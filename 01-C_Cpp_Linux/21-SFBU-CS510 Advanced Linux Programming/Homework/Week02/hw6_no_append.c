#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
{
        int ret=0;
        int fd=-1;
        struct stat sb;
		
		// open or create a file using append mode.
        fd = open("hw6_no_append.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
        if(fd==-1) perror("open() error:");

		// set the cursor to the end of the file and get the file size
        ret = lseek(fd,0,SEEK_END);		
        if(ret==-1) perror("lseek() seek-end error:");

        printf("Before lseek(fd,0,SEEK_END); File Size=%d\n\n",ret);
        
		// set the cursor to the 100 byte position from the begining.
		printf("Begin lseek(fd,100,SEEK_SET)>>>>>>>>\n");
		ret=lseek(fd,100,SEEK_SET);//set offset of file with lseek()
        if(ret==-1) perror(">>>>>>>lseek(fd,100,SEEK_SET) error():");
		
        
		// get the cursor's current position
		ret=lseek(fd,0,SEEK_CUR);
        if(ret==-1) perror("lseek() current cursor error:");
		
        printf("After lseek(fd,100,SEEK_SET), Current Cursor Posiont = %d\n",ret);
		printf("End SEEK_SET\n\n");
		
		// write 4 byte data into the file
		printf("Begin write 4 byte data into file>>>>>>>>\n");
        ret=write(fd,"xxxx",4);
        if(ret==-1) perror("write() error:");

		// get the updated cursor's current position
        ret=lseek(fd,0,SEEK_CUR);
        if(ret==-1) perror("lseek() updated current cursor error:");
        printf("After write 4 byte data, Current Cursor Position = %d\n\n",ret);
		
		// set the cursor to the 70 byte position from the begining.
		printf("Begin lseek(fd,70,SEEK_SET)>>>>>>>>\n");
		ret=lseek(fd,70,SEEK_SET);//set offset of file with lseek()
        if(ret==-1) perror(">>>>>>>lseek(fd,70,SEEK_SET) error():");
		
        
		// get the cursor's current position
		ret=lseek(fd,0,SEEK_CUR);
        if(ret==-1) perror("lseek() current cursor error:");
		
        printf("After lseek(fd,70,SEEK_SET), Current Cursor Position = %d\n",ret);
		printf("End SEEK_SET\n\n");
		
		// append 8 byte data into the file
		printf("Begin write 8 byte data into file>>>>>>>>\n");
        ret=write(fd,"12345678",8);
        if(ret==-1) perror("write() error:");

		// get the updated cursor's current position
        ret=lseek(fd,0,SEEK_CUR);
        if(ret==-1) perror("lseek() updated current cursor error:");
        printf("After write 4+8 byte data, Current Cursor Position = %d\n",ret);
		
        printf("End Write Data\n");
		
        ret=fstat(fd,&sb);
        if(ret==-1) perror("fstat error:");
        printf("\nFinally, File Size = %ld\n",sb.st_size);//filesize == 1;
 
        close(fd);
 
		return 0;
}