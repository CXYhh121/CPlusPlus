#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//class A{
//};
//class B{
//	char ch;
//	int x;
//};
//class C{
//public:
//	void Print(void){}
//};
//class D
//{
//public:
//	virtual void Print(void){}
//};
//
//int main()
//{
//	printf("%d\n", sizeof(A));
//	printf("%d\n", sizeof(B));
//	printf("%d\n", sizeof(C));
//	printf("%d\n", sizeof(D));
//
//
//	return 0;
//}

//char *f(char *str, char ch)
//{
//	char *it1 = str;
//	char *it2 = str;
//	while (*it2 != '\0')
//	{
//		while (*it2 == ch)
//		{
//			it2++;
//		}
//		*it1++ = *it2++;
//	}
//	return str;
//}
//
//int main()
//{
//	char *a = new char[10];
//	strcpy(a, "abcdcccd");
//	cout << f(a, 'c');
//	return 0;
//}

class Test {
public:
	int a;
	static int b;
public:
	Test::Test(int _a, int _b) : a(_a) {
		b = _b;
	}
};
int Test::b;
int _tmain(int argc, char *argv[]) {
	Test t1(0, 0), t2(1, 1);
	t1.b = 10;
	t2.b = 20;
	printf("%u %u %u %u", t1.a, t1.b, t2.a, t2.b);
}