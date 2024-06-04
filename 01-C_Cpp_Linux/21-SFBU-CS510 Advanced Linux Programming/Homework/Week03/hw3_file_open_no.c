#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>



#define MAX_RESULT_LENGTH 1000

extern int errno;

int main()
{
	struct stat file_stat;
	int fd1, fd2, fd3;
	const char *command;
	FILE *fp;
	char cmd_result[MAX_RESULT_LENGTH];

    fd1 = open("hw3_foo_no.txt", O_RDONLY | O_CREAT);

	printf("------Testing O_CREAT Mode WITHOUT Permission Bit------\n");
    printf("Creating File: hw3_foo_no.txt ==> fd = %d\n", fd1);

    if (fd1 == -1) {
        // print which type of error have in a code
        printf("Error Number % d\n", errno);

        // print program detail "Success or failure"
        perror("Program");
    }

	if (fstat(fd1, &file_stat) == -1) {
        perror("Error in fstat");
        close(fd1);
        return 1;
    }

	printf("Creating File: hw3_foo_no.txt, Permission Bits: %o\n", file_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
    


	fd2 = open("hw3_foo_0444.txt", O_RDONLY | O_CREAT, 0444);
	printf("\n------Testing O_CREAT Mode with 0444------\n");
    printf("Creating File with 0444: hw3_foo_0444.txt ==> fd = %d\n", fd2);

	if (fd2 == -1) {
	printf("Error Number % d\n", errno);
	perror("Program");
	}

	
    if (fstat(fd2, &file_stat) == -1) {
        perror("Error in fstat");
        close(fd2);
        return 1;
    }

	printf("Creating File: hw3_foo_0444.txt, Permission Bits: %o\n", file_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
	
	printf("\n------Testing O_CREAT Mode with existing file------\n");

    fd3 = open("hw3_existed_foo.txt", O_RDONLY | O_CREAT);
    printf("Open Existed File: hw3_foo_existed.txt ==> fd = %d\n", fd3);

	if (fd3 == -1) {
	printf("Error Number % d\n", errno);
	perror("Program");
	}

	
    if (fstat(fd3, &file_stat) == -1) {
        perror("Error in fstat");
        close(fd3);
        return 1;
    }

	printf("File: hw3_foo_existed.txt, Permission Bits: %o\n", file_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));

	printf("\n\n========================================\n");
// 定义要执行的命令
    command = "ls -l hw3*.txt";

    printf("Executing command $: %s\n", command);

	fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to execute the command.\n");
        return 1;
    }

    // 读取命令输出
    while (fgets(cmd_result, sizeof(cmd_result), fp) != NULL) {
        // 打印每一行命令输出结果
        printf("%s", cmd_result);
    }

    // 关闭命令的输出文件流
    pclose(fp);
	close(fd1);
	close(fd2);
	close(fd3);
    return 0;
}
