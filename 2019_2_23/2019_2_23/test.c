#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//
//int main()
//
//{
//	int  a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, *p;
//	for (p = a; p<a + 10; p++)
//		printf("%d,", *p);
//
//	return 0;
//
//}

//int main()
//{
//	int j = -1;
//	if (j <= 1) printf("****\n");
//	else printf("%%%%\n");
//	return 0;
//}

//int main()
//{
//	int a = 7, b = 5;
//	printf("%d\n", b = b / a);
//	return 0;
//}

//int main()
//{
//	double d = 3.2;
//	int x, y; x = 1.2; 
//	y = (x + 3.8) / 5.0; 
//	printf("%d\n", d*y);
//	return 0;
//}

int main()
{
	signed char a = 0xe0;
	unsigned int b = a;
	unsigned char c = a;

	int ret = a > 0 && c > 0;
	int ret2 = a == c;

	printf("%d\n", ret);
	printf("%d\n", ret2);
	printf("%x\n", b);


	return 0;
}