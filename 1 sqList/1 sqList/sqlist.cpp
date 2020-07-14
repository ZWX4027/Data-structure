#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sqlist.h"

//��ʼ��
void InitSqList(PSqList ps)
{
	assert(ps != NULL);//���Ե�ʱ��һ��Ҫ�жϲ���
	if (ps == NULL)//�����������,���������ұ���һ�����õķ��
		return;

	ps->elem = (int *)malloc(INIT_SIZE*sizeof(int));
	assert(ps->elem != NULL);//��д�ɲ�д
	ps->lenght = 0;
	ps->listsize = INIT_SIZE;
}

//�ڲ�����,����
static  bool IsFull(PSqList ps)
{
	return ps->lenght == ps->listsize;
}

//����,����������ԭ����2��
//STL����1.5����2������һ��
static void Inc(PSqList ps)
{
	ps->elem = (int *)realloc(ps->elem, ps->listsize * 2 * sizeof(int));
	//ps->length;//����
	ps->listsize *= 2;
}

//��ps��posλ�ò�������val,˳���Ҫ���������
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

	//����������ݺ���
	for (int i = ps->lenght - 1; i >= pos; i--)
	{
		ps->elem[i + 1] = ps->elem[i];
	}

	//�������ݲ���
	ps->elem[pos] = val;

	//��Ч���ݸ���+1;
	ps->lenght++;

	return true;
}

//���Ҵ�ͷ��ʼ�ĵ�һ��key,�ɹ������±�,ʧ�ܷ���-1
int Search(PSqList ps, int key)
{
	for (int i = 0; i<ps->lenght; i++)//��������
	{
		if (key == ps->elem[i])
		{
			return i;
		}
	}
	return -1;
}

//ɾ��posλ�õ�ֵ
bool DeletePos(PSqList ps, int pos)
{
	if (pos<0 || pos >= ps->lenght)
		return false;

	//�������������ǰ��
	for (int i = pos; i<ps->lenght - 1; i++)
	{
		ps->elem[i] = ps->elem[i + 1];
	}

	ps->lenght--;

	return true;
}

//ɾ����ͷ��ʼ�ĵ�һ��key
bool DeleteVal(PSqList ps, int key)
{
	int i = Search(ps, key);
	if (i < 0)
		return false;

	return DeletePos(ps, i);
}

//���
void Show(PSqList ps)
{
	for (int i = 0; i<ps->lenght; i++)
	{
		printf("%d ", ps->elem[i]);
	}
	printf("\n");
}

//����
void Destroy(PSqList ps)
{
	assert(ps != NULL);
	free(ps->elem);
	ps->elem = NULL;
	ps->lenght = 0;
	ps->listsize = 0;
}