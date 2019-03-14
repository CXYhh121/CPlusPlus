#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//int WhoAmin(int num1, int num2)
//{
//	if (num2 == 0)
//		return num1;
//	
//	int num = num1 ^ num2;
//	int carry = (num1 & num2) << 1;
//
//	return WhoAmin(num, carry);
//}
//
//int main()
//{
//	cout << WhoAmin(5, 6) << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class TestClass{
//	char x;
//public:
//	TestClass() { cout << 'A'; }
//	TestClass(char c) { cout << c; }
//	~TestClass() { cout << 'B'; }
//};
//int main() {
//	TestClass p1, *p2;
//	p2 = new TestClass('X');
//	delete p2;
//	return 0;
//}


class A
{
public:
	virtual void func(int val = 1)
	{
		std::cout << "A->" << val << std::endl;
	}
	virtual void test()
	{
		func();
	}
};
class B : public A
{
public:
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;
	}
};
int main(int argc, char* argv[])
{
	B*p = new B;
	p->test();
	return 0;
}