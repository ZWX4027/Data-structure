#include<stdio.h>
#include"Queue.h"

void init(pQueue pqu)
{
	if (pqu != NULL)
	{
		pqu->front = pqu->rear = 0;
	}
}

int full(pQueue pqu)
{
	return (pqu->rear + 1) % MAX_SIZE == pqu->front;
}

int enqueue(pQueue pqu, ElemType val)
{
	if (full(pqu))
	{
		return 0;
	}
	pqu->arr[pqu->rear] = val;
	pqu->rear = (pqu->rear + 1) % MAX_SIZE;
	return 1;
}

int empty(pQueue pqu)
{
	return pqu->front == pqu->rear ? 1 : 0;
}

int dequeue(pQueue pqu)
{
	if (empty(pqu))
	{
		return 0;
	}
	pqu->front = (pqu->front + 1) % MAX_SIZE;
	return 1;
}

int front(pQueue pqu)
{
	if (empty(pqu))
	{
		return 0;
		//C++中操作,要加头文件#include<iostream>
		//throw std::exception("queue is empty!");
	}
	return pqu->arr[pqu->front];
}

int back(pQueue pqu)
{
	if (empty(pqu))
	{
		return 0;
	}
	//return pqu->arr[pqu->rear - 1];//error
	return pqu->arr[(pqu->rear + MAX_SIZE - 1) % MAX_SIZE];
}