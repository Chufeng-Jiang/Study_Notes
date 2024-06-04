//编写libevent服务端
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <event2/event.h>
#include <errno.h>

struct event *readev = NULL;
//通信文件描述符对应的事件的回调函数
void readcb(evutil_socket_t cfd, short events, void *arg)
{
	int n;
	char buf[1024];
	
	memset(buf, 0x00, sizeof(buf));
	n = read(cfd, buf, sizeof(buf));
	if(n<=0)
	{
		printf("read error or client closed, n==[%d]\n", n);
		
		//关闭cfd
		close(cfd);
		
		//将cfd对应的事件从base下删除
		event_del(readev);
		
		//释放event节点
		event_free(readev);
	}
	write(cfd, buf, n);
}
//typedef void (*event_callback_fn)(evutil_socket_t fd, 
//			short events, void *arg);
//监听文件描述符对应的回调函数
void conncb(evutil_socket_t lfd, short events, void *arg)
{
	struct event_base *base = (struct event_base *)arg;
	
	//接受新的客户端连接
	int cfd = accept(lfd, NULL, NULL);
	if(cfd>0)
	{
		//创建cfd对应的事件节点
		readev = event_new(base, cfd, EV_READ|EV_PERSIST, readcb, NULL);
		
		if(readev == NULL)
			{
				//退出循环
				event_base_loopexit(base, NULL);
			}
		
		//将cfd对应的事件节点上base
		event_add(readev, NULL);
	}
}

int main()
{
	//创建socket
	int fd = socket(AF_INET, SOCK_STREAM, 0);

	//设置端口复用
	int opt = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	//绑定
	struct sockaddr_in serv;
	bzero(&serv, sizeof(serv));
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	serv.sin_port = htons(8888);
	serv.sin_family = AF_INET;
	bind(fd, (struct sockaddr*)&serv, sizeof(serv));

	//监听
	listen(fd, 120);
	
	//创建地基节点
	struct event_base *base = event_base_new();
	if(base==NULL)
	{
		return -1;
	}
	
	//创建监听文件描述符对应的事件节点
	//struct event *event_new(struct event_base *base, evutil_socket_t fd, 
	  //short events, event_callback_fn cb, void *arg);
	struct event *event = event_new(base, fd, EV_READ | EV_PERSIST, conncb, base);
	if(event==NULL)
	{
		event_base_free(base);
		return -1;
	}
	event_add(event, NULL);
	
	//进入循环
	event_base_dispatch(base);
	
	//释放地基节点
	event_base_free(base);
	event_free(event);
	
	close(fd);
	
	return 0;
}
