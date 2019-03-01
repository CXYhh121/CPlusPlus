#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//char fun(char *c)
//{
//	if (*c <= 'Z'&& *c >= 'A') *c -= 'A' - 'a'; return *c;
//}
//main()
//{
//	char s[81], *p = s;
//	gets(s);
//	while (*p)
//	{
//		*p = fun(p);
//		putchar(*p);
//		p++;
//	}
//	printf("\n");
//	return 0;
//}

#include <stdio.h>

//int func(unsigned int v)
//{
//	v ^= v >> 16;
//	v ^= v >> 8;
//	v ^= v >> 4;
//	v &= 0xf;
//	return (0x6996 >> v) & 1;
//}
//
//int funb(int n)
//{
//	unsigned int t = 1 << n;
//	int val = 0;
//	for (int i = 0; i < t; ++i)
//	{
//		val += func(i);
//	}
//	return val;
//}
//int main()
//{
//	int n = 10;
//	int ret = funb(n);
//	printf("%d\n", ret);
//	return 0;
//}
//int a = 0;
//
//void foo() {
//	if (a <= 0) {
//		a++;
//	}
//	else {
//		a--;
//	}
//	printf("%d", a);
//}
//
//int main()
//{
//	foo();
//	return 0;
//}


//int main()
//{
//	int x, y, z;
//		scanf("%d%d%d", &x, &y, &z);
//	printf("x+y+z=%d\n", x + y + z);
//}

#include <stdio.h>
#define SUB(x,y) x-y
#define ACCESS_BEFORE(element,offset,value)  *SUB(&element, offset) = value
int main() {
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i;
	//ACCESS_BEFORE(array[5], 4, 6);
	printf("array: ");
	for (i = 0; i < 10; ++i) {
		printf("%d", array[i]);
	}
	printf("\n");
	return (0);
}