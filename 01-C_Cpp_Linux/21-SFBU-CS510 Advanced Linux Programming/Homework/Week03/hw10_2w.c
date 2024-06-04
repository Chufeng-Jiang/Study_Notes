#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> 

int main(void)
{
    int fd[2];
    char buf1[12] = "hello world";
    char buf2[12];
    off_t cursorPos1;
    off_t cursorPos2;
	FILE *file;
    char character;

    // assume foo1.txt and sample.txt are already created
    fd[0] = open("hw10_foo.txt", O_RDWR);
    fd[1] = open("hw10_sample.txt", O_RDWR);

    if (fd[0] == -1 || fd[1] == -1) {
        perror("Error opening files");
        exit(1);
    }

    // Writing the content in bu1 to file fd[0]
    write(fd[0], buf1, strlen(buf1));

    printf("\nAfter 1st write buf1: %s", buf1);
	printf("\nAfter 1st write buf2: %s", buf2);

    cursorPos1 = lseek(fd[0], 0, SEEK_CUR);
    if (cursorPos1 == -1) {
        perror("Error getting cursor position");
        close(fd[0]);
        close(fd[1]);
        exit(1);
    }

    // Print the fd[0] position
    printf("\nfd[0]: Current cursor1 position: %ld\n", (long)cursorPos1);

    cursorPos2 = lseek(fd[1], 0, SEEK_CUR);
    if (cursorPos2 == -1) {
        perror("Error getting cursor position");
        close(fd[0]);
        close(fd[1]);
        exit(1);
    }
    // Print the fd[1] position
    printf("fd[1]: Current cursor2 position: %ld\n", (long)cursorPos2);

	printf("\n==========1. Print File content in fd[0]=============\n");
	// open the file in read mode
    file = fopen("hw10_foo.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // suspend the program
    while ((character = fgetc(file)) != EOF) {
        printf("%c", character);
    }

    // Close the file
    fclose(file);

    printf("\n\n\n===2. write(1, buf2, read(fd[1], buf2, 12))====\n");
	printf("---2.1. read(fd[1], buf2, 12): read 12 bytes from fd[1] and write to buf2---\n");

    // reading from file fd[0] and writing to stdout (fd=1)
	//write(1, buf2, read(fd[1], buf2, 12));
	read(fd[1], buf2, 12);
    printf("\nbuf1: %s", buf1);
    printf("\nbuf2: %s", buf2);

    cursorPos1 = lseek(fd[0], 0, SEEK_CUR);
    if (cursorPos1 == -1) {
        perror("Error getting cursor position");
        close(fd[0]);
        close(fd[1]);
        exit(1);
    }

    // Print the current cursor position
    printf("\nfd[0]: current cursor1 position: %ld\n", (long)cursorPos1);

    cursorPos2 = lseek(fd[1], 0, SEEK_CUR);
    if (cursorPos2 == -1) {
        perror("Error getting cursor position");
        close(fd[0]);
        close(fd[1]);
        exit(1);
    }

    // Print the current cursor position
    printf("fd[1]: current cursor2 position: %ld\n", (long)cursorPos2);
	
	printf("\n---2.2. write(1, buf2, strlen(buf2)): write %ld bytes from buf2 to STDOUT---\n", strlen(buf2));

    write(1, buf2, strlen(buf2) );

    printf("\nbuf1: %s", buf1);
    printf("\nbuf2: %s", buf2);

    cursorPos1 = lseek(fd[0], 0, SEEK_CUR);
    if (cursorPos1 == -1) {
        perror("Error getting cursor position");
        close(fd[0]);
        close(fd[1]);
        exit(1);
    }

    // Print the current cursor position
    printf("\nCurrent cursor1 position: %ld\n", (long)cursorPos1);

    cursorPos2 = lseek(fd[1], 0, SEEK_CUR);
    if (cursorPos2 == -1) {
        perror("Error getting cursor position");
        close(fd[0]);
        close(fd[1]);
        exit(1);
    }

    // Print the current cursor position
    printf("Current cursor2 position: %ld\n", (long)cursorPos2);

	printf("\n\n\n===3. write(1, buf2, read(fd[0], buf2, 12))====\n");
	printf("---3.1. read(fd[0], buf2, 12): read 12 bytes from fd[0] and write to buf2---\n");

    // reading from file fd[0] and writing to stdout (fd=1)
	//write(1, buf2, read(fd[1], buf2, 12));
	read(fd[0], buf2, 12);
    printf("\nbuf1: %s", buf1);
    printf("\nbuf2: %s", buf2);

    cursorPos1 = lseek(fd[0], 0, SEEK_CUR);
    if (cursorPos1 == -1) {
        perror("Error getting cursor position");
        close(fd[0]);
        close(fd[1]);
        exit(1);
    }

    // Print the current cursor position
    printf("\nfd[0]: current cursor1 position: %ld\n", (long)cursorPos1);

    cursorPos2 = lseek(fd[1], 0, SEEK_CUR);
    if (cursorPos2 == -1) {
        perror("Error getting cursor position");
        close(fd[0]);
        close(fd[1]);
        exit(1);
    }

    // Print the current cursor position
    printf("fd[1]: current cursor2 position: %ld\n", (long)cursorPos2);
	
	printf("\n---3.2. write(1, buf2, strlen(buf2)): write %ld bytes from buf2 to STDOUT---\n", strlen(buf2));

    write(1, buf2, strlen(buf2) );

    printf("\nbuf1: %s", buf1);
    printf("\nbuf2: %s", buf2);

    cursorPos1 = lseek(fd[0], 0, SEEK_CUR);
    if (cursorPos1 == -1) {
        perror("Error getting cursor position");
        close(fd[0]);
        close(fd[1]);
        exit(1);
    }

    // Print the current cursor position
    printf("\nCurrent cursor1 position: %ld\n", (long)cursorPos1);

    cursorPos2 = lseek(fd[1], 0, SEEK_CUR);
    if (cursorPos2 == -1) {
        perror("Error getting cursor position");
        close(fd[0]);
        close(fd[1]);
        exit(1);
    }

    // Print the current cursor position
    printf("Current cursor2 position: %ld\n", (long)cursorPos2);

    close(fd[0]);
    close(fd[1]);

    return 0;
}
