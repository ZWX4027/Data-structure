#include<stdio.h>
#include"Queue.h"

int main()
{
	LQueue que;
	init(&que);
	for (int i = 1; i < 7; i++)
	{
		enqueue(&que, i);
	}
	printf("fr:%d\n", front(&que));
	printf("ba:%d\n", back(&que));

	dequeue(&que);
	enqueue(&que, 100);
	printf("fr:%d\n", front(&que));
	printf("ba:%d\n", back(&que));
	return 0;
}