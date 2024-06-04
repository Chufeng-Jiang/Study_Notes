#include "apue.h"
#include <fcntl.h>

int main(int fd, int flags) /* flags are file status flags to turn on */
       {
           int val;
           if ((val = fcntl(fd, F_GETFL, 0)) < 0)
               printf("fcntl F_GETFL error\n");
           val |= flags;       /* turn on flags */
           if (fcntl(fd, F_SETFL, val) < 0)
               printf("fcntl F_SETFL error\n");
           return 0;
}
