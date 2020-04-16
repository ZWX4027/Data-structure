#include<stdio.h>
#include"pStack_List.h"

void init(pStack pst)
{
	if (pst != NULL)
	{
		pst->top = 0;
	}
}

int full(pStack pst)
{
	return pst->top == STACK_SIZE ? 1 : 0;
}

int push(pStack pst, ElemType val)
{
	if (full(pst))
	{
		return 0;
	}
	pst->data[pst->top] = val;
	pst->top++;
	return 1;
}

int empty(pStack pst)
{
	return pst->top == 0 ? 1 : 0;
}

int pop(pStack pst)//只删除元素，不获取元素
{
	if (empty(pst))
	{
		return 0;
	}
	pst->top--;
	return 1;
}

int gettop(pStack pst,ElemType* prt)//拿到栈顶元素，但不删除
{
	if (empty(pst))
	{
		return 0;
	}
	*prt = pst->data[pst->top - 1];
	return 1;
}
