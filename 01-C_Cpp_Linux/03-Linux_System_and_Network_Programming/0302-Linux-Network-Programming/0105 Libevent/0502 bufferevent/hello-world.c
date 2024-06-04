/*
  This exmple program provides a trivial server program that listens for TCP
  connections on port 9995.  When they arrive, it writes a short message to
  each client connection, and closes each connection once it is flushed.

  Where possible, it exits cleanly in response to a SIGINT (ctrl-c).
*/


#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#ifndef WIN32
#include <netinet/in.h>
# ifdef _XOPEN_SOURCE_EXTENDED
#  include <arpa/inet.h>
# endif
#include <sys/socket.h>
#endif

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>

static const char MESSAGE[] = "Hello, World!\n";

static const int PORT = 9995;

static void listener_cb(struct evconnlistener *, evutil_socket_t,
    struct sockaddr *, int socklen, void *);
static void conn_writecb(struct bufferevent *, void *);
static void conn_eventcb(struct bufferevent *, short, void *);
static void signal_cb(evutil_socket_t, short, void *);

int
main(int argc, char **argv)
{
	struct event_base *base;    //定义了指向地基节点的指针
	struct evconnlistener *listener;  //定义了链接监听器的指针
	struct event *signal_event;  //定义了信号事件指针

	struct sockaddr_in sin;
#ifdef WIN32
	WSADATA wsa_data;
	WSAStartup(0x0201, &wsa_data);
#endif

	//创建地基节点--相当于epoll的树根
	base = event_base_new();
	if (!base) {
		fprintf(stderr, "Could not initialize libevent!\n");
		return 1;
	}

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORT);

	//创建链接监听器--socket bind  listen  accept
	//listener_cb--回调函数
	//LEV_OPT_REUSEABLE|LEV_OPT_CLOSE_ON_FREE: 端口复用|释放连接监听器的时候关闭文件描述符
	listener = evconnlistener_new_bind(base, listener_cb, (void *)base,
	    LEV_OPT_REUSEABLE|LEV_OPT_CLOSE_ON_FREE, -1,
	    (struct sockaddr*)&sin,
	    sizeof(sin));

	if (!listener) {
		fprintf(stderr, "Could not create a listener!\n");
		return 1;
	}

	//#define evsignal_new(b, x, cb, arg)				\
	//event_new((b), (x), EV_SIGNAL|EV_PERSIST, (cb), (arg))
	signal_event = evsignal_new(base, SIGINT, signal_cb, (void *)base);

	if (!signal_event || event_add(signal_event, NULL)<0) {
		fprintf(stderr, "Could not create/add a signal event!\n");
		return 1;
	}

	//进入事件循环---相当于while(1)
	event_base_dispatch(base);

	//释放连接监听器
	evconnlistener_free(listener);
	//释放信号事件节点
	event_free(signal_event);
	//释放地基节点
	event_base_free(base);

	printf("done\n");
	return 0;
}

//listener: 链接监听器指针
//fd: 通信文件描述符
//sa和socklen: 客户端地址信息和长度
//user_data: 具体是地基节点指针
static void
listener_cb(struct evconnlistener *listener, evutil_socket_t fd,
    struct sockaddr *sa, int socklen, void *user_data)
{
	printf("--call--%s--\n", __FUNCTION__);

	struct event_base *base = user_data;
	struct bufferevent *bev;//指向bufferevent的指针

	//创建bufferevent
	//BEV_OPT_CLOSE_ON_FREE: 当释放bufferevent的时候关闭连接
	bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
	if (!bev) {
		fprintf(stderr, "Error constructing bufferevent!");
		event_base_loopbreak(base);
		return;
	}
	//设置回调函数---写事件和异常事件回调函数
	bufferevent_setcb(bev, NULL, conn_writecb, conn_eventcb, NULL);
	//使写事件回调生效
	bufferevent_enable(bev, EV_WRITE);
	//使读事件回调失效
	bufferevent_disable(bev, EV_READ);

	//将数据写到bufferevent的写缓冲区
	bufferevent_write(bev, MESSAGE, strlen(MESSAGE));
}

static void
conn_writecb(struct bufferevent *bev, void *user_data)
{
	printf("--call--%s--\n", __FUNCTION__);

	//获取bufferevent的写缓冲区的指针
	struct evbuffer *output = bufferevent_get_output(bev);
	//查看缓冲区还有没有数据
	if (evbuffer_get_length(output) == 0) {
		printf("flushed answer\n");
		//释放bufferevent,关闭通信文件 描述符
		bufferevent_free(bev);
	}
}

static void
conn_eventcb(struct bufferevent *bev, short events, void *user_data)
{
	printf("--call--%s--\n", __FUNCTION__);

	if (events & BEV_EVENT_EOF) {
		printf("Connection closed.\n");
	} else if (events & BEV_EVENT_ERROR) {
		printf("Got an error on the connection: %s\n",
		    strerror(errno));/*XXX win32*/
	}
	/* None of the other events can happen here, since we haven't enabled
	 * timeouts */
	bufferevent_free(bev);
}

static void
signal_cb(evutil_socket_t sig, short events, void *user_data)
{
	printf("--call--%s--\n", __FUNCTION__);

	struct event_base *base = user_data;
	struct timeval delay = { 2, 0 };

	printf("Caught an interrupt signal; exiting cleanly in two seconds.\n");

	//事件回调函数执行完后, 再过2秒, 跳出循环, 程序结束
	event_base_loopexit(base, &delay);
}
