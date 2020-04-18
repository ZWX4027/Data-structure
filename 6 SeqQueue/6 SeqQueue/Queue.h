typedef int ElemType;
#define MAX_SIZE 10

typedef struct Queue
{
	ElemType arr[MAX_SIZE];
	int front;//��ͷָ�룬������±�
	int rear;//��βָ��
}Queue,*pQueue;

void init(pQueue pqu);

int full(pQueue pqu);
int enqueue(pQueue pqu, ElemType val);

int empty(pQueue pqu);
int dequeue(pQueue pqu);

int front(pQueue pqu);
int back(pQueue pqu);
