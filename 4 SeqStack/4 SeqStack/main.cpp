#include<stdio.h>
#include"pStack_List.h"

int main()
{
	Stack st;
	init(&st);
	int i = 0;
	for (i; i < STACK_SIZE-1; i++)
	{
		push(&st, i);
	}
	int rt = 0;
	int flag = gettop(&st, &rt);
	if (flag)
	{
		printf("rt:%d\n", rt);
	}
	return 0;
} 