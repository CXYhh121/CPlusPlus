#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int f()
//{
//	static int i = 0;
//	int s = 1;
//	s += i; i++;
//	return s;
//}
//main()
//{
//	int i, a = 0;
//	for (i = 0; i<5; i++)
//		a += f();
//	printf("%d\n", a);
//}

//#include<stdio.h>
//int inc(int a)
//{
//	return (++a);
//}
//int multi(int *a, int *b, int *c)
//{
//	return (*c = *a* *b);
//}
//typedef int(*FUNC1)(int in);
//typedef int(*FUNC2)(int*, int*, int*);
//void show(FUNC2 fun, int arg1, int *arg2)
//{
//	FUNC1 p = &inc;
//	int temp = p(arg1);
//	fun(&temp, &arg1, arg2);
//	printf("%d\n", *arg2);
//}
//int main()
//{
//	int a;
//	show(multi, 10, &a);
//	return 0;
//}