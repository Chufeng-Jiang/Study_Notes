#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/signal.h>
#define SIZE 12
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
        /* Child process: Continues and becomes the server */
        /* process running forver as a daemon */
        /* Ignore signals */
        signal(SIGHUP, SIG_IGN);
        signal(SIGINT, SIG_IGN);

        /* Set umask */
        (void) umask(027);

        /* Display Daemon's PID */
        (void) sprintf(buf, "Daemon PID: %d\n", getpid());
        (void) write(1, buf, strlen(buf));

        /* Code for the server */
        while(1) {
                /* Wait for a client request */
           /* Serve the client request */
                sleep(10); /* Dummy code */
        }
}
