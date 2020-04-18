#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"Queue.h"
using namespace std;

void init(pQue pqu)
{
	if (pqu != NULL)
	{
		//在堆上动态申请一个空间存放头结点，无实际意义
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


//获取队头元素
int front(pQue pqu)
{
	if (empty(pqu))
	{
		throw exception("queue is empty!");//代码直接跳转到调用方
	}
	return pqu->phead->next->data;
}
int back(pQue pqu)
{
	if (empty(pqu))
	{
		throw exception("queue is empty!");//代码直接跳转到调用方
	}
	return pqu->ptail->data;
}

//清理函数：只删除数据，不销毁结构
void clear(pQue pqu)
{
	Node* pCur = pqu->phead->next;//第一个数据结点
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

//销毁函数：数据和结构一起销毁
void destory(pQue pqu)
{
	clear(pqu);//销毁数据结点
	free(pqu->phead);//销毁头结点
	pqu->phead = pqu->ptail = NULL;
}