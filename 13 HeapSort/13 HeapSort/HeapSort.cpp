//������
#include<stdio.h>

void HeapAdjust(int arr[], int parent, int len)
{
	int child = 2 * parent + 1;
	int tmp ;
	for (child; child < len; child = 2 * parent + 1)
	{
		if ((child < len - 1) && (arr[child + 1] > arr[child]))//������Ҳ���Һ���&&�Һ��Ӵ�������
		{
			child++;
		}//child��ʶ���Һ����нϴ������
		if (arr[parent] > arr[child])//���׽��������Һ��ӵĽϴ�ֵ
			break;
		tmp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = tmp;
			
		parent = child;//���׽���λ�ñ�ʶ�����Һ����з���������֧·��
	}
}
void HeapSort(int arr[], int len)
{
	int tmp;
	int parent = (len - 2) / 2;//��ʼ��ʶ���һ�����׽ڵ��λ��
	for (parent; parent >= 0; parent--)//ѭ������ÿһ�����׽���λ��
	{
		HeapAdjust(arr, parent, len);
	}

	//for (parent = len - 1; parent >0; parent--)//len - 1��ʶ���һ��Ԫ���±�
	//{
	//	tmp = arr[parent];
	//	arr[parent] = arr[0];
	//	arr[0] = tmp;
	//	HeapAdjust(arr, 0, parent);
	//}
}
int main()
{
	int arr[] = { 12, 3, 21, 32, 1, 34, 12, 35, 34};
	int len = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}