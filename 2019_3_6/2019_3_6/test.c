#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//int main()
//{
//	char a[5][10] = { "one", "two", "three", "four", "five" };
//	int i, j;
//	char t;
//	for (i = 0; i<2; i++)
//	for (j = i + 1; j<5; j++)
//	if (a[i][0] >a[j][0])
//	{
//		t = a[i][0];
//		a[i][0] = a[j][0];
//		a[j][0] = t;
//	}
//	puts(a[1]);
//	return 0;
//}


//int main()
//{
//	char ch1, ch2, ch3;
//	scanf("%1c%2c%3c", &ch1, &ch2, &ch3);
//
//	printf("%1c%2c%3c\n", ch1, ch2, ch3);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int*p = NULL;
//	int a[] = { 1, 2, 3, 4 };
//	p = a;
//	*(p++) += 100;
//	printf("%d%d%d%d%d\n", *p, a[0], a[1], a[2], a[3]);
//
//	return 0;
//}


//void main()
//{
//	char ch[7] = ("65ab21");
//    int i, s = 0;
//	for (i = 0; ch[i] >= '0' && ch[i] <='9'; i += 2) 
//		s = 10 * s + ch[i] - '0';
//		printf("%d\n", s);
//}


int main()
{
	char* str[3] = { "stra", "strb", "strc" };
	char* p = str[0];
	int i = 0;
	while (i < 3)
	{
		printf("%s ", p++);
			++i;
	}

	return 0;
}