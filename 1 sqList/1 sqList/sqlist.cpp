#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sqlist.h"

//初始化
void InitSqList(PSqList ps)
{
	assert(ps != NULL);//笔试的时候一定要判断参数
	if (ps == NULL)//常量放在左边,变量放在右边是一个更好的风格
		return;

	ps->elem = (int *)malloc(INIT_SIZE*sizeof(int));
	assert(ps->elem != NULL);//可写可不写
	ps->lenght = 0;
	ps->listsize = INIT_SIZE;
}

//内部函数,判满
static  bool IsFull(PSqList ps)
{
	return ps->lenght == ps->listsize;
}

//扩容,总容量扩大到原来的2倍
//STL扩容1.5或者2倍都不一定
static void Inc(PSqList ps)
{
	ps->elem = (int *)realloc(ps->elem, ps->listsize * 2 * sizeof(int));
	//ps->length;//不变
	ps->listsize *= 2;
}

//向ps的pos位置插入数据val,顺序表要求必须连续
bool Insert(PSqList ps, int pos, int val)
{
	assert(ps != NULL);
	if (ps == NULL || pos<0 || pos>ps->lenght)
	{
		return false;
	}

	if (IsFull(ps))
	{
		Inc(ps);
	}

	//将后面的数据后移
	for (int i = ps->lenght - 1; i >= pos; i--)
	{
		ps->elem[i + 1] = ps->elem[i];
	}

	//将新数据插入
	ps->elem[pos] = val;

	//有效数据个数+1;
	ps->lenght++;

	return true;
}

//查找从头开始的第一个key,成功返回下标,失败返回-1
int Search(PSqList ps, int key)
{
	for (int i = 0; i<ps->lenght; i++)//无序数据
	{
		if (key == ps->elem[i])
		{
			return i;
		}
	}
	return -1;
}

//删除pos位置的值
bool DeletePos(PSqList ps, int pos)
{
	if (pos<0 || pos >= ps->lenght)
		return false;

	//将后面的数据往前移
	for (int i = pos; i<ps->lenght - 1; i++)
	{
		ps->elem[i] = ps->elem[i + 1];
	}

	ps->lenght--;

	return true;
}

//删除从头开始的第一个key
bool DeleteVal(PSqList ps, int key)
{
	int i = Search(ps, key);
	if (i < 0)
		return false;

	return DeletePos(ps, i);
}

//输出
void Show(PSqList ps)
{
	for (int i = 0; i<ps->lenght; i++)
	{
		printf("%d ", ps->elem[i]);
	}
	printf("\n");
}

//销毁
void Destroy(PSqList ps)
{
	assert(ps != NULL);
	free(ps->elem);
	ps->elem = NULL;
	ps->lenght = 0;
	ps->listsize = 0;
}