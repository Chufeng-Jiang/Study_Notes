#include <unistd.h>
#include <string.h>
#include<stdio.h>
#define SIZE 32
int main(void) {
        pid_t pid;
        char buf[SIZE];
        pid = fork();
        if (pid == -1) {
                printf("Fork failed\n");
                return(1);
        }
        /* Parent process */
        if (pid > 0) return(0);
        /* Child process: Continues and becomes the server process running forever as a daemon */

        (void) sprintf(buf, "Daemon PID: %d\n", getpid());
        (void) write(1,buf,strlen(buf));
        while(1) {
                /* Wait for a client request */
                /* Serve the client request */
                sleep(10);  /* Dummy code */
        }
}
