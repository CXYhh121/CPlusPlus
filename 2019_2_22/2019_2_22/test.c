#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int f(int n)
//{
//	if (n == 1) return 1;
//	else return f(n - 1) + 1;
//}
//void main()
//{
//	int i, j = 0;
//	for (i = 1; i < 3; i++)
//	{
//		j += f(i);
//	}
//		
//	printf("%d\n", j);
//	return 0;
//}

//int main()
//{
//	int x = 0, s = 0;
//	while (!x != 0) s += ++x;
//	printf("%d",s);
//	return 0;
//}

//int main()
//{
//	int a;
//	a = 'A' + 1.6;
//
//	printf("%d\n", a);
//	return 0;
//}

//void sub(int x, int y, int *z)
//{
//	*z = y - x;
//}
//void main()
//{
//	int a, b, c;
//	sub(10, 5, &a);
//	sub(7, a, &b);
//	sub(a, b, &c);
//	printf("%d,%d,%d\n", a, b, c);
//}

//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	case 1: b = 30;
//	case 2: b = 20;
//	case 3: b = 16;
//	default: b = 0;
//	}
//	return b;
//}
//
//int main()
//{
//	int ret = func(1);
//
//	printf("%d\n", ret);
//	return 0;
//
//}


//int main()
//{
//	const char* name = "chen";
//	name[3] = 'q';
//	name = "lin";
//
//	return 0;
//}

//main()
//{
//	int m = 7, n = 4;
//	float a = 38.4, b = 6.4, x;
//	x = m / 2 + n*a / b + 1 / 2;
//	printf("%f\n", x);
//}

//typedef struct list_t{
//	struct list_t *next;
//	struct list_t *prev;
//	char data[0];
//}list_t;
//
//int main()
//{
//	printf("%d\n", sizeof(list_t));
//	return 0;
//}


//int main(void)
//{
//	int i;
//	for (i = 0; i < 2; i++) {
//		fork();
//		printf("-");
//	}
//	return 0;
//}