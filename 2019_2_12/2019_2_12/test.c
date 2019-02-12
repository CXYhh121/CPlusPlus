#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	uint32_t a = 100;
//	while (a>0)
//	{
//		--a;
//	}
//	printf("%d", a);
//	return 0;
//}

#include<stdio.h>
#include<string.h>
struct STU
{
	char name[10];
	int num;
};
void f(char* name, int num)
{
	struct STU s[2] = { { "SS", 10001 }, { "PP", 10002 } };
	num = s[1].num;
	strcpy(name, s[1].name);
}
main()
{
	struct STU  s[2] = { { "YY", 10003 }, { "LL", 10004 } }, *p;
	p = s;
	f(p->name, p->num);
	printf("%s %d\n", p->name, p->num);
}
