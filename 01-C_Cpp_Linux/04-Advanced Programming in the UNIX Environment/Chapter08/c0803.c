#include "apue.h"

int globvar = 6;  /* external variable in initialized data */

int main(int argc, char* argv[])
{
    int var;  /* automatic variable on the stack */
    pid_t pid;

    var = 88;
    printf("before vfork: pid = %ld, glob = %d, var = %d\n\n",(long)getpid(), globvar, var);  /* we don't flush stdio */
    if ((pid = vfork()) < 0)
    {
        err_sys("vfork error");
    }
    else if (pid == 0)  /* child */
    {
        ++globvar;  /* modify parent's variables */
        ++var;
		printf("After vfork ---> Child :pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
		// 在调用exit之前，在父进程的空间中运行，所以共享数据
        _exit(0);  /* child terminates */
    }
    /* parent continues here */
    printf("After vfork ---> Parent :pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    exit(0);
}
