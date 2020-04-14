#include<stdio.h>
#include<stdlib.h>
#include"SeqList.h"

//初始化
void init(pList phead)
{
	//当main函数中，出现head(NULL);时会导致指向了一个无效的地址，所以要先判断指向地址的节点是否合理
	if (phead == NULL)
	{
		exit(0); //用到头文件<stdlib.h>，程序直接退出
	}
	phead->data = 0;
	phead->Next = NULL;
}
//插入
Node* buyNode(ElemType val)
{
	Node* pnewnode = (Node*)malloc(sizeof(Node));//开辟新结点
	pnewnode->data = val;
	pnewnode->Next = NULL;
	return pnewnode;
}
int insertHead(pList phead, ElemType val)
{
	Node* pnewnode = buyNode(val);
	pnewnode->Next = phead->Next;
	phead->Next = pnewnode;
	return 1;
}
int insertTail(pList phead, ElemType val)
{
	Node* pnewnode = buyNode(val);
	Node* ptail = phead;
	//有两种情况，空链表和有数据的链表
	while (ptail->Next != NULL)
	{
		ptail = ptail->Next;
	}
	ptail->Next = pnewnode;
	return 1;
}
int getLength(pList phead)
{
	int count = 0;
	Node* pCur = phead->Next;
	while (pCur != NULL)
	{
		count++;
		pCur = pCur->Next;
	}
	return count;
}
int insertPos(pList phead, int pos, ElemType val)
{
	int i = 0;
	Node* pfront = phead;
	Node* pnewnode = buyNode(val);
	if (pos<0 || pos > getLength(phead))
	{
		return -1;
	}
	for (i; i < pos; i++)
	{
		pfront = pfront->Next;
	}
	pnewnode->Next = pfront->Next;
	pfront->Next = pnewnode;
	return 1;
}
//删除
int Empty(pList phead)
{
	return (phead->Next == NULL) ? 1 : 0;//1为空
}
int deleteHead(pList phead)
{
	if (Empty(phead))
	{
		return -1;
	}
	Node* pdel = phead->Next;
	phead->Next = pdel->Next;
	free(pdel);
	return 1;
}
int deleteTail(pList phead)
{
	if (Empty(phead))
	{
		return -1;
	}
	Node* ptail2 = phead;
	Node* pdel = NULL;
	while (ptail2->Next != NULL)
	{
		if (ptail2->Next->Next == NULL)
		{
			break;
		}
		ptail2 = ptail2->Next;
	}
	pdel = ptail2->Next;
	ptail2->Next = NULL;
	free(pdel);
	return 1;
}
int deletePos(pList phead, int pos)
{
	int i = 0;
	Node* pfront = phead;
	Node* pdel = NULL;
	if (pos < 0 || pos >= getLength(phead))
	{
		return -1;
	}
	for (i; i < pos; i++)
	{
		pfront = pfront->Next;
	}
	pdel = pfront->Next;
	pfront->Next = pdel->Next;
	free(pdel);
	return 1;
}
void  Show(pList phead)
{
	Node* pCur = phead->Next;
	while (pCur != NULL)
	{
		printf("%d  ", pCur->data);
		pCur = pCur->Next;
	}
	printf("\n");
}
void destroy(pList phead)
{
	Node* pCur = phead->Next;
	Node* pNext = NULL;
	while (pCur != NULL)
	{
		pNext = pCur->Next;
		free(pCur);
		pCur = pNext;
	}
	phead->Next = NULL;
}



