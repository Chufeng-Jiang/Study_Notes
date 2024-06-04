
int main(void)
{
	int arr[] = {2, 7, 3, 10 ,8, 5, 9, 88, 53};

	int n = sizeof(arr) / sizeof(arr[0]);	// 获取数组元素个数

	int i = 0;					// 最小下标
	int j = n - 1;				// 最大下标。
	int temp = 0;

	while (i < j)
	{
		temp = arr[i];			// 三杯水法 交换 arr[i] 和 arr[j] 这两个变量
		arr[i] = arr[j];
		arr[j] = temp;
		i++;					// 从最小下标向后
		j--;					// 从最大下标向前
	}
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}