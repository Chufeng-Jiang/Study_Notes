#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

char* mystrcpy(char* dest, const char* src)
{
	char* temp = dest;
	
	if (!dest || !src)
		return NULL;
		
	while (*dest++ = *src++);
	
	return temp;
}

char* mystrncpy(char* dest, const char* src, size_t size)
{
	if (!dest || !src)
		return NULL;
		
	size_t i;
	
	for ( i = 0; i < size; i++)
	{
		*(dest+i) = *(src+i);
	}
	*(dest + i) = 0;
	
	return dest;
}
int main(void)
{
	char src[] = "hello world";
	
	char dst[100];

	//mystrcpy(dst, src);
	mystrncpy(dst, src, 5);
	
	printf("%s\n", dst);
	
	return EXIT_SUCCESS;
}
