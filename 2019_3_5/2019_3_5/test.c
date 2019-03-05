#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	int *b = a;
//	*b += 2;
//	*(b + 2) = 2;
//	b++;
//	printf("%d, %d\n", *b, *(b + 2));
//	return 0;
//}


//#include <stdio.h>
//main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, }, *p = a + 5, *q = NULL;
//	*q = *(p + 5);
//	printf("%d %d\n", *p, *q);
//	return 0;
//}

#include <string.h>

int main()
{
	//在内存中\07被转换为\a,此时用strlen求字符串的长度为9
	char a[80] = " 0123\0789 ";

	printf("%d\n", sizeof(a));
	printf("%d\n", strlen(a));
	return 0;
}