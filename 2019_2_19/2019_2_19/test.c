#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//#define add(a,b) a+b
//int main()
//{
//	printf("%d\n", 5 * add(3, 4));
//	return 0;
//}


//typedef struct s1 {
//	char ch, *ptr;
//	union {
//		short a, b;
//		unsigned int c : 2, d : 1;
//	};
//	struct s1 *next;
//}s1;
//
//int main()
//{
//	printf("%d\n", sizeof(s1));
//	return 0;
//}
//

//#include<stdio.h>
//int main(void)
//{
//	int x[5] = { 2, 4, 6, 8, 10 }, *p;  int(*pp)[5];
//	p = x;
//	pp = &x;
//	printf("%d\n", *(p++));
//	printf("%d\n", *pp);
//}


//#include <stdio.h> 
//char *a = " you";
//char b[] = " Welcome you to China!";
//main()
//{
//	int i, j = 0; char * p;
//	for (i = 0; b[i] != '\0'; i++)
//	{
//		if (*a == b[i])
//		{
//			p = a;
//			for (j = i; *p != '\0'; j++)
//			{
//				if (*p != b[j]) break;
//				p++;
//			}
//			if (*p == '\0')
//				break;
//		}
//	}
//	printf("%s", &b[i]);
//}



//#include<stdio.h>
//main()
//{
//	int s = 0, n;
//	for (n = 0; n<4; n++)
//	{
//		switch (n)
//		{
//		default:s += 4;
//		case 1:s += 1; break;
//		case 2:s += 2; break;
//		case 3:s += 3;
//		}
//	}
//	printf("%d\n", s);
//}


//typedef union X{
//	int x;
//	char y[4];
//}X;
//
//int main()
//{
//
//	X a;
//	a.x = 0x11223344;//16
//
//	printf("%x\n", a.y[0]);
//	return 0;
//}

int ADD(int x, int y)
{
	return x + y;
}
int main()
{
	int a = 3;
	int b = 4;
	int c = ADD(a, b);
	return 0;
}