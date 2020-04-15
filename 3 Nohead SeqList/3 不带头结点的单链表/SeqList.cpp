#include<stdio.h>
#include"SeqList.h"
#include<stdlib.h>

void init(Node** phead)
{
	*phead = NULL;
}

Node *buyNode(ElemType val)
{
	Node* pnewnode = (Node*)malloc(sizeof(Node));
	pnewnode->data = val;
	pnewnode->next = NULL;
	return pnewnode;
}

//Node** phead就相当于pList *phead,pList本身就是一个指针类型
int insertHead(pList* phead, ElemType val)
{
	Node* pnewnode = buyNode(val);
	pnewnode->next = (*phead);
	(*phead) = pnewnode;
	return 1;
}

int insertTail(pList* ptwohead, ElemType val)
{
	Node* pnewnode = buyNode(val);
	Node* ptail = *ptwohead;
	if (*ptwohead == NULL)
	{
		(*ptwohead) = pnewnode;
	}
	
	while (ptail->next != NULL)
	{
		ptail = ptail->next;
	}
	ptail->next = pnewnode;
	return 1;
}

int empty(Node* phead)
{
	return phead == NULL ? 1 : 0;
}

int deleteHead(pList* ptwohead)
{
	if (empty(*ptwohead))
	{
		return 0;
	}
	Node* pCur = *ptwohead;//指向*ptwohead就是指向phead所存放的地址所在的位置，即第一个数据结点
	*ptwohead = pCur->next;
	free(pCur);
	return 1;
}

int deleteTail(pList* ptwohead)
{
	if (empty(*ptwohead))
	{
		return 0;
	}
	Node* pfront = *ptwohead;//指向第一个结点
	Node* pCur = pfront->next;//如果为空说明整个链表只有一个结点，非空说明有两个或两个以上的结点
	if (pCur == NULL)
	{
		*ptwohead = NULL;
		free(pfront);
		return 1;
	}
	while (pfront->next != NULL)
	{
		pCur = pfront->next;
		if (pCur->next == NULL)
		{
			break;
		}
		pfront = pfront->next;
	}
	//pfront   倒数第二个
	//pCur    倒数第一个
	pfront->next = NULL;
	free(pCur);
	return 1;
}

void Show(Node* phead)
{
	Node* pCur = phead;
	while (pCur != NULL)
	{
		printf("%d  ", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}

//void destroy(pList* ptwohead)
//{
//	Node* pCur = *ptwohead;
//	Node* pNext = NULL;
//	while (pCur != NULL)
//	{
//		pNext = pCur->next;
//		free(pCur);
//		pCur = pNext;
//	}
//	*ptwohead = NULL;
//}


