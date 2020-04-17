#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

void init(pStack pst)
{
	if (pst != NULL)
	{
		pst->next = NULL;
	}
}

Node* buyNode(ElemType val)
{
	Node* pnewnode = (Node*)malloc(sizeof(Node));
	pnewnode->data = val;
	pnewnode->next = NULL;
	return pnewnode;
}

//Ԫ����һ�������ͷ��
void push(pStack pst, ElemType val)
{
	Node* pnewnode = buyNode(val);
	pnewnode->next = pst->next;
	pst->next = pnewnode;
	
}

int empty(pStack pst)
{
	return pst->next == NULL ? 1 : 0;
}

//�����ͷɾ���൱�ڳ�ջ
int pop(pStack pst)
{
	if (empty(pst))
	{
		return 0;
	}
	Node* pCur = pst->next;
	pst->next = pCur->next;
	free(pCur);
	return 1;
}

int gettop(pStack pst, ElemType* prt)
{
	if (empty(pst))
	{
		return 0;
	}
	*prt = pst->next->data;//��һ�����ݽ�������
	return 1;
}

void destory(pStack pst)
{
	Node* pCur = pst->next;//��һ�����ݽ��
	Node* pNext = NULL;
	while (pCur != NULL)
	{
		pNext = pCur->next;
		free(pCur);
		pCur = pNext;
	}
	pst->next = NULL;
}