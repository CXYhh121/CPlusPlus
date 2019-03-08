#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	int a = 5, b = 4, c = 3, d;
//	d = (a>b>c);
//	printf("%d\n", d);
//
//	return 0;
//}


//int fun(int a)
//{
//	a = (1 << 5) - 1;
//	return a;
//}
//
//int main()
//{
//	int ret = fun(21);
//	printf("%d\n", ret);
//	return 0;
//}


//int main()
//{
//	int a = 3, b = 4, c = 5, d = 2;
//	if (a>b)
//	if (b>c)
//		printf("%d", d++ + 1);
//	else
//		printf("%d", ++d + 1);
//
//	printf("%d\n", d);
//	return 0;
//}


//#include <stdio.h>
//main()
//{
//	int a = 0, b = 0, c = 0, d;
//	c = (a += b, , b += a); /// *第4行 * /
//		d = c; /// *第5行 * /
//		; /// *第6行 * /
//		; printf("%d,%d,%d\n", a, b, c); /// *第7行 * /
//}

//struct mybitfields
//{
//	unsigned short a : 4;
//	unsigned short b : 5;
//	unsigned short c : 7;
//}test;
//
//void main(void)
//{
//	int i;
//	test.a = 2;
//	test.b = 3;
//	test.c = 0;
//
//	i = *((short *)&test);
//	printf("%d\n", i);
//}