#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
int main()
{  
    
	// 1. 打开共享内存
	int shmid = shmget(100, 0, 0);
    if(shmid == -1)
    {  
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }   
	// 2. 将共享内存连接到当前进程的地址空间
	void * ptr = shmat(shmid, NULL, 0);
	
	// 3. 读共享内存
	printf("%s\n", (char*)ptr);

	printf("按任意键继续...");
	getchar();
	
	// 4. 解除关联
	shmdt(ptr);
	
	// 5. 删除共享内存
	shmctl(shmid, IPC_RMID, NULL);
	
	return 0;
	
}