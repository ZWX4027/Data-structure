#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//①2346   如果pos是2，pow结果是100，说明排的是百位，就要得到数据3
//②pow(10.0,pos)求次方，10的pos次方
//如果pos = 0,得到的是1;pos = 1,得到的是10;pos = 2,得到的是100,
int GetFiNumber(int val, int pos)//给出一个数据，求出该数据对应位数的数字
{
	return val / (int)(pow(10.0, pos)) % 10;
}

//
void Radix(int arr[], int len, int figure)
{
	int* bucket[10];//给出10个桶
	int i = 0;
	int finum;//每个数据位数上的数字，也就是代表几号桶
	int count[10] = {};//每个桶里当前可插入元素的下标，也可标识当前桶中的元素个数
	int arrindex = 0;//代表数据存放的数组的起始下标
	int bucketindex = 0;//代表每个桶的起始下标
	for (i; i < 10; i++)//给10个桶开辟空间
	{
		bucket[i] = (int*)malloc(sizeof(int)*len);
	}
	for (i = 0; i < len; i++)//把数据放入桶中
	{
		finum = GetFiNumber(arr[i], figure);//获取arr[i]对应的位数该存放在几号桶中
		bucket[finum][count[finum]] = arr[i];//count[finum]表示finum号桶里面可插入元素的下标
		//表示将arr[i]存放在有[count[finum]]元素的finum号桶中
		count[finum]++;//每次给finum号桶++，就能使count[]标识桶中的元素
	}
	for (i = 0; i < 10; i++)//把桶中所有元素取出放进数组
	{
		bucketindex = 0;
		while (count[i] != 0)//桶里有元素
		{
			arr[arrindex] = bucket[i][bucketindex];//i对应的桶里面bucketindex
			bucketindex++;
			arrindex++;
			count[i]--;
		}
	}
	for (i = 0; i < 10; i++)
	{
		free(bucket[i]);
	}
}

//找数组中的最大数，并求出最大数的位数
int GetMaxfigure(int arr[], int len)
{
	int max = -1;
	int count = 0;
	int i = 0;
	for (i; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	while (max != 0)
	{
		max = max / 10;
		count++;
	}

	return count;
}

//通过最大数的位数控制了排序趟数
void RadixSort(int arr[], int len)
{
	int MaxFi = GetMaxfigure(arr, len);//最大的位数
	int i = 0;
	for (i; i < MaxFi; i++)
	{
		Radix(arr, len, i);
	}
}

int main()
{
	int arr[] = {  3, 2, 43, 46, 75, 12, 4, 235, 45, 7, 34 };
	int len = sizeof(arr) / sizeof(arr[0]);
	
	int max = GetMaxfigure(arr, len);
	printf("%d  \n", max);

	RadixSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}