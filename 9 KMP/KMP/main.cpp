#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��next����
void getNext(char* t, int next[])
{
	int len = strlen(t);
	int k = 0;//���ǰ׺������׺��ȵĸ���
	int j = 1;//��1��ʼ��ԭ����0���±��kֵ����ֱ�Ӹ���
	if (len == 0)
	{
		return ;
	}
	next[0] = -1;
	if (len > 1)
	{
		next[1] = 0;//��Ϊ�±�1ǰ��Ҳû�����ǰ׺������׺
		while (j < len - 1)//��ʾģʽ��û�б�����
		{
			if (k == -1||t[k] == t[j])//k = -1��ʾû�����ǰ׺������׺���
			{
				next[j + 1] = k + 1;
				j++;
				k++;
				
			}
			else
			{
				k = next[k];
				//����տ�ʼ3���±�Ͳ���ȣ���ôk=next[0]=-1???����next[3]=???
				//���������Ǵ�ģ���������Ҫ��k==-1ʱ����������
			}
		}
	}
}

void ShowNext(int next[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", next[i]);
	}
	printf("\n");
}
int KMP(char* s, char* t)
{
	int slen = strlen(s);
	int tlen = strlen(t);
	int i = 0;//s���±�
	int j = 0;//t���±�
	int* next = (int*)malloc(sizeof(int)*tlen);
	getNext(t, next);
	ShowNext(next, tlen);
	while (i < slen && j < tlen)//��ʾ������ģʽ����û��ƥ�����
	//j == -1��ʾǰ���Ѿ����ܻ�����
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	free(next);
	if (j == tlen)
	{
		return i - tlen;//����ƥ��λ��
	}
	return -1;
}

int main()
{
	char* s = "ABCABCABCCCABCABCD";
	char* t = "ABCABCD";
	int kmp = KMP(s, t);
	printf("%d  ", kmp);
	printf("\n");
	return 0;
}