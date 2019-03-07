#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//int f(int n){
//	if (n == 1)
//		return 1;
//	else
//		return (f(n - 1) + n*n*n);
//}
//int main(){
//	int s = f(3);
//	cout << s << endl;
//	return 0;
//}


//
//void fut(int**s, int p[2][3]) {
//	**s = p[1][1];
//}
//int main() {
//	int a[2][3] = { 1, 3, 5, 7, 9, 11 }, *p;
//	p = (int*)malloc(sizeof(int));
//	fut(&p, a);
//	cout << *p;
//}
//
//int main()
//{
//	char* a[] = { "hello", "the", "world" };
//	char** pa = a;
//	pa++;
//	cout << *pa << endl;
//}


//#include<iostream>
//using namespace std;
//
//int f(int a)
//{
//	int b = 0;
//	static int c = 3;
//	a = c++, b++;
//	return (a);
//}
//int main()
//{
//	int a = 2, i, k;
//	for (i = 0; i < 2; i++)
//		k = f(a++);
//	printf(" % d\n", k);
//
//	return 0;
//}