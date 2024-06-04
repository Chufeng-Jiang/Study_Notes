#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <flags>\n", argv[0]);
        return 1;
    }

    int fd;
    if ((fd = open(argv[1], O_RDWR)) < 0) {
        perror("open error");
        return 1;
    }

    int flags = atoi(argv[2]); // assuming flags is passed as an integer string

    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        printf("fcntl F_GETFL error\n");
    val |= flags;       /* turn on flags */
    if (fcntl(fd, F_SETFL, val) < 0)
        printf("fcntl F_SETFL error\n");
    
    close(fd);
    return 0;
}

