// C program to illustrate close system Call
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
// open a pre-existing file using read only mode.
    int fd1 = open("hw6_foo.txt", O_RDONLY);
    if (fd1 < 0) {
        perror("c1");
        exit(1);
    }
// print the file descriptor's vale
    printf("opened the fd = % d\n", fd1);

	int c  = getc(stdin);

// close and release the file descriptor, if not close sucessfully, print c1, otherwise print "closed the fd."

	if (close(fd1) < 0) {
        perror("c1");
        exit(1);
    }

    printf("closed the fd.\n");
	exit(0);
}
