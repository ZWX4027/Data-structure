#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//求next数组
void getNext(char* t, int next[])
{
	int len = strlen(t);
	int k = 0;//最大前缀和最大后缀相等的个数
	int j = 1;//从1开始的原因是0号下标的k值我们直接给出
	if (len == 0)
	{
		return ;
	}
	next[0] = -1;
	if (len > 1)
	{
		next[1] = 0;//因为下标1前面也没有最大前缀和最大后缀
		while (j < len - 1)//表示模式串没有遍历完
		{
			if (k == -1||t[k] == t[j])//k = -1表示没有最大前缀和最大后缀相等
			{
				next[j + 1] = k + 1;
				j++;
				k++;
				
			}
			else
			{
				k = next[k];
				//如果刚开始3号下标就不相等，那么k=next[0]=-1???而且next[3]=???
				//这样明显是错的，所以我们要在k==-1时，另作处理
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
	int i = 0;//s的下标
	int j = 0;//t的下标
	int* next = (int*)malloc(sizeof(int)*tlen);
	getNext(t, next);
	ShowNext(next, tlen);
	while (i < slen && j < tlen)//表示主串和模式串都没有匹配完成
	//j == -1表示前面已经不能回退了
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
		return i - tlen;//返回匹配位置
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