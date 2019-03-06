#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class A
{
public:
	virtual void print()
	{
		cout << "A::print()" << "\n";
	}
};
class B : public A
{
public: virtual void print()
{
			cout << "B::print()" << "\n";
}
};
class C : public A
{
public: virtual void print()
{
			cout << "C::print()" << "\n";
}
};
void print(A a)
{
	a.print();
}
int main()
{
	A a, *aa, *ab, *ac;
	B b;
	C c;
	aa = &a;
	ab = &b;
	ac = &c;
	a.print();
	b.print();
	c.print();
	aa->print();
	ab->print();
	ac->print();
	print(a);
	print(b);
	print(c);
}