//循环创建n个子进程
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int i = 0;
	for(i=0; i<3; i++)
	{
		//创建子进程
		pid_t pid = fork();
		if(pid<0) //fork失败的情况
		{
			perror("fork error");
			return -1;
		}
		else if(pid>0)//父进程
		{
			printf("father: pid==[%d], fpid==[%d]\n", getpid(),getppid());
			//sleep(1);
		}
		else if(pid==0) //子进程
		{
			printf("child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
			break; // 加了这句话以后子进程不再fork孙进程，保证了每次fork只多一个进程
		}
	}

	//fork出来的子进程继续执行，父进程返回继续循环至结束再往下执行	
	//第1个子进程
	if(i==0)
	{
		printf("[%d]--[%d]: child\n", i, getpid());	
	}

	//第2个子进程
	if(i==1)
	{
		printf("[%d]--[%d]: child\n", i, getpid());	
	}
	//第3个子进程
	if(i==2)
	{
		printf("[%d]--[%d]: child\n", i, getpid());	
	}
	//父进程
	if(i==3)
	{
		printf("[%d]--[%d]: child\n", i, getpid());	
	}
	sleep(20);

	return 0;
}
