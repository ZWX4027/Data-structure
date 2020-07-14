#include "sqlist.h"

int main()
{
	SqList sq;
	InitSqList(&sq);
	for (int i = 0; i<20; i++)
	{
		//Insert(&sq,i,i);
		Insert(&sq, 0, i);
	}

	DeleteVal(&sq, 5);
	Show(&sq);
	Destroy(&sq);
	Destroy(&sq);

	return 0;
}