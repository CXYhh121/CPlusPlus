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


//��Ԫ��������Ԫ��
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
//	friend class Circle;            //����CircleΪRadius����Ԫ��
//	friend void Show_r(Radius &n);     //����Show_rΪ��Ԫ����
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
//void Show_r(Radius &n)//��Ԫ�����������ⶨ�壬���üӹؼ���friend
//{
//	     cout << "Բ�İ뾶Ϊ: " << n.r << endl;    //����Radius�����˽�г�Ա����r
//	 }
//
//class Circle
//{
// public:
//	 Circle(){}
//	~Circle(){}
//	 double area(Radius a)
//	 {
//		 s = a.r * a.r * 3.1415926;             //����Radius�����˽�г�Ա����r
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
//	cout << "���Ϊ��" << objCircle.area(objRadius) << endl;
//	
//	return 0;
//}



//һ���������Ա�����������Ϊ��Ԫ
//class Teacher;//ֻ����
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