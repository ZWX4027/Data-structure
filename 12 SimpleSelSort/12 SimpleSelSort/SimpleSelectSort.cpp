#include<stdio.h>

void SelectSort(int arr[], int len)
{
	int i = 0;
	int j;
	int min = 0;
	int tmp = 0;
	for (i = 0; i < len-1; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
		
	}
	
}
int main()
{
	int arr[] = { 12, 3, 21, 32, 1, 34, 12, 35, 34, 18, 67, 18, 17, 32, 45, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}