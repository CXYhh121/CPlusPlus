#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <math.h>
//void Shaixuan()
//{
//
//	int i, j, n, a[101];
//	for (i = 1; i <= 100; i++)
//		a[i] = i;
//	a[1] = 0;
//	for (i = 2; i<sqrt(100); i++)
//	for (j = i + 1; j <= 100; j++)
//	{
//		if (a[i] != 0 && a[j] != 0)
//		if (a[j] % a[i] == 0)
//			a[j] = 0;
//	}
//	printf("\n");
//	for (i = 2, n = 0; i <= 100; i++)
//	{
//		if (a[i] != 0)
//		{
//			printf("%5d", a[i]);
//			n++;
//		}
//		if (n == 10)
//		{
//			printf("\n");
//			n = 0;
//		}
//	}
//	printf("\n");
//}
//
//int main()
//{
//	Shaixuan();
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//void Func(char str_arg[100])
//{
//	printf("%d\n", sizeof(str_arg));
//}
//int main(void)
//{
//	char str[] = "Hello";
//	printf("%d\n", sizeof(str));
//	printf("%d\n", strlen(str));
//	char*p = str;
//	printf("%d\n", sizeof(p));
//	Func(str);
//}


//#include<stdio.h>
//#define N 9
//int fun(int a[], int n)
//{
//	int i, j;
//	j = 0;
//	for (i = 0; i<n; i++)
//		/**********found**********/
//	if (a[i] % 2 == 1)
//	{
//		/**********found**********/
//		a[j] = a[i];
//		j++;
//	}
//	/**********found**********/
//	return j;
//}
//main()
//{
//	int b[N] = { 9, 1, 4, 2, 3, 6, 5, 8, 7 }, i, n;
//	printf("\nThe original data:\n");
//	for (i = 0; i<N; i++)
//		printf("% 4d", b[i]);
//	printf("\n");
//	n = fun(b, N);
//	printf("\nThe number of odd:% d\n", n);
//	printf("\nThe odd number: \n");
//	for (i = 0; i<n; i++)
//		printf("%4d", b[i]);
//	printf("\n");
//}


#include <stdio.h>
//void fun(int *s)
//{
//	static int j = 0;
//	do {
//		s[j] += s[j + 1];
//	} while (++j < 2);
//}
//main()
//{
//	int i, a[10] = { 1, 2, 3, 4, 5 };
//	for (i = 1; i < 3; i++) 
//		fun(a);
//	for (i = 1; i < 5; i++)
//		printf("%d", a[i]);
//	printf("\n");
//}

//int main()
//{
//	char*a[] = { "work", "at", "alibaba" };
//	char**pa = a;
//	pa++;
//	printf("%s", *pa);
//	return 0;
//}


void GetMemory(char *p)
{
	p = (char *)malloc(100);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}

int main()
{
	Test();
	return 0;

}
