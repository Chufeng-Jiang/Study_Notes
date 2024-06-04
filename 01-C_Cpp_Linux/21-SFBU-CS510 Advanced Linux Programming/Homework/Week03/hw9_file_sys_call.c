#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char c[10], ch;
	off_t position1, position2;

	printf("==Read 1 byte for fd1 and fd2==\n");
    int fd1 = open("hw9_sample.txt", O_RDONLY, 0);
    int fd2 = open("hw9_sample.txt", O_RDONLY, 0);

    read(fd1, &c, 1);
	printf("fd1: c = %s\n", c);
	position1 = lseek(fd1, 0, SEEK_CUR);
	if (position1 == -1) {
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	printf("fd1: current position1: %ld\n\n", (long)position1);


    read(fd2, &c, 1);
	printf("fd2: c = %s\n", c);
	position2 = lseek(fd2, 0, SEEK_CUR);
	if (position2 == -1) {
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	printf("fd2: current position2: %ld\n\n", (long)position2);

	ch = getchar();

     printf("==Read 1 more byte for fd1, not fd2==\n");
	read(fd1, &c, 1);
	printf("fd1: c = %s\n", c);
	position1 = lseek(fd1, 0, SEEK_CUR);
	if (position1 == -1) {
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	printf("fd1: current position1: %ld\n", (long)position1);
	printf("fd2: current position2: %ld\n", (long)position2);

	close(fd1);
	close(fd2);
    exit(0);
}
