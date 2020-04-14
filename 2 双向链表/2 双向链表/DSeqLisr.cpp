#include <stdio.h>
#include "DSeqList.h"
#include <stdlib.h>

//初始化
void init(DPList plist)
{
	if (plist == NULL)
	{
		exit(0);
	}
	//plist->data = 0;
	plist->prev = NULL;
	plist->next = NULL;
}

Node* buyNode(ElemType val)
{
	Node* pnewnode = (Node*)malloc(sizeof(Node));
	pnewnode->prev = pnewnode->next = NULL;
	pnewnode->data = val;
	return pnewnode;
}

//头插
int insertHead(DPList plist, ElemType val)
{
	Node* pnewnode = buyNode(val);
	Node* pfront = plist;
	pnewnode->next = plist->next;
	pnewnode->prev = plist;
	if (pfront->next != NULL)
	{
		pfront->next->prev = pnewnode;
	} 
	plist->next = pnewnode;
	return 0;	
}

//尾插
int insertTail(DPList plist, ElemType val)
{
	Node* pnewnode = buyNode(val);
	Node* ptail = plist;
	while (ptail->next != NULL)
	{
		ptail = ptail->next;
	}
	ptail->next = pnewnode;
	pnewnode->prev = ptail;
	return 1;
}

//获取当前的链表长度：判断位置是否合理
int getLength(DPList plist)
{
	int count = 0;
	Node* pCur = plist->next;
	while (pCur != NULL)
	{
		pCur = pCur->next;
		count++;
	}
	return count;
}

//按位置插入
int insertPos(DPList plist, int pos, ElemType val)
{
	Node* pfront = plist;
	if (pos < 0 || pos > getLength(plist))
	{
		return 0;
	}
	for (int i = 0; i < pos; i++)
	{
		pfront = pfront->next;
	}
	Node* pnewnode = buyNode(val);
	pnewnode->next = pfront->next;
	pnewnode->prev = pfront;
	if (pfront->next != NULL)
	{
		pfront->next->prev = pnewnode;
	}
	pfront->next = pnewnode;
	return 1;
}

//判空
int empty(DPList plist)
{
	return plist->next == NULL ? 1 : 0;
}

//头删
int deleteHead(DPList plist)
{
	if (empty(plist))
	{
		return 0;
	}
	Node* pCur = plist->next;
	plist->next = pCur->next;
	if (pCur != NULL)
	{
		pCur->next->prev = plist;
	}
	free(pCur);
	return 1;
}

//尾删
int deleteTail(DPList plist)
{
	if (empty(plist))
	{
		return 0;
	}
	Node* ptail2 = plist;
	Node* pCur = NULL;
	while (ptail2->next != NULL)
	{
		if (ptail2->next->next == NULL)
		{
			break;
		}
		ptail2 = ptail2->next;
	}
	pCur = ptail2->next;
	ptail2->next = NULL;
	free(pCur);
	return 1;
}

//按位置删除
int deletePos(DPList plist, int pos)
{
	Node* pfront = plist;
	if (pos < 0 || pos >= getLength(plist))
	{
		return -1;
	}
	for (int i = 0; i < pos; i++)
	{
		pfront = pfront->next;
	}
	Node* pCur = NULL;
	pCur = pfront->next;
	pfront->next = pCur->next;
	if (pCur->next != NULL)
	{
		pCur->next->prev = pfront;
	}
	free(pCur);
	return 1;
}

//查询
void Show(DPList plist)
{
	Node* pCur = plist->next;
	while (pCur != NULL)
	{
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}

void destroy(DPList plist)
{
	Node* pCur = plist->next;
	Node* pNext = NULL;
	while (pCur != NULL)
	{
		pNext = pCur->next;
		free(pCur);
		pCur = pNext;
	}
	plist->next = NULL;
}