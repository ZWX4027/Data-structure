#include<stdio.h>
#include"SeqList.h"
//#include<stdlib.h>

int main()
{
	Node head;
	int i = 1;
	init(&head);//≥ı ºªØ
	for (i; i < 9; i++)
	{
		insertHead(&head,i);
	}
	Show(&head);

	/*insertTail(&head, 6);
	Show(&head);*/

	/*insertPos(&head,3, 100);
	Show(&head);*/

	/*deleteHead(&head);
	Show(&head);*/

	/*deleteTail(&head);
	Show(&head);*/

	/*deletePos(&head,2);
	Show(&head);*/
	
	destroy(&head);
	return 0;
}