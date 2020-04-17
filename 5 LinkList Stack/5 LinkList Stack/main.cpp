#include<stdio.h>
#include"Stack.h"

int main()
{
	Stack st;
	init(&st);
	int i = 0;
	for (i; i < 5; i++)
	{
		push(&st, i);
	}
	int rt = 0;
	int flag = gettop(&st, &rt);
	if (flag)
	{
			printf("%d\n", rt);
			pop(&st);
	}
	return 0;
}