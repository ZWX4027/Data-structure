#include<stdio.h>
#include"String.h"

int main()
{
	/*String str;
	initString(&str);
	strAssign(&str, "hello");
	strPring(&str);

	String str2;
	initString(&str2);
	strAssign(&str2, "hi");

	String str3;
	initString(&str3);
	strAssign(&str3, "world");

	strSub(&str, &str2, &str3);
	strPring(&str);*/

	String s;
	initString(&s);
	strAssign(&s, "HSIDABCFHABCD");
	strPring(&s);

	String p;
	initString(&p);
	strAssign(&p, "ABCD");
	strPring(&p);

	printf("%d\n",BF(&s, &p));

	return 0;
}