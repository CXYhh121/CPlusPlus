#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//int main()
//{
//	int a = 0;
//
//	a += (a = 8);
//
//	printf("%d\n", a);
//	return 0;
//}

//void  main()
//{
//	int x = 0, y = 5, z = 3;
//	while (z-->0 && ++x<5)
//	{
//		y = y - 1;
//	}
//	printf("%d, %d, %d\n", x, y, z);
//	return 0;
//}

//#include <stdio.h> 
//void main()
//{
//	int y = 10;
//	do { y--; } while (--y);
//	printf("%d\n", y--);
//}


#include <stdio.h>
int fun3(int x)
{
	static int a = 2;
	a += x;
	return(a);
}
void main()
{
	int k = 2, m = 1, n;
	n = fun3(k);
	n += fun3(m);
	printf("%d\n", n);
}