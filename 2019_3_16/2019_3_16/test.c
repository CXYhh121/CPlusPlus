#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int func(int i)
//{
//	if (i > 1)
//		return i * func(i - 1);
//	else
//		return 1;
//}
//
//int main()
//{
//	int ret = func(5);
//	printf("%d\n", ret);
//	return 0;
//}

#include <stdio.h>
//int f1(int x)
//{
//	return x + 5;
//}
//int f2(int x)
//{
//	return 2 * x - 1;
//}
//main()
//{
//	int(*p1)(int), (*p2)(int), (*t)(int), y1, y2;
//	p1 = f1; p2 = f2;
//	y1 = p2(p1(1));
//	t = p1;
//	p1 = p2;
//	p2 = t;
//	y2 = p2(p1(2));
//	printf("%d, %d\n", y1, y2);
//}



//char fun(char x, char y)
//{
//	if (x)
//		return(y);
//}
//int main()
//{
//	int a = '¦È', b = '1', c = '2';
//	printf("%c\n", fun(fun(a, b), fun(b, c)));
//	return 0;
//}


//struct A
//{
//	char t : 4;
//	char k : 4;
//	unsigned short i : 8;
//	unsigned long m;
//}A;
//
//int main()
//{
//	printf("%d\n", sizeof(A));
//	return 0;
//}

//int main()
//{
//	char s[] = "123", *p;
//	p = s;
//	printf("%c%c%c\n", *p++, *p++, *p++);
//	return 0;
//}