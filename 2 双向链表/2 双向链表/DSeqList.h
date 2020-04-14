typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* prev;
	struct Node* next;
}Node, *DPList;

void init(DPList plist);//�����������ֻ����Node head������Ҫ������ǰ���ͺ�̽��д���
//����
Node* buyNode(ElemType val);//����һ���½��
int insertHead(DPList plist, ElemType val);//ͷ��
int insertTail(DPList plist, ElemType val);//β��
int getLength(DPList plist);
int insertPos(DPList plist, int pos, ElemType val);//��λ�ò���
//ɾ��
int empty(DPList plist);//�п�
int deleteHead(DPList plist);//ͷɾ
int deleteTail(DPList plist); //βɾ
int deletePos(DPList plist, int pos);//��λ��ɾ��

void Show(DPList plist);

void destroy(DPList plist);
