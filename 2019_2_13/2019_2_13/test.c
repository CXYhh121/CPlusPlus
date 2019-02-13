#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
//main()
//{
//	int b = 10, a = -11;
//	a %= b %= 4;
//	printf("%d %d\n", a, b);
//}

//void main()
//{
//	char *p, *q;
//	p = (char *)malloc(sizeof (char)* 20); q = p;
//	scanf("%s%s", p, q); printf("%s %s\n", p, q);
//}

#include<stdio.h>
//main()
//{
//	char ch = 'A';
//	while (ch<'D')
//	{
//		printf("%d", ch - 'A');
//		ch++;
//	}
//	printf("\n");
//}


//int main()
//{
//	int a = 0, c = 0;
//	do
//	{
//		--c;
//		a = a - 1;
//	} while (a > 0);
//
//	printf("%d\n", c);
//}

//#define X 5 
//#define Y X + 1
//#define Z Y*X/2 
//void main()
//{
//	int a = Y;
//	printf("%d,%d", Z, --a);
//}

//int main()
//{
//	const char *p1 = "hello";
//	char *const p2 = "world";
//	p1++;
//	//p1[2] = 'w';
//	p2[2] = 'l';
//	//p2++;
//}

//#include < stdio.h>
//char * a = "you", b[] = "welcome # you # to # China!";
//main()
//{
//	int i, j = 0; char* p = ' ';
//	for (i = 0; b[i] != '\0'; i++)
//	{
//		if (*a == b[i])
//		{
//			p = &b[i];
//			for (j = 0; a[j] != '\0'; j++)
//			{
//				if (a[j] != *p)
//					break;
//				p++;
//			}
//			if (a[j] != '\0')
//				break;
//		}
//	}
//	printf("%s\n", p);
//}

//int main()
//{
//	int i = 5;
//	int j = 7;
//
//	printf("%d\n", i | j);
//}

//int main()
//{
//	int i = 10;
//	int j = 1;
//	const int *p1;//(1)
//	int const *p2 = &i; //(2)
//	p2 = &j;//(3)
//	int *const p3 = &i;//(4)
//	*p3 = 20;//(5)
//	//*p2 = 30;//(6)
//	//p3 = &j;//(7)
//	return 0;
//}

#include<stdio.h> 
void f(int n);
int main() {
	void f(int n);
	f(5);
}
void f(int n)
{
	printf("%d\n", n);
}
