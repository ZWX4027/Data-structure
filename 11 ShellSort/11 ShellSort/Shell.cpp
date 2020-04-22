#include<stdio.h>

void Shell(int arr[], int len, int dk)
{
	int tmp;
	int i;
	int j;
	for (i = dk; i < len; i++)
	{
		tmp = arr[i];
		for (j = i - dk; j >= 0 && arr[j] > tmp; j -= dk)
		{
			arr[j + dk] = arr[j];
		}
		arr[j + dk] = tmp;
	}
	
}
void ShellSort(int arr[], int len)
{
	int dk[] = { 5, 3, 1 };
	int dklen = sizeof(dk) / sizeof(dk[0]);
	int i = 0;	
	for (i; i < dklen; i++)
	{
		Shell(arr, len, dk[i]);
	}
}
int main()
{
	int arr[] = { 12, 3, 21, 32, 1, 34, 12, 35, 34, 18, 67, 18, 17, 32, 45, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	ShellSort(arr, len);
	for (i; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}