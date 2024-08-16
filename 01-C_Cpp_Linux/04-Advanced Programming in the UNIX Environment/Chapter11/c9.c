#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
#include <sys/file.h>
#include <sys/signal.h>
#include<string.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define SIZE 32
#define LOCKMODE (S_IRUSR | S_IWUSR | S_IWGRP | S_IROTH) 
#ifdef __sun
#define LOCKFILE "/home/beza/CS510-APUE/Chapter11/c9testd.lock" 
#else
#define LOCKFILE "/home/beza/CS510-APUE/Chapter11/c9testd.lock" 
#endif

void zombie_gatherer(int);
int main(void) {
        int fd, lockfd;
        pid_t pid, sid;
        char buf[SIZE];
        struct flock lock;

        pid = fork();
        if (pid == -1) {
                printf("Fork failed\n");
                return(1);
        }
        /* Parent process */
        if (pid > 0) return(0);

        /* Child process: Continues and becomes the server process running forever as a daemon */
/* Ignore signals */

        signal(SIGHUP, SIG_IGN);
        signal(SIGINT, SIG_IGN);

        /* Intercept SIGCHLD and cleanup the terminating chid/children */
        signal(SIGCHLD, zombie_gatherer);

        /* Set umask */
        (void) umask(027);

        /* Allow only a single copy of the daemon */
        /* Open (or create) LOCKFILE */

        lockfd = open(LOCKFILE, O_RDWR | O_CREAT, LOCKMODE);
        if (lockfd == -1) {
                printf("open failed to create LOCKFILE");
                return(1);
        }
#ifdef __sun
        /* Set lock */
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;

/* Lock LOCKFILE for mutually exclusive access */
        if (fcntl(lockfd, F_SETLK, &lock)) {
                printf("Daemon already running");
                close(lockd);
                return(1);
        }
#else
        /* Lock LOCKFILE for mutually exclusive access */
        if (flock(lockfd, LOCK_EX | LOCK_NB)) {
                printf("Daemon already running");
                close(lockfd);
                        return(1);
        }
#endif
        /* Save daemon PID in the lock file */
        (void) sprintf(buf, "tested PID: %d\n", getpid());
        (void) write(lockfd, buf, strlen(buf));

        /* Detach terminal from the daemon */
        if((sid = setsid()) == -1) {
                printf("setsid failed");
                return(1);
        }
        /* Change working directory */
        if((chdir("/")) == -1) {
                printf("chdir failed");
                return(1);
        }
        /* Close inherited standard desciptors */
        for(fd = 2; fd >= 0; fd--) {
        if(close(fd) == -1) {
                printf("close failed");
                return(1);
        }
        /* Open standard descriptors */
        if ((fd = open("/dev/null", O_RDWR)) == -1) {
                printf("Open failed");
	return(1);
}
(void) dup(fd);
        (void) dup(fd);

        /* Main server loop */
        while(1) {
                /* Wait for a client request */
                /* Serve the client request */
                sleep(10); /* Dummy code */
        }
        }
}
        void zombie_gatherer(int signal) {
                int status;
                while(wait3(&status, WNOHANG, 0) >= 0) ;
        }
