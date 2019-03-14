#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
//main()
//{
//	char c[2][5] = { "6934", "8254" }, *p[2];
//	int i, j, s = 0;
//	for (i = 0; i<2; i++)
//		p[i] = c[i];
//	for (i = 0; i<2; i++)
//	for (j = 0; p[i][j]>0 && p[i][j] <= '9'; j += 2)
//		s = 10 * s + p[i][j] - '0';
//	printf("%d\n", s);
//}


//void f(int *p)
//{
//	*p = 5;
//}
//int main(void)
//{
//	int a, *p;
//	a = 10;
//	p = &a;
//	f(p);
//	printf("%d", (*p)++);
//	return 0;
//}


#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a = -3;
	unsigned int b = 2;
	long c = a + b;
	printf("%ld\n", c);
}
