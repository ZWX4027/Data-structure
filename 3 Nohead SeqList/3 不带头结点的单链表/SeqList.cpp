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

//Node** phead���൱��pList *phead,pList�������һ��ָ������
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
	Node* pCur = *ptwohead;//ָ��*ptwohead����ָ��phead����ŵĵ�ַ���ڵ�λ�ã�����һ�����ݽ��
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
	Node* pfront = *ptwohead;//ָ���һ�����
	Node* pCur = pfront->next;//���Ϊ��˵����������ֻ��һ����㣬�ǿ�˵�����������������ϵĽ��
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
	//pfront   �����ڶ���
	//pCur    ������һ��
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


