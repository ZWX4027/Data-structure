#include<stdio.h>
#include"SeqList.h"

int main()
{
	Node* phead;
	init(&phead);
	int i = 1;
	for (i; i < 7; i++)
	{
		insertHead(&phead, i);
	}
	Show(phead);

	/*insertTail(&phead, 7);
	Show(phead);*/

	/*deleteHead(&phead);
	Show(phead);*/

	deleteTail(&phead);
	Show(phead);

	return 0;
}