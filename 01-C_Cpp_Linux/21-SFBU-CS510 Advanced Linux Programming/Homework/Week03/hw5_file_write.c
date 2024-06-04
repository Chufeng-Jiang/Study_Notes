#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 


void main()
{
int sz;
int fd = open("hw5_foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

printf("fd = %d\n", fd);
if (fd < 0)
{
    perror("r1");
    exit(1);
}

sz = write(fd, "hello geeks", strlen("hello geeks"));
printf("Called write(%d, \"hello geeks\", strlen(\"hello geeks\") = %ld); ===> It returned %d bytes.\n", fd, strlen("hello geeks"), sz);


printf("\n\n====Does of \"\\n\" counts towards the length of the string? ====\n");
sz = write(fd, "hello geeks\n", strlen("hello geeks\n"));
printf("Called write(%d, \"hello geeks\\n\", strlen(\"hello geeks\\n\") = %ld); ===> It returned %d bytes.\n", fd, strlen("hello geeks\n"), sz);


printf("\n\n====Does of \"\\0\" counts towards the length of the string? ====\n");
sz = write(fd, "hello geeks\0", strlen("hello geeks\0"));
printf("Called write(%d, \"hello geeks\\0\", strlen(\"hello geeks\\0\") = %ld); ===> It returned %d bytes.\n", fd, strlen("hello geeks\0"), sz);


close(fd);
}
