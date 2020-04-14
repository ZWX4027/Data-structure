#include <stdio.h>
#include "DSeqList.h"

int main()
{
	Node head;
	init(&head);
	for (int i = 1; i < 8;i++)
	{
		insertHead(&head, i );
	}
	Show(&head);

	/*insertTail(&head, 8);
	Show(&head);*/
	
	/*insertPos(&head, 5, 100);
	Show(&head);*/

	/*deleteHead(&head);
	Show(&head);*/

	/*deleteTail(&head);
	Show(&head);*/

	/*deletePos(&head, 5);
	Show(&head);*/

	destroy(&head);
	return 0;
}