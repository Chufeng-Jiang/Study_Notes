//服务端程序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>

int main()
{
	//创建socket
	//int socket(int domain, int type, int protocol); 
	//AF_INET--ipv4，SOCK_STREAM --tcp
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	if(lfd<0)
	{
		perror("socket error");
		return -1;
	}
	
	//int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	//绑定，服务端必须绑定，但是客户端不用必须绑定，客户端内核随机分配端口
	struct sockaddr_in serv; //定义参数二，后面要强制转换(struct sockaddr *)&serv
	
	bzero(&serv, sizeof(serv)); // man 7 ip
	serv.sin_family = AF_INET; // 定义结构体内的变量
	serv.sin_port = htons(8888); // 主机字节序转网络字节序，使用1024以后的数字，自定义端口8888
	serv.sin_addr.s_addr = htonl(INADDR_ANY); //表示使用本地任意可用IP
	
	int ret = bind(lfd, (struct sockaddr *)&serv, sizeof(serv));
	if(ret<0)
	{
		perror("bind error");	
		return -1;
	}

	//监听
	//int listen(int sockfd, int backlog);
	listen(lfd, 128); // man 2 listen，最大值是128

	//int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	struct sockaddr_in client;//获取客户端的参数
	socklen_t len = sizeof(client);
	
	//int cfd = accept(lfd, NULL, NULL);  
	//有参数的可以设置黑名单
	int cfd = accept(lfd, (struct sockaddr *)&client, &len);  //len是一个输入输出参数

	
	//获取client端的IP和端口
	char sIP[16];
	memset(sIP, 0x00, sizeof(sIP));
    //const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
	printf("client-->IP:[%s],PORT:[%d]\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, sIP, sizeof(sIP)), ntohs(client.sin_port));
	printf("lfd==[%d], cfd==[%d]\n", lfd, cfd);

	int i = 0;
	int n = 0;
	char buf[1024];

	while(1)
	{
		//读数据
		memset(buf, 0x00, sizeof(buf));
		n = read(cfd, buf, sizeof(buf)); //阻塞函数
		if(n<=0) // 读失败或者对方关闭链接
		{
			printf("read error or client close, n==[%d]\n", n);
			break;
		}
		printf("n==[%d], buf==[%s]\n", n, buf);	

		for(i=0; i<n; i++) //大小写转换
		{
			buf[i] = toupper(buf[i]);
		}

		//发送数据
		write(cfd, buf, n);
	}

	//关闭监听文件描述符和通信文件描述符
	close(lfd);
	close(cfd);
	
	return 0;
}

