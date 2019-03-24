#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Jack;
//	Func(Jack);
//	return 0;
//}


//虚函数重写中的例外，协变
//class A{};
//class B : public A {};
//class Person {
//public:
//	virtual A* f() { return new A; }
//};
//class Student : public Person {
//public:
//	virtual B* f() { return new B; }
//};
//
//void Func(Person& p)
//{
//	p.f();
//}
//int main()
//{
//	Person p;
//	Func(p);
//
//	Student s;
//
//	return 0;
//}




//析构函数声明为虚函数


//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	delete p1;
//	delete p2;
//
//	return 0;
//}


//抽象类
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}


// 1.final 修饰基类的虚函数不能被派生类重写
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};