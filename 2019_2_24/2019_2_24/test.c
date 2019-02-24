#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//int main()
//{
//	int n = 2;
//	int ret = n += n -= n*n;
//	printf("%d\n", ret);
//	return 0;
//}

//#include<stdio.h>
//#define N 4
//void fun(int a[][N], int *p)
//{
//	int i;
//	for (i = 0; i<N; i++) {
//		if (i<3) p[i] += a[i][i] - a[i][N - i - 2];
//		else p[i] += a[i][i] - a[i][N - i];
//	}
//}
//int main()
//{
//	int x[N][N] = { { 3, 6, 2, 0 }, { 2, 8, 7, 9 }, { 5, 1, 7, 3 }, { 9, 5, 3, 7 } }, y[N] = { 3, 5, 8, 6 }, i;
//	fun(x, y);
//	for (i = 0; i<N; i++)
//		printf("%d ", y[i]);
//	printf("\n");
//
//	return 0;
//}

//有M个串，长度都小于N
//#define M 5
//#define N 20
//int fun(char(*ss)[N], int *n)
//{
//	int i, k = 0, len = N;
//	for (i = 0; i < M; i++)
//	{
//		len = strlen(ss[i]);
//		if (i == 0)
//			*n = len;
//		if (len < *n)
//		{
//			*n = len;
//			k = i;
//		}
//	}
//	return (k);
//}
//main()
//{
//	char ss[M][N] = { "shanghai", "guangzhou", "beijing", "tianjing", "chongqing" };
//	int n, k, i;
//	printf("\nThe originalb stringsare:\n");
//	for (i = 0; i < M; i++)
//		puts(ss[i]);
//	k = fun(ss, &n);
//	printf("\nThe length of shortest string is: % d\n", n);
//	printf("\nThe shortest string is: % s\n", ss[k]);
//}
//

//int main()
//{
//	printf("\n");
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *p, **k;
//	p = a;
//	k = &p;
//	printf("%d", *(p++));
//	printf("%d", **k);
//	return 0;
//}

//int main(int argc, char**argv){
//	int a[4] = { 1, 2, 3, 4 };
//	int*ptr = (int*)(&a + 1);
//	printf("%d", *(ptr - 1));
//
//	return 0;
//}

void print_value(int* x)
{
	printf("%x\n", ++*x);
}

int main()
{
	int a = 25;
	print_value(&a);
	return 0;
}