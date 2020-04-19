#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"String.h"

//初始化
void initString(pString ps)
{
	if (ps != NULL)
	{
		ps->pstr = NULL;
		ps->totalsize = 0;
		ps->cursize = 0;
	}
}

//赋值
void strAssign(pString ps, char* p)
{
	int len = strlen(p);//计算p的有效长度
	if (ps->pstr != NULL)//判断现在串中是否有元素，如果有就释放掉
	{
		free(ps->pstr);
	}
	if (len == 0)//判断要赋值的串是否存在
	{
		ps->pstr = NULL;//串不存在，因为上面把pstr释放掉了，所以要置NULL
		ps->totalsize = ps->cursize = 0;
	}
	else
	{
		ps->pstr = (char*)malloc(sizeof(char)*len);
		for (int i = 0; i < len; i++)
		{
			ps->pstr[i] = p[i];
		}
		ps->totalsize = len;
		ps->cursize = len;
	}
}

//合并
void strSub(pString ps, pString p1, pString p2)
{
	int len1 = p1->cursize;
	int len2 = p2->cursize;
	int i=0;//ps中的数据下标
	int j = 0;//p1、p2的数据下标
	if (ps->pstr != NULL)
	{
		free(ps->pstr);
	}
	if (!len1 && !len2)
	{
		ps->pstr = NULL;
		ps->totalsize = ps->cursize = 0;
	}
	else
	{
		ps->pstr = (char*)malloc(sizeof(char)*(len1+len2));
		for (j = 0; j < len1; j++)
		{
			ps->pstr[i++] = p1->pstr[j];
		}
		for (j = 0; j < len2; j++)
		{
			ps->pstr[i++] = p2->pstr[j];
		}
		ps->totalsize = (len1 + len2);
		ps->cursize = (len1 + len2);
	}
}

//朴素匹配算法
int BF(pString S, pString P)
{
	int i = 0;//定义S串的下标
	int j = 0;//定义P串的下标
	//i < S->cursize表示主串没有遍历完，j < P->cursize表示模式串没有遍历完
	//当(i < S->cursize && j > P->cursize)或者(i > S->cursize && j > P->cursize)时，匹配成功
	//当(i > S->cursize && j < P->cursize)时，匹配失败
	while (i < S->cursize && j < P->cursize)
	{
		if (S->pstr[i] == P->pstr[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j = P->cursize)//j遍历的次数等于模式串P的有效长度
	{
		return i - P->cursize;//如果成功，返回这趟遍历成功的首位置
	}
}

//打印串
void strPring(pString ps)
{
	for (int i = 0; i < ps->cursize; i++)
	{
		printf("%c", ps->pstr[i]);
	}
	printf("\n");
}

//销毁
void destroy(pString ps)
{
	if (ps->pstr != NULL)
	{
		free(ps->pstr);
	}
	ps->totalsize = ps->cursize = 0;
}
