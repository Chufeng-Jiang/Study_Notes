#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

char *my_strchr(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return str;
		str++;
	}
	return NULL;
}

char *my_strchr2(char *str, char ch)
{
	int i = 0;
	//while (str[i] != '\0')
	while (str[i])		// str[i] --> *(str+i)
	{
		if (str[i] == ch)
			return &str[i];
		i++;
	}
	return NULL;
}

int main(void)
{
	char str[] = "hello";
	char ch = 'l';

	char *p = my_strchr2(str, ch);

	if (p == NULL)
		printf("ц╩сп\n");
	else
		printf("%s\n", p);

	system("pause");
	return EXIT_SUCCESS;
}
