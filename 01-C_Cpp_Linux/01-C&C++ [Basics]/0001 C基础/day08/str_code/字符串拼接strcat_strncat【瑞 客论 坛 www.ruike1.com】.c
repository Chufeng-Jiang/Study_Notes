#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

char* mystrcat(char* dst, const char* src)
{
	char* temp = dst;
	if (!dst || !src)
		return NULL;

	while (*dst)dst++;

	while (*dst++ = *src++);

	return temp;

}

char* mystrncat(char* dst, const char* src, size_t size)
{
	char* temp = dst;
	
	if (!dst || !src)
		return NULL;

	while (*dst)dst++;
	int i;
	for (i = 0; i < size; i++)
	{
		*(dst + i) = *(src + i);
	}
	*(dst + i) = 0;
	
	return temp;
}

int main(void)
{
	char src[] = "world";
	char dst[100] = "hello";

	//mystrcat(dst, src);
	mystrncat(dst, src, 3);
	
	printf("%s\n", dst);
	
	return EXIT_SUCCESS;
}
