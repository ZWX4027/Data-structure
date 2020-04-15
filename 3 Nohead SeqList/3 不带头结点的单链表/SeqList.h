typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*pList;

void init(Node** phead);

Node* buyNode(ElemType val);
int insertHead(pList* phead, ElemType val);
int insertTail(pList* phead, ElemType val);

int empty(Node* phead);
int deleteHead(pList* ptwohead);
int deleteTail(pList* ptwohead);

void Show(Node* phead);
void destroy(pList* ptwohead);


