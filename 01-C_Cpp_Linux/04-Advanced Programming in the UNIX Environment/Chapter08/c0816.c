#include "apue.h"
#include <sys/wait.h>

//#define APUE_DIR "/home/beza/CS510-APUE/Chapter08"

char* env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)  /* specify pathname, specify environment */
    {
        if (execle("/home/beza/CS510-APUE/Chapter08/c0817", "c0817", "myarg1", "MY ARG2", (char*)0, env_init) < 0)
        {
            err_sys("execle error");
        }
    }

    if (waitpid(pid, NULL, 0) < 0)
    {
        err_sys("wait error");
    }

    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)  /* specify filename, inherit environment */
    {
        if (execlp("/home/beza/CS510-APUE/Chapter08/c0817", "c0817", "only 1 arg", (char*)0) < 0)
        {
            err_sys("execlp error");
        }
    }

    exit(0);
}
