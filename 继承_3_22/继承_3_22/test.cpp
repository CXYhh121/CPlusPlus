#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//基类和派生；类对象的赋值转换
//class Person
//{
//protected:
//	string _name;//姓名
//	string _sex;//性别
//	int _age;//年龄
//};
//
//class Student : public Person
//{
//public:
//	int Num;//学号
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	p = s;//将子类对象传给父类，切割或是切片，允许
//	Person* pp = &s;//将子类对象的地址传给父类指针，允许
//	Person& rp = s;//将子类对象传给父类的引用，允许
//	//s = p; //将父类对象传给子类，不允许
//	Student* ps1 = (Student*)pp;//将父类指针强制类型转换为子类指针，允许
//
//	//此时ps1指向的是子类对象，用ps1访问子类对象中的成员Num，不会越界
//	ps1->Num = 10;
//
//
//	pp = &p;
//	Student* ps2 = (Student*)pp;
//	//此时ps2指向的是基类对象，用ps2访问派生类类对象中的成员Num，会越界
//	ps1->Num = 20;
//	return 0;
//}


//继承中的作用域
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};
void Test()
{
	A a;
	B b;
	a.fun();
	//b.fun();//此时编译不通过，因为派生类与基类的函数名相同构成隐藏，此时派生类无法调用基类的fun函数
	b.A::fun();//显示指定是允许
	b.fun(10);
};
int main()
{
	Test();
	return 0;
}

//class A
//{
//public:
//	int _a;
//};
//class B : public A
////class B : virtual public A
//{
//public:
//	int _b;
//};
//
// class C : public A
////class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}
