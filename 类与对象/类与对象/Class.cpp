//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	// 1.无参构造函数
//	Date()
//	{}
//
//	// 2.带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//3、带缺省值的构造函数
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
//	Date d1; // 调用无参构造函数,系统给出默认值
//	Date d2(2015, 1, 1); // 调用带参的构造函数，将对象初始化为2015-1-1
//	Date d3;//调用带缺省值的构造函数，对象初始化为2019-1-1
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
//	int _age;//默认析构函数不会处理内置类型的成员变量
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
	A() //无参构造函数
	{
		++_scount;
	}
	A(const A& t)//拷贝构造函数 
	{ 
		++_scount; 
	}
	static int GetACount()//静态成员函数
	{ 
		return _scount;
	}
private:
	static int _scount;//静态成员变量
};
int A::_scount = 0;//静态成员变量必须在类外进行初始化，而且必须带上类名标明是属于哪一个类域
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

	ostream& operator<<(ostream& _cout)//还有一个隐藏的形参this，占据第一个位置，接收左操作数
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
	d << cout;//传参时，this为第一个参数，默认接受左操作数，因此调用时d应该为左操作数
	return 0;
}