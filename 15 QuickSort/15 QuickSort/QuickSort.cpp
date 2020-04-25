#include<stdio.h>

int parition(int arr[], int start, int end)//�ҵ���׼���Ļ�׼���±�
{
	int boundkey = arr[start];
	while (start < end)//Ԫ��û�б����꣬���start<=end��ʾ�������ݱȽ����
	{
		while (start < end && arr[end] >= boundkey)//Ԫ��û�б����겢�Ҵ������ں��棬�����ƶ�
			end--;
		arr[start] = arr[end];//���������ݱȻ�׼ֵС
		while (start < end && arr[start] <= boundkey)//Ԫ��û�б����겢��С������ǰ�棬�����ƶ�
			start++; 
		arr[end] = arr[start];
	}
	arr[end] = boundkey;
	return start;//��ʱstart = end
}
void Quick(int arr[], int start, int end)//��������
{
	int key;
	if (start < end)//�ж���������Ƿ���Ҫ����
	{
		key = parition(arr,start,end);//��start��end�ҵ���׼��
		Quick(arr,start, key - 1);//�ݹ���ðѻ�׼����߻��ֳ�һ������
		Quick(arr,key + 1, end);//�ݹ���ðѻ�׼���ұ߻��ֳ�һ������
	}
}
void QuickSort(int arr[], int len)//�õ����ݺ������С,���������б�����
{
	Quick(arr, 0, len - 1);
}
int main()
{
	int arr[] = { 12, 3, 21, 32, 1, 34, 12, 35, 34 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	QuickSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}