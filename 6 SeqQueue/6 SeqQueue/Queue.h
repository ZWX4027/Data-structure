typedef int ElemType;
#define MAX_SIZE 10

typedef struct Queue
{
	ElemType arr[MAX_SIZE];
	int front;//队头指针，存的是下标
	int rear;//队尾指针
}Queue,*pQueue;

void init(pQueue pqu);

int full(pQueue pqu);
int enqueue(pQueue pqu, ElemType val);

int empty(pQueue pqu);
int dequeue(pQueue pqu);

int front(pQueue pqu);
int back(pQueue pqu);
