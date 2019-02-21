#include <stdio.h>

//void main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 }, b[5] = { 0, 2, 1, 3, 0 }, i, s = 0;
//	for (i = 0; i < 5; i++) s += a[b[i]];
//	printf("%d\n", s);
//}


//int main()
//{
//	int y = 2;
//	while (y <= 8)
//		y = y + y;
//
//	printf("%d\n", y);
//	return 0;
//}

//int miracle(unsigned int n)
//{
//	int m = n == 0 ? 0 : 1;
//	while (n = (n&(n - 1)))
//	{
//		m++;
//	}
//	return m;
//}
//
//int main()
//{
//	unsigned int n = 7;
//	int ret = miracle(n);
//	printf("%d\n", ret);
//	return 0;
//}

//#define N 2
//#define M N+1
//#define NUM  (M+1)*M/2
//
//int main()
//{
//
//	printf("%d\n", NUM);
//	return 0;
//}

//main(){
//	char str[] = "Geneius";
//	print(str);
//}
//print(char *s){
//	if (*s){
//		print(++s);
//		printf("%c", *s);
//	}
//}

//#include <stdio.h>
//int fun(int x)
//{
//	int p;
//	if (x == 0 || x == 1)
//		return(3);
//	p = x - fun(x - 2);
//	return(p);
//}
//main()
//{
//	printf("%d\n", fun(9));
//	return 0;
//}


//#include <stdio.h>
//main()
//{
//	int i;
//	int sum = 0;
//	for (i = 1; i < 6; i++) sum += i;
//	printf("%d\n", sum);
//	return 0;
//}
//


//#include<stdio.h>
//void add(int *p)
//{
//	(*p)++;
//	printf("%d", *p);
//	if (*p>5)
//	{
//		return;
//	}
//	add(p);
//}
//int main()
//{
//	int i = 0;
//	add(&i);
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 32;
//	printf("%d,%d", a << b, 1 << 32);
//	return 0;
//}

void main()
{
	long y = -43456;
		printf("y=©¦%-8ld©¦ y=©¦%-08ld©¦ y=©¦%08ldl©¦y=©¦%+8ld©¦", y, y, y, y);

		return 0;
}
