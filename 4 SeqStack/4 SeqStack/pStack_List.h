typedef int ElemType;
#define STACK_SIZE 10

typedef struct Stack
{
	ElemType data[STACK_SIZE];//data为栈数据空间
	int top;//top为栈顶元素
}Stack, *pStack;

void init(pStack pst);

int full(pStack pst);
int push(pStack pst, ElemType val);

int empty(pStack pst);
int pop(pStack pst);

int gettop(pStack pst, ElemType* prt);

