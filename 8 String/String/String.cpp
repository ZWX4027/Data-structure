#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"String.h"

//��ʼ��
void initString(pString ps)
{
	if (ps != NULL)
	{
		ps->pstr = NULL;
		ps->totalsize = 0;
		ps->cursize = 0;
	}
}

//��ֵ
void strAssign(pString ps, char* p)
{
	int len = strlen(p);//����p����Ч����
	if (ps->pstr != NULL)//�ж����ڴ����Ƿ���Ԫ�أ�����о��ͷŵ�
	{
		free(ps->pstr);
	}
	if (len == 0)//�ж�Ҫ��ֵ�Ĵ��Ƿ����
	{
		ps->pstr = NULL;//�������ڣ���Ϊ�����pstr�ͷŵ��ˣ�����Ҫ��NULL
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

//�ϲ�
void strSub(pString ps, pString p1, pString p2)
{
	int len1 = p1->cursize;
	int len2 = p2->cursize;
	int i=0;//ps�е������±�
	int j = 0;//p1��p2�������±�
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

//����ƥ���㷨
int BF(pString S, pString P)
{
	int i = 0;//����S�����±�
	int j = 0;//����P�����±�
	//i < S->cursize��ʾ����û�б����꣬j < P->cursize��ʾģʽ��û�б�����
	//��(i < S->cursize && j > P->cursize)����(i > S->cursize && j > P->cursize)ʱ��ƥ��ɹ�
	//��(i > S->cursize && j < P->cursize)ʱ��ƥ��ʧ��
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
	if (j = P->cursize)//j�����Ĵ�������ģʽ��P����Ч����
	{
		return i - P->cursize;//����ɹ����������˱����ɹ�����λ��
	}
}

//��ӡ��
void strPring(pString ps)
{
	for (int i = 0; i < ps->cursize; i++)
	{
		printf("%c", ps->pstr[i]);
	}
	printf("\n");
}

//����
void destroy(pString ps)
{
	if (ps->pstr != NULL)
	{
		free(ps->pstr);
	}
	ps->totalsize = ps->cursize = 0;
}
