#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//class A
//{
//public:
//	int m;
//	int* p;
//};
//
//int main()
//{
//	A s;
//	s.m = 10;
//	cout << s.m << endl; //10
//	s.p = &s.m;
//	*s.p = 5;
//	cout << s.m << endl; //5
//	return 0;
//}


//友元函数和友元类
//#include<iostream>
//using namespace std;
//class MyClass
//{
//public:
//	MyClass(int i = 0)
//	{
//		cout << i;
//	}
//	MyClass(const MyClass &x)
//	{
//		cout << 2;
//	}
//	MyClass &operator=(const MyClass &x)
//	{
//		cout << 3;
//		return *this;
//	}
//	~MyClass()
//	{
//		cout << 4;
//	}
//};
//int main()
//{
//	MyClass obj1(1), obj2(2);
//	MyClass obj3 = obj1;
//	return 0;
//}



//class Radius
//{
//	friend class Circle;            //声明Circle为Radius的友元类
//	friend void Show_r(Radius &n);     //声明Show_r为友元函数
//public:
//	Radius(int x)
//	{
//		r = x;
//	}
//	~Radius(){}
//		
//private:
//	int r;
//};
//
//void Show_r(Radius &n)//友元函数可在类外定义，不用加关键字friend
//{
//	     cout << "圆的半径为: " << n.r << endl;    //调用Radius对象的私有成员变量r
//	 }
//
//class Circle
//{
// public:
//	 Circle(){}
//	~Circle(){}
//	 double area(Radius a)
//	 {
//		 s = a.r * a.r * 3.1415926;             //调用Radius对象的私有成员变量r
//		 return s;
//	 }
//private:
//	double s;
//};
//int main()
//{
//	Radius objRadius(9);
//	Circle objCircle;
//	Show_r(objRadius);
//	cout << "面积为：" << objCircle.area(objRadius) << endl;
//	
//	return 0;
//}



//一个函数可以被两个类声明为友元
//class Teacher;//只申明
//class Student
//{
//public:
//	friend bool is_equal(Student&,Teacher&);
//private:
//	int _sid;
//};
//
//class Teacher
//{
//public:
//	friend bool is_equal(Student&, Teacher&);
//private:
//	int _tid;
//};