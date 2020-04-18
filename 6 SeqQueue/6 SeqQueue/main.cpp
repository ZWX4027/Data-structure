#include<stdio.h>
#include"Queue.h"

int main()
{
	Queue qu;
	init(&qu);
	enqueue(&qu, 3);
	enqueue(&qu, 7);
	enqueue(&qu, 6); 
	enqueue(&qu, 4);
	enqueue(&qu, 2);
	int refront = front(&qu);
	printf("fr:%d\n", refront);
	int reback = back(&qu);
	printf("re:%d\n", reback);
	
	dequeue(&qu);

	refront = front(&qu);
	printf("fr:%d\n", refront);
	reback = back(&qu);
	printf("re:%d\n", reback);
	return 0;
}