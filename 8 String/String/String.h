typedef struct String
{
	char*pstr;//��̬�����ڴ����洢����
	int totalsize;//����ǰ���ĳ���
	int cursize;//����ǰ����Ч����
}String,*pString;

void initString(pString ps);

void strAssign(pString ps, char* p);//���ַ���p�е����ݸ�ֵ����ps���ٵ��ڴ���

void strSub(pString ps, pString p1, pString p2);//��p1��p2�е����ݺϲ�����ps��

int BF(pString S, pString P);//����ƥ���㷨

void strPring(pString ps);//��ӡ��������

void destroy(pString ps);//����

