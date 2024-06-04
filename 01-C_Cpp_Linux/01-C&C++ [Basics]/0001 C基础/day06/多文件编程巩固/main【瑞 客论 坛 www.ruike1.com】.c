#define _CRT_SECURE_NO_WARNINGS

#include "myInclude.h"

int main(void)
{
	int arr[] = {3, 4, 6, 7, 8, 22, 99, 43, 0, 56};

	my_sort(arr);

	print_arr(arr);

	system("pause");
	return EXIT_SUCCESS;
}




