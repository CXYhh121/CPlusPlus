#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//����������������ĸ�ֵת��
//class Person
//{
//protected:
//	string _name;//����
//	string _sex;//�Ա�
//	int _age;//����
//};
//
//class Student : public Person
//{
//public:
//	int Num;//ѧ��
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	p = s;//��������󴫸����࣬�и������Ƭ������
//	Person* pp = &s;//���������ĵ�ַ��������ָ�룬����
//	Person& rp = s;//��������󴫸���������ã�����
//	//s = p; //��������󴫸����࣬������
//	Student* ps1 = (Student*)pp;//������ָ��ǿ������ת��Ϊ����ָ�룬����
//
//	//��ʱps1ָ��������������ps1������������еĳ�ԱNum������Խ��
//	ps1->Num = 10;
//
//
//	pp = &p;
//	Student* ps2 = (Student*)pp;
//	//��ʱps2ָ����ǻ��������ps2����������������еĳ�ԱNum����Խ��
//	ps1->Num = 20;
//	return 0;
//}


//�̳��е�������
// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
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
	//b.fun();//��ʱ���벻ͨ������Ϊ�����������ĺ�������ͬ�������أ���ʱ�������޷����û����fun����
	b.A::fun();//��ʾָ��������
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
