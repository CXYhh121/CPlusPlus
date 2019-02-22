#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//class A{
//public:
//	virtual void f() { cout << "A::f() "; }
//	void f() const { cout << "A::f() const "; }
//};
//class B : public A {
//public:
//	void f() { cout << "B::f() "; }
//	void f() const { cout << "B::f() const "; }
//};
//void g(const A* a) {
//	a->f();
//}
//int main(int argc, char *argv[]) {
//	A* p = new B();
//	p->f();
//	g(p);
//	delete(p);
//	return 0;
//}


class CBase
{
public:
	CBase(){ cout << "constructing CBase class" << endl; }
	~CBase(){ cout << "destructing CBase class" << endl; }
};

class CSub : public CBase
{
public:
	CSub(){ cout << "constructing CSub class" << endl; }
	~CSub(){ cout << "destructing CSub class" << endl; }
};

void main()
{
	CSub obj;
}