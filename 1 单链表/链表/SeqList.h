
typedef int ElemType;

typedef struct Node
{
	ElemType data;//������
	struct Node* Next;//ָ����
}Node, *pList;

void init(pList phead);//������������ʼ��ͷ���head����pheadͷָ�룩
//��������������void���ͣ�����ǷǷ�λ�ã����޷�����Ԫ�أ�
//����Ҫ��int���ͣ�����ֵ�������ղ����״̬�����Ƿ����ɹ�
Node* buyNode(ElemType val);//����һ���µĽ��(val����Ԫ��)
int insertHead(pList phead,ElemType val);//ͷ��:��Ԫ�ز���ͷ�ڵ�֮��
int insertTail(pList phead, ElemType val);//β�壺��Ԫ�ز������������β��
int getLength(pList phead);//�������ݽ��ĸ�����������ͷ���
int insertPos(pList phead,int pos, ElemType val);//��λ�ò���(pos����λ��)
//ɾ��������Ҫע���пգ����Ԫ��Ϊ�գ�����ɾ��
int Empty(pList phead);
int deleteHead(pList phead);//ͷɾ
int deleteTail(pList phead);//βɾ
int deletePos(pList phead,int pos);//��λ��ɾ��
void  Show(pList phead);//��ѯ������
void destroy(pList phead);//���������




