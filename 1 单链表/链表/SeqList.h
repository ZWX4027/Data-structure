
typedef int ElemType;

typedef struct Node
{
	ElemType data;//数据域
	struct Node* Next;//指针域
}Node, *pList;

void init(pList phead);//创建单链表，初始化头结点head，（phead头指针）
//插入操作：如果是void类型，如果是非法位置，则无法插入元素，
//所以要用int类型，返回值用来接收插入的状态，看是否插入成功
Node* buyNode(ElemType val);//生成一个新的结点(val插入元素)
int insertHead(pList phead,ElemType val);//头插:将元素插入头节点之后
int insertTail(pList phead, ElemType val);//尾插：将元素插入整个链表的尾部
int getLength(pList phead);//计算数据结点的个数，不包含头结点
int insertPos(pList phead,int pos, ElemType val);//按位置插入(pos插入位置)
//删除操作：要注意判空，如果元素为空，则不能删除
int Empty(pList phead);
int deleteHead(pList phead);//头删
int deleteTail(pList phead);//尾删
int deletePos(pList phead,int pos);//按位置删除
void  Show(pList phead);//查询单链表
void destroy(pList phead);//链表的销毁




