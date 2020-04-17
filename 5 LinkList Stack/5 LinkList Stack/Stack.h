typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,Stack, *pStack;

void init(pStack pst);

Node* buyNode(ElemType val);
void push(pStack pst, ElemType val);

int empty(pStack pst);
int pop(pStack pst);

int gettop(pStack pst, ElemType* prt);
void destory(pStack pst);