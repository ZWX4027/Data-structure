#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[], int tmp[], int start,int mid, int end)//�ϲ�С�鲢����
{
	int i = start;//i��ʶ��С��ĵ�һ��Ԫ��λ��
	int j = mid + 1;//j��ʶ��С��ĵ�һ��Ԫ��λ��
	int k = start;//tmp��ǰС���ŵ���ʼλ��
	while (i < mid + 1 && j < end + 1)//��С��Խ�����С��Խ������˳�
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
	while (j < end + 1)//�ұ�С��û��Խ��
	{
		tmp[k++] = arr[j++];
	}
	while (i < mid + 1)//���С��û��Խ��
	{
		tmp[k++] = arr[i++];
	}
	for (i = start; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}
void MergeS(int arr[], int tmp[], int start, int end)//����С��
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
	int *tmp = (int *)malloc(sizeof(int)*len);//��������������ʱ����
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