#include "apue.h"  // User Defined Header File
#include <stdio.h> //Standard Header File 

int main(void)
{
    // If the file is not seekable, print "cannot seek".
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) 
        printf("cannot seek\n");
	// If the file is seekable, print "seek OK".
    else
        printf("seek OK\n");
	
	exit(0); 
 }
