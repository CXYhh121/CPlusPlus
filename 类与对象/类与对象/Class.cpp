//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	// 1.�޲ι��캯��
//	Date()
//	{}
//
//	// 2.���ι��캯��
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//3����ȱʡֵ�Ĺ��캯��
//	Date(int year = 2019, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1; // �����޲ι��캯��,ϵͳ����Ĭ��ֵ
//	Date d2(2015, 1, 1); // ���ô��εĹ��캯�����������ʼ��Ϊ2015-1-1
//	Date d3;//���ô�ȱʡֵ�Ĺ��캯���������ʼ��Ϊ2019-1-1
//
//	return 0;
//}
//
#include<iostream>
using namespace std;
//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//class Person
//{
//private:
//	String _name;
//	int _age;//Ĭ�������������ᴦ���������͵ĳ�Ա����
//};
//int main()
//{
//	Person p;
//	return 0;
//}
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2(d1);
	return 0;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
private:
	int _year;
	int _month;
	int _day;
};
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

private:
	    int _year;
	    int _month;
	    int _day;
};class Array
{
public:
	Array(int size)
		:_size(size)
		, _array((int*)malloc(sizeof(int)*_size))
	{}
private:
	   int* _array;
	   int _size;
};class A
{
public:
	A() //�޲ι��캯��
	{
		++_scount;
	}
	A(const A& t)//�������캯�� 
	{ 
		++_scount; 
	}
	static int GetACount()//��̬��Ա����
	{ 
		return _scount;
	}
private:
	static int _scount;//��̬��Ա����
};
int A::_scount = 0;//��̬��Ա����������������г�ʼ�������ұ����������������������һ������
void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	ostream& operator<<(ostream& _cout)//����һ�����ص��β�this��ռ�ݵ�һ��λ�ã������������
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

private:
	int _year;
	int _month;
	int _day
};
int main()
{
	Date d(2017, 12, 24);
	d << cout;//����ʱ��thisΪ��һ��������Ĭ�Ͻ��������������˵���ʱdӦ��Ϊ�������
	return 0;
}