typedef struct String
{
	char*pstr;//动态开辟内存来存储数据
	int totalsize;//串当前最大的长度
	int cursize;//串当前的有效长度
}String,*pString;

void initString(pString ps);

void strAssign(pString ps, char* p);//把字符串p中的数据赋值给串ps开辟的内存中

void strSub(pString ps, pString p1, pString p2);//把p1与p2中的数据合并存在ps中

int BF(pString S, pString P);//朴素匹配算法

void strPring(pString ps);//打印串中数据

void destroy(pString ps);//销毁

