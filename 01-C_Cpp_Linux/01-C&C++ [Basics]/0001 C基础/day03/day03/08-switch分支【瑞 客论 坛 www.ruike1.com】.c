#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0801(void)
{
	int score;
	scanf("%d", &score);

	switch (score/10)
	{
	case 10:		//	 100 -- 90 优秀
	case 9:	    
		printf("优秀\n");
		break;
	case 8:			//   70 -- 90 良好
	case 7:
		printf("良好\n");
		//break;
	case 6:		   // 70 - 60 及格
		printf("及格\n");
		//break;
	default:
		printf("不及格\n");
		break;		
	}

	system("pause");
	return EXIT_SUCCESS;
}
