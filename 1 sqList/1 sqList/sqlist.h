#pragma once //
//������˳���
typedef struct SqList
{
	int *elem;//���涯̬�ڴ�ĵ�ַ
	int lenght;//��Ч���ݸ���
	int listsize;//�ܸ�����
}SqList, *PSqList;

//˳����ŵ�:1.��;2.���ҷ���;3.�洢�����ܶȴ�;4.��Ƶ����������ͷ��ڴ�,û���ڴ���Ƭ������

#define INIT_SIZE 10

//��ʼ��
void InitSqList(PSqList ps);

//��ps��posλ�ò�������val,˳���Ҫ���������
bool Insert(PSqList ps, int pos, int val);

//���Ҵ�ͷ��ʼ�ĵ�һ��key,�ɹ������±�,ʧ�ܷ���-1
int Search(PSqList ps, int key);

//ɾ��posλ�õ�ֵ
bool DeletePos(PSqList ps, int pos);

//ɾ����ͷ��ʼ�ĵ�һ��key
bool DeleteVal(PSqList ps, int key);

//���
void Show(PSqList ps);

//����
void Destroy(PSqList ps);