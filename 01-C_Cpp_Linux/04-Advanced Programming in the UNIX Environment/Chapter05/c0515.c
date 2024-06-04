#include "apue.h"

#define BSZ 48

int main()
{
	FILE *fp;
	char buf[BSZ];

	memset(buf, 'a', BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';
	if ((fp = fmemopen(buf, BSZ, "w+")) == NULL)
		err_sys("fmemopen failed");
	printf("Initial buffer contents: %s\n", buf);
	fprintf(fp, "hello, world"); //д������
	printf("Before flush: %s\n\n", buf);
	fflush(fp); //����fflush��fclose����fseek��fseeko��fsetpos���ڵ�ǰλ�����null
	printf("After fflush: %s\n", buf);
	printf("Len of string in buf = %ld\n\n", (long)strlen(buf));

	memset(buf, 'b', BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';
	fprintf(fp, "hello, world");
	fseek(fp, 0, SEEK_SET); //����ƫ��ֵ��ϴ֮���λ��
	printf("After  fseek: %s\n", buf);
	printf("Len of string in buf = %ld\n\n", (long)strlen(buf));

	memset(buf, 'c', BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';
	fprintf(fp, "hello, world"); //����д��ȥ
	fclose(fp);
	//fseek(fp, 0, SEEK_SET); //ƫ��ֵ��Ϊ��������ʼλ��
	printf("After fseek: %s\n", buf);
	printf("Len of string in buf = %ld\n\n", (long)strlen(buf));
/*
	memset(buf, 'd', BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';
	fprintf(fp, "hello, world"); //����д��ȥ
	fclose(fp); //Ȼ��fclose�ڵ�ǰλ��Ҳ��������β�����һ��null
	printf("After close: %s\n", buf);
	printf("Len of string in buf = %ld\n", (long)strlen(buf));
*/
	return(0);
}