#pragma once //
//不定长顺序表
typedef struct SqList
{
	int *elem;//保存动态内存的地址
	int lenght;//有效数据个数
	int listsize;//总格子数
}SqList, *PSqList;

//顺序表优点:1.简单;2.查找方便;3.存储数据密度大;4.不频繁申请或者释放内存,没有内存碎片的问题

#define INIT_SIZE 10

//初始化
void InitSqList(PSqList ps);

//向ps的pos位置插入数据val,顺序表要求必须连续
bool Insert(PSqList ps, int pos, int val);

//查找从头开始的第一个key,成功返回下标,失败返回-1
int Search(PSqList ps, int key);

//删除pos位置的值
bool DeletePos(PSqList ps, int pos);

//删除从头开始的第一个key
bool DeleteVal(PSqList ps, int key);

//输出
void Show(PSqList ps);

//销毁
void Destroy(PSqList ps);