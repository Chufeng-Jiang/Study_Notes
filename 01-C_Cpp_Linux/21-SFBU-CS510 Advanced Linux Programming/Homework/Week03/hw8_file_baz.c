#include<stdio.h> 
#include<fcntl.h> 
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char ch;

	printf("-------open hw8_foo.txt------\n");
    // assume that foo.txt is already created 
    int fd1 = open("hw8_foo.txt", O_RDONLY, 0);
	printf("fd1 = %d\n", fd1);

	while ((read(fd1, &ch, 1)) != 0) {
        putchar(ch);
    }

	ch = getchar();

    close(fd1);
	printf("-------fd1 closed------\n\n");

	ch = getchar();

	printf("-------open hw8_baz.txt------\n");
	// assume that baz.tzt is already created 
    int fd2 = open("hw8_baz.txt", O_RDONLY, 0);
    printf("fd2 = %d\n", fd2);
	while ((read(fd2, &ch, 1)) != 0) {
        putchar(ch);
    }

	ch = getchar();
    close(fd2);

	printf("-------fd2 closed------\n\n");
	
	ch = getchar();
    exit(0);
}
