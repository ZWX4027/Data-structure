#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[], int tmp[], int start,int mid, int end)//合并小组并排序
{
	int i = start;//i标识左小组的第一个元素位置
	int j = mid + 1;//j标识右小组的第一个元素位置
	int k = start;//tmp当前小组存放的起始位置
	while (i < mid + 1 && j < end + 1)//左小组越界或右小组越界才能退出
	{
		if (arr[i] <= arr[j])
		{
			/*tmp[k] = arr[i];
			k++;
			i++;*/
			tmp[k++] = arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
		}
	}
	while (j < end + 1)//右边小组没有越界
	{
		tmp[k++] = arr[j++];
	}
	while (i < mid + 1)//左边小组没有越界
	{
		tmp[k++] = arr[i++];
	}
	for (i = start; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}
void MergeS(int arr[], int tmp[], int start, int end)//划分小组
{
	if (start < end)
	{
		int mid = (start+end)/2;
		MergeS(arr, tmp, start, mid);
		MergeS(arr, tmp, mid + 1, end);
		Merge(arr, tmp, start, mid, end);
	}
}

void MergeSort(int arr[], int len)
{
	int *tmp = (int *)malloc(sizeof(int)*len);//排序后结果保存的临时数组
	MergeS(arr, tmp, 0, len - 1);
	free(tmp);
}
int main()
{
	int arr[] = { 12, 3, 21, 32, 1, 34, 12, 35, 34 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}