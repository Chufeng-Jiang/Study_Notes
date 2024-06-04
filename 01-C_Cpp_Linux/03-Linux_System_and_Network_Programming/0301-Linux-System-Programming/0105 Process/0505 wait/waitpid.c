//父进程调用waitpid函数完成对子进程的回收
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
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
		printf("father: [%d], pid==[%d], fpid==[%d]\n", pid, getpid(),getppid());
		int status;

		while(1) //循环回收，直到子进程2秒耗尽被回收，父进程进入100秒sleep状态
		{
			//pid_t wpid = waitpid(pid, &status, 0); //和wait函数一模一样
			pid_t wpid = waitpid(-1, &status, WNOHANG); //-1表示等待任意子进程,WNOHANG表示不阻塞
			printf("wpid==[%d]\n", wpid);
			if(wpid > 0)
			{
				if(WIFEXITED(status)) //正常退出
				{
					printf("child normal exit, status==[%d]\n", WEXITSTATUS(status));
				}
				else if(WIFSIGNALED(status)) //被信号杀死
				{
					printf("child killed by signal, signo==[%d]\n", WTERMSIG(status));
				}
			}
			else if(wpid == 0) //子进程还活着
			{
				printf("child is living, wpid==[%d]\n", wpid);
			}
			else if(wpid==-1) //没有子进程了
			{
				printf("no child is living, wpid==[%d]\n", wpid);
				break;
			}
		}
		sleep(100); //如果只回收一次的话，子进程2秒耗尽，父进程还在sleep-100秒，此时子进程变成僵尸进程，所以需要增加while循环语句对子进程循环回收。

	}
	else if(pid==0) //子进程
	{

		printf("child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
		sleep(2);
		return 9;
	}

	return 0;
}
