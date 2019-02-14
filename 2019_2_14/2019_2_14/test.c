#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

//int main()
//{
//	/*char a[10];
//	char* p = a;
//	p = "china";*/
//
//	/*char* a;
//	a = "china";*/
//
//	//char a[10], *p;
//	//p = a = "china";
//	return 0;
//}

//main()
//{
//	int n;
//	for (n = 1; n <= 10; n++)
//	{
//		if (n % 3 == 0) continue;
//		printf("%d", n);
//	}
//}

//int a, b;
//void fun()
//{
//	a = 100;
//	b = 200;
//}
//main()
//{
//	int a = 5, b = 7;
//	fun();
//	printf(" % d % d \n", a, b);
//}

//int main()
//{
//	//const int *x = "hello";   //¢Ù
//	int * const x;   //¢Ú
//	++x;
//	++(*x);
//}

//int main()
//{
//	char a[7] = "abcde";  
//	char b[4] = "ABC";
//	strcpy(a, b);        
//	printf("%c", a[4]);
//
//	return 0;
//
//}

//int main()
//{
//	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, *p = a;
//
//	printf("%d\n", *(a + 5));
//	printf("%d\n", *(p + 5));
//	printf("%d\n", p[5]);
//	printf("%d\n", a[5]);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char c = '0';
//	printf("%d %d", sizeof(c), sizeof(char));
//	return 0;
//}

//#include <stdio.h>
//void s(int *a, int n)
//{
//	int i, j, t;
//	for (i = 0; i<n - 1; i++)
//	{
//		for (j = i + 1; j<n; j++){
//			if (*(a + i)<*(a + j))
//			{
//				t = a[i]; a[i] = a[j]; a[j] = t;
//			}
//		}
//	}
//}
//main()
//{
//	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, i;
//	s(a+4 , 6);
//	for (i = 0; i <= 9; i++)
//		printf("%d ", *(a + i));
//	printf("\n");
//}

//main()
//{
//	//swap(int* p, int* q);
//	int a = 10, b = 20;
//	printf("(1)a=%d,b=%d\n", a, b);
//	swap(&a, &b);
//	printf("(2)a=%d,b=%d\n", a, b);
//}
//swap(int* p, int* q){
//	int t;
//	t = p; p = q; q = t;
//}


int foo(int x)
{
	return x & -x;
}

int main()
{
	printf("%d\n",foo(2 ^ 31 - 3));
	return 0;
}

