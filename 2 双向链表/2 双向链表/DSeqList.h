typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* prev;
	struct Node* next;
}Node, *DPList;

void init(DPList plist);//如果主函数中只存在Node head，则需要对它的前驱和后继进行处理
//插入
Node* buyNode(ElemType val);//创建一个新结点
int insertHead(DPList plist, ElemType val);//头插
int insertTail(DPList plist, ElemType val);//尾插
int getLength(DPList plist);
int insertPos(DPList plist, int pos, ElemType val);//按位置插入
//删除
int empty(DPList plist);//判空
int deleteHead(DPList plist);//头删
int deleteTail(DPList plist); //尾删
int deletePos(DPList plist, int pos);//按位置删除

void Show(DPList plist);

void destroy(DPList plist);
