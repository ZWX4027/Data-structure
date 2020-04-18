#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"Queue.h"
using namespace std;

void init(pQue pqu)
{
	if (pqu != NULL)
	{
		//�ڶ��϶�̬����һ���ռ���ͷ��㣬��ʵ������
		Node* pnhead = (Node*)malloc(sizeof(Node));
		pnhead->next = NULL;
		pqu->phead = pnhead;
		pqu->ptail = pnhead;
	}
}

Node* buyNode(ElemType val)
{
	Node* pnewnode = (Node*)malloc(sizeof(Node));
	pnewnode->data = val;
	pnewnode->next = NULL;
	return pnewnode;
}

void enqueue(pQue pqu, ElemType val)
{
	Node* pnewnode = buyNode(val);
	pqu->ptail->next = pnewnode;
	pqu->ptail = pnewnode;
}

int empty(pQue pqu)
{
	return (pqu->phead == pqu->ptail) && (pqu->phead != NULL) ? 1 : 0;
}

int dequeue(pQue pqu)
{
	if (empty(pqu))
	{
		return 0;
	}
	Node* pdelete = pqu->phead->next;
	pqu->phead->next = pdelete->next;
	if (pqu->phead->next == NULL)
	{
		pqu->ptail = pqu->phead;
	}
	free(pdelete);
	return 1;
}


//��ȡ��ͷԪ��
int front(pQue pqu)
{
	if (empty(pqu))
	{
		throw exception("queue is empty!");//����ֱ����ת�����÷�
	}
	return pqu->phead->next->data;
}
int back(pQue pqu)
{
	if (empty(pqu))
	{
		throw exception("queue is empty!");//����ֱ����ת�����÷�
	}
	return pqu->ptail->data;
}

//��������ֻɾ�����ݣ������ٽṹ
void clear(pQue pqu)
{
	Node* pCur = pqu->phead->next;//��һ�����ݽ��
	Node* pNext;
	if (pCur != NULL)
	{
		pNext = pCur->next;
		free(pCur);
		pNext = pNext->next;
	}
	pqu->phead->next = NULL;
	pqu->phead = pqu->ptail;
}

//���ٺ��������ݺͽṹһ������
void destory(pQue pqu)
{
	clear(pqu);//�������ݽ��
	free(pqu->phead);//����ͷ���
	pqu->phead = pqu->ptail = NULL;
}