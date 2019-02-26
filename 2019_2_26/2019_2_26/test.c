#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//void f(int a[], int i, int j)
//{
//	int t;
//	if (i<j) 
//	{ 
//		t = a[i]; 
//		a[i] = a[j]; 
//		a[j] = t; 
//		f(a, i + 1, j - 1); 
//	}
//
//}
//
//void main()
//{
//	int i, a[5] = { 1, 2, 3, 4, 5 };
//	f(a, 0, 4);
//	for (i = 0; i < 5; i++) 
//		printf("%d, ", a[i]);
//
//	return 0;
//}

//#include<stdio.h>
//union uni
//{
//	int a;
//	char b;
//};
//struct str
//{
//	int a;
//	char b;
//};
//int main(int argc, char **argv)
//{
//	printf("%d %d\n", sizeof(union uni), sizeof(struct str));
//	return 0;
//}

#include <stdio.h>
//main()
//{
//	int c[6] = { 10, 20, 30, 40, 50, 60 }, *p, *s;
//	p = c;
//	s = &c[5];
//	printf("%d\n", s - p);
//	return 0;
//}


//int main()
//{
//	int a[3][3] = { { 3, 5 }, { 8, 9 }, { 12, 35 } }, i, sum = 0;
//	for (i = 0; i<3; i++) 
//		sum += a[i][2 - i];
//
//	printf("%d\n", sum);
//	return 0;
//}

//int main()
//{
//	int a = 3366;
//	printf("©¦%-08d©¦", a);
//
//	return 0;
//
//}

int main()
{
	for (int i = 10, j = 1; i = j = 0; i++, j--)
		printf("hehe");
	return 0;
}