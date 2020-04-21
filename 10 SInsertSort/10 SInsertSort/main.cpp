//简单插入排序
#include<stdio.h>

void InsertSort(int arr[], int len)
{
	int i = 1;
	int j = i-1;
	int tmp = 0;
	for (i; i < len; i++)
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > tmp; j--)//j >= 0 已排序部分还没有遍历完成
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = tmp;
	}	
}
int main()
{
	int arr[] = { 12, 3, 21, 32, 1, 34, 12, 35, 34, 18 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	InsertSort(arr, len);
	for (i; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}