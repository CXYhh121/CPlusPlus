#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//int main(void)
//{
//	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, *p = a + 3;
//	printf("%d", *++p);
//	return 0;
//}


//int f(int a)
//{
//	return a % 2;
//}
//int main()
//{
//	int s[8] = { 1, 3, 5, 2, 4, 6 }, i, d = 0;
//	for(i = 0; f(s[i]); i++) 
//		d += s[i];
//	printf("%d\n", d);
//	return 0;
//}
//


//int main()
//{
//	int a[2][2] = { { 1 }, { 2, 3 } };
//
//	printf("%d\n", a[0][1]);
//	return 0;
//}

//int main()
//{
//	int p, i;
//	/*for (i = 1,p = 1; i <= 5; i++)
//	{
//		p *= i;
//	}*/
//	/*for (i = 1; i <= 5; i++)
//	{
//		p = 1;
//		p *= i;
//	}*/
//
//	/*i = 1;
//	p = 1;
//	while (i <= 5)
//	{
//		p *= i;
//		++i;
//	}*/
//
//	i = 1;
//	p = 1;
//	do{
//		p *= i;
//		++i;
//	} while (i <= 5);
//
//	printf("%d\n", p);
//	return 0;
//}

//
//#include <stdio.h>
//main(){
//	int x = 35, B;
//	char z = 'B';
//	B = ((x) && (z <'b'));
//	printf("%d\n", B);
//}

#include <stdio.h>
#include <stdlib.h>
void fun(int *pl, int *p2, int *s)
{
	s =(int*) malloc(sizeof(int));
	*s = *pl + *(p2++);
}
main()
{
	int a[2] = { 1, 2 }, b[2] = { 10, 20 }, *s = a;
	fun(a, b, s);
	printf("%d \n", *s);

	return 0;
}