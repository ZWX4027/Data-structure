#include<stdio.h>

void ShowSort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("  %d ", arr[i]);
	}
	printf("\n\n");
}
void BubbleSort(int arr[], int len)
{
	int i = 0; 
	int j = 0;
	int tmp = 0;
	int pos = 0;
	int k = len - 1;
	int p = 1;
	for (i; i < len-1 ; i++)
	{
		int flag = 0;
		for (j = 0; j < len - i - 1; j++ )
		{
			if (arr[j + 1] < arr[j])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
				flag = 1;
				pos = j;
			}
		}
		k = pos;
		if (flag = 0)
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 3, 4, 2, 1, 5, 6, 7, 8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, len);
	printf("×îÖÕ½á¹û:\n");
	ShowSort(arr, len);
	return 0;
}