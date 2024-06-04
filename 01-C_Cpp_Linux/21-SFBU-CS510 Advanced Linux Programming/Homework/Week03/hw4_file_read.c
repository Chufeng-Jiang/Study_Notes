// C program to illustrate
// read system Call
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 

int main() {
// declare file descriptor and size variables
    int fd, sz;
    
// allocate memory for 100 characters and initialize to 0
    char* c = (char*) calloc(100, sizeof(char));

// open the file "hw4_foo.txt" in read-only mode
    fd = open("hw4_foo.txt", O_RDONLY);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }

// Obtain and print the current offset before reading
    off_t offset_before = lseek(fd, 0, SEEK_CUR);
    printf("Before sz = read(fd, c, 13) : current file offset: %ld\n", (long) offset_before);

// Read up to 13 bytes from the file into the buffer c
    sz = read(fd, c, 13);

// Obtain and print the current offset after reading
    off_t offset_after = lseek(fd, 0, SEEK_CUR);
    printf("After sz = read(fd, c, 13) : current file offset: %ld\n\n", (long) offset_after);


// print the number of bytes read from the file
    printf("Called read(%d, c, 13). returned that %d bytes were read.\n\n", fd, sz);
	printf("Before set c[sz] = \'p\' ===>c[sz] = [%c]\n", c[sz]);
    printf("Before set c[sz] = \'p\' ===>Those bytes in buffer c : %s, the length is: %ld\n", c, strlen(c));

// set the character at position sz in buffer c to 'p'
    c[sz] = 'p';
    printf(" After set c[sz] = \'p\' ===>Those bytes in buffer c : %s, the length is: %ld\n\n", c, strlen(c));

// null-terminate the string read from the file at position sz - 2
    c[sz - 2] = '\0';

    printf("After set c[sz - 2] = \'\\0\' ===>Those bytes in buffer c : %s, the length is: %ld\n\n ", c, strlen(c));

// free allocated memory and close file descriptor
    free(c);
    close(fd);
    return 0;
}
