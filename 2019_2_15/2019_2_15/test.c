#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//int main()
//{
//	char a[] = "programming", b[] = "language";
//	char *p1, *p2;
//	int i;
//	p1 = a, p2 = b;
//	for (i = 0; i<7; i++)
//	if (*(p1 + i) == *(p2 + i))
//		printf("%c", *(p1 + i));
//}

#include <stdio.h> 
//void main()
//{
//	int a = 1, b = 10;
//	do
//	{
//		b -= a; a++;
//	} while (b--<0);
//	printf("a=%d,b=%d\n", a, b);
//}

#include<stdint.h>
#include<stdio.h>

typedef union X
{
	int32_t a;
	struct
	{
		int16_t b;
		int16_t c;
	};
}X;

int main(){
	X x;
	x.a = 0x20150810;
	printf("%x,%x\n", x.b, x.c);
	return 0;
}