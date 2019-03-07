#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//static int calc(int a, int b)
//{
//	if (a >= b)
//		return (a == b) ? a : b;
//	else
//		return a + b + calc(a + 2, b - 1);
//}
//
//int main()
//{
//	int ret = calc(2, 7);
//	printf("%d\n", ret);
//	return 0;
//}

//struct STU
//{
//	char num[10]; float score[3];
//};
//void main()
//{
//	struct STU s[3] = { { "20021", 90, 95, 85 },
//	{ "20022", 95, 80, 75 },
//	{ "20023", 100, 95, 90 } }, *p = s;
//	int i; float sum = 0;
//	for (i = 0; i < 3; i++)
//		sum = sum + p->score[i];
//	printf("%6.2f\n", sum);
//}

//int func(int x){
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x&(x - 1);//”Î‘ÀÀ„
//	}
//	return count;
//}
//
//int main()
//{
//	printf("%d\n",func(9999));
//	return 0;
//}

#include<stdio.h>
int main()
{
	unsigned char i = 7;
	int j = 0;
	for (; i>0; i -= 3)
	{
		++j;
	}
	printf("%d\n", j);
	return 0;
}