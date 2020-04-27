#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//��2346   ���pos��2��pow�����100��˵���ŵ��ǰ�λ����Ҫ�õ�����3
//��pow(10.0,pos)��η���10��pos�η�
//���pos = 0,�õ�����1;pos = 1,�õ�����10;pos = 2,�õ�����100,
int GetFiNumber(int val, int pos)//����һ�����ݣ���������ݶ�Ӧλ��������
{
	return val / (int)(pow(10.0, pos)) % 10;
}

//
void Radix(int arr[], int len, int figure)
{
	int* bucket[10];//����10��Ͱ
	int i = 0;
	int finum;//ÿ������λ���ϵ����֣�Ҳ���Ǵ�����Ͱ
	int count[10] = {};//ÿ��Ͱ�ﵱǰ�ɲ���Ԫ�ص��±꣬Ҳ�ɱ�ʶ��ǰͰ�е�Ԫ�ظ���
	int arrindex = 0;//�������ݴ�ŵ��������ʼ�±�
	int bucketindex = 0;//����ÿ��Ͱ����ʼ�±�
	for (i; i < 10; i++)//��10��Ͱ���ٿռ�
	{
		bucket[i] = (int*)malloc(sizeof(int)*len);
	}
	for (i = 0; i < len; i++)//�����ݷ���Ͱ��
	{
		finum = GetFiNumber(arr[i], figure);//��ȡarr[i]��Ӧ��λ���ô���ڼ���Ͱ��
		bucket[finum][count[finum]] = arr[i];//count[finum]��ʾfinum��Ͱ����ɲ���Ԫ�ص��±�
		//��ʾ��arr[i]�������[count[finum]]Ԫ�ص�finum��Ͱ��
		count[finum]++;//ÿ�θ�finum��Ͱ++������ʹcount[]��ʶͰ�е�Ԫ��
	}
	for (i = 0; i < 10; i++)//��Ͱ������Ԫ��ȡ���Ž�����
	{
		bucketindex = 0;
		while (count[i] != 0)//Ͱ����Ԫ��
		{
			arr[arrindex] = bucket[i][bucketindex];//i��Ӧ��Ͱ����bucketindex
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

//�������е��������������������λ��
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

//ͨ���������λ����������������
void RadixSort(int arr[], int len)
{
	int MaxFi = GetMaxfigure(arr, len);//����λ��
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