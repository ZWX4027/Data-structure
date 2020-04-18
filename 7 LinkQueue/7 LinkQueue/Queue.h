typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;
typedef struct LQueue
{
	struct Node* phead;
	struct Node* ptail;
}LQueue,*pQue;

void init(pQue pqu);

Node* buyNode(ElemType val);
void enqueue(pQue pqu, ElemType val);

int empty(pQue pqu);
int dequeue(pQue pqu);

int front(pQue pqu);
int back(pQue pqu);

void clear(pQue pqu);
void destory(pQue pqu);


