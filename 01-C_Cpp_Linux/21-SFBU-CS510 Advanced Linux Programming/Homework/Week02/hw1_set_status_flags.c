#include "apue.h"
#include <fcntl.h>

#define    BUFFSIZE    8
void
set_fl(int fd, int flags) /* flags are file status flags to turn on */
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fcntl F_GETFL error");

    val |= flags;       /* turn on flags */

    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}

void
clr_fl(int fd, int flags) /* flags are file status flags to turn on */
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fcntl F_GETFL error");

    val &= ~flags;       /* turn on flags */

    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}



int main() {
    int fd;
    
	// open the "test_file_for_set.txt",or creat it if it dosen't exist.
	// if successfully, we'll get the file descriptor.
    if ((fd = open("test_file_for_set.txt", O_CREAT | O_WRONLY , 0644)) < 0) {
        err_sys("open error");
    }
    
    // using the fd, which points to the "test_file_for_set.txt" file,
	// write the "Hello, World!" into the file
    if (write(fd, "Hello, World!", 14) != 14) {
        err_sys("write error");
    }
    
	
    // close the fd, and all the content will be saved automatically.
    if (close(fd) < 0) {
        err_sys("close error");
    }
	
	// we re-open the "test_file_for_set.txt", and get the fd again.
	if ((fd = open("test_file_for_set.txt", O_CREAT | O_WRONLY , 0644)) < 0) {
        err_sys("open error");
    }
	
	// we set the status flag for fd as O_APPEND
	// it means what we write into the file will be append to the end
	// rather than overwrite from the beginning
	// if this line is commented, what we write will be overwrite the content from the beginning of the file without offset.
	set_fl(fd, O_APPEND);
    
	// we write "+append\n" into the content
	if (write(fd, "+append\n", 8) != 8) {
        err_sys("write error");
    }
	
    // close the fd again, and the new content will be saved automatically.
    if (close(fd) < 0) {
        err_sys("close error");
    }
	
	
    printf("Test case: test_file_for_set.txt ====> Over.\n");
    
    return 0;
}