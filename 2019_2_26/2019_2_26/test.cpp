#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;
//class A
//{
//	friend long fun(A s)
//	{
//		if (s.x<3) {
//			return 1;
//		}
//		return s.x + fun(A(s.x - 1));
//	}
//public:
//	A(long a)
//	{
//		x = a--;
//	}
//private:
//	long x;
//};

//int main()
//{
//	int sum = 0;
//	for (int i = 0; i<5; i++) {
//		sum += fun(A(i));
//	}
//	cout << sum;
//}

//class A {
//public:
//	int GetValue()  {
//		vv = 1;
//		return vv;
//	}
//private:
//	 int vv;
//};
//
//int main()
//{
//	class A a;
//	return 0;
//}


class A
{
	int a;
	short b;
	int c;
	char d;
};
class B
{
	double a;
	short b;
	int c;
	char d;
};

int main()
{
	printf("%d\n", sizeof(A));
	printf("%d\n", sizeof(B));

	return 0;
}
