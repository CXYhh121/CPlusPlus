#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//实现一个不能被继承的类C++98
//class Person
//{
//public:
//	static Person GetPerson()
//	{
//		return Person();
//	}
//private:
//	Person()
//	{}
//	int _a;
//};
//
//class Student : public Person
//{
//private:
//	int _b;
//};
//
//int main()
//{
//	Student s;
//	return 0;
//}


//class Person final
//{
//private:
//	int _a;
//};
//
//class Student : class Person
//{
//
//private:
//	int _b;
//};



//class Base1 {
//public:
//	int _b1;
//};
//class Base2 {
//public:
//	int _b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	int _d;
//};
//int main()
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}


//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//	void Func2()
//	{
//		cout << "Func2" << endl;
//	}
//private:
//	int _b = 1;
//};////int main()//{//	Base b;//	printf("%d\n", sizeof(Base));//	return 0;//}//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	printf("Base:%d\n", sizeof(Base));
//	printf("Derive:%d\n", sizeof(Derive));
//
//	return 0;
//}

