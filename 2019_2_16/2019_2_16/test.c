#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//#define ADD (x) x+x
//void main()
//{
//	int m = 1, n = 2, k = 3;
//		int sum = ADD(m + n)*k;
//	printf("sum=%d", sum);
//}
//#include <stdio.h>
//
//void fork()
//{
//
//}
//
//int main() {
//	printf("Hello");
//	fork();
//	printf("Hello");
//}


//int main()
//{
//	printf("%d\n", strlen("abcde\n"));
//	return 0;
//}

//main()
//{
//	int a = 9;
//	a += a -= a + a;
//	printf("%d\n", a);
//}

void main(void)
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
}