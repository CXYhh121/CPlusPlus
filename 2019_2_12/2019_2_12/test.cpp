//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//void main()
//{
//	int k;
//	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	for (k = 0; k < 3; k++) 
//		printf("%d ", a[k][2 - k]);
//}

//#include <stdio.h> 
//void f(int x)
//{
//	if (x >= 10)
//	{
//		printf("%d - ", x % 10); f(x / 10);
//	}
//	else
//		printf(" % d", x);
//}
//main()
//{
//	int z = 123456;
//	f(z);
//}

//#include <iostream>
//using namespace std;
//
//
//void swap(int &a, int &b)
//{
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//	cout << a << "  " << b << "\n";
//}
//
//int main(){
//
//	int x = 1;
//	int y = 2;
//	swap(x, y);
//	cout << x << "  " << y << "\n";
//	return 0;
//}

#include<iostream>
using namespace std;
//int main()
//{
//	char c[2][5] = { "6938", "8254" }, *p[2];
//	int s = 0;
//	for (int i = 0; i < 2; i++)
//		p[i] = c[i];
//	for (int i = 0, j = 0; i <4; i++, j += 2)
//	{
//		if (j>3)
//		{
//			j = 0;
//		}
//		s = 10 * s + (p[i / 2][j] - '0');
//	}
//	cout << s << endl;
//	return 0;
//}

int function2(int a[], int b, int e)
{
	if (e - b <= 1) return abs(a[b] - a[e]) >= 3 ? a[b] : a[e];
	int l = 0, r = 0;
	l = function2(a, b, b + (e - b) / 2);
	if (l % 2 == 0)
		r = function2(a, b + (e - b) / 2 + 1, e);
	else
		return l;
	if (l | r)
		return l | r;
	else
		return r;
}

int main()
{
	int a[] = { 10, 5, 8, 4, 5, 20, 2, 3 };
	cout << function2(a, 0, sizeof(a) / sizeof(1)) << endl;
	int b[] = { 3, 5, 8, 4, 8, 30, 2, 3 };
	cout << function2(b, 0, sizeof(b) / sizeof(1)) << endl;
	return 0;
}