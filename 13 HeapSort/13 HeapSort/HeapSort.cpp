//堆排序
#include<stdio.h>

void HeapAdjust(int arr[], int parent, int len)
{
	int child = 2 * parent + 1;
	int tmp ;
	for (child; child < len; child = 2 * parent + 1)
	{
		if ((child < len - 1) && (arr[child + 1] > arr[child]))//有左孩子也有右孩子&&右孩子大于左孩子
		{
			child++;
		}//child标识左右孩子中较大的数据
		if (arr[parent] > arr[child])//父亲结点大于左右孩子的较大值
			break;
		tmp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = tmp;
			
		parent = child;//父亲结点的位置标识到左右孩子中发生调整的支路上
	}
}
void HeapSort(int arr[], int len)
{
	int tmp;
	int parent = (len - 2) / 2;//起始标识最后一个父亲节点的位置
	for (parent; parent >= 0; parent--)//循环调整每一个父亲结点的位置
	{
		HeapAdjust(arr, parent, len);
	}

	//for (parent = len - 1; parent >0; parent--)//len - 1标识最后一个元素下标
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