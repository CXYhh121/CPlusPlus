#include <iostream>
using namespace std;
class Date
{
public:
	int GetMonthDay(int year, int month);
	Date(int year = 2019, int month = 1, int day = 15);
	Date(const Date& d);//拷贝构造函数
	bool operator==(const Date& d);//重载运算符==
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	Date& operator=(const Date& d);//重载运算符=
	Date operator+=(int day);
	Date operator+(int day);
	Date operator-(int day);
	Date operator-=(int day);
	// 前置
	Date operator++();
	Date operator--();

	// 后置
	Date operator++(int);
	Date operator--(int);

	// d1-d2
	int operator-(const Date& d);
	void Display();



private:
	int _year;
	int _month;
	int _day;
};