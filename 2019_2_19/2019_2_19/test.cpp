#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//class A
//{
//public:
//	A(int aa, int bb)
//	{ a = aa--; b = a*bb; }
//
//	void display()
//	{
//		cout << a << endl;
//		cout << b << endl;
//	}
//
//private:
//	int a;
//	int b;
//};
//
//int main()
//{
//	A x(4, 5);
//	x.display();
//	return 0;
//}
//
//void main()
//{
//	int a = 1, b = 0, c = -1, d = 0;
//	d = ++a || ++b&&++c;
//	cout << d << endl;
//	return;
//}



class C
{
public:
	char a;
	static char b;
	void *p;
	static int *c;
	virtual void func1();
	virtual void func2();
};

int main()
{

	printf("%d\n", sizeof(C));
	return 0;
}