#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
int Date::GetMonthDay(int year, int month)
{
	int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 29;
	else
		return MonthDay[month];
}
Date::Date(int year, int month, int day)//带缺省参数的构造函数
{
	if (year > 0 &&
		month > 0 && month < 13 &&
		day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期非法，请重新输入！" << endl;
	}
}
//
Date::Date(const Date& d)//拷贝构造函数
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
//重载运算符==
bool Date::operator==(const Date& d)
{
	return _year == d._year &&
		_month == d._month &&
		_day == d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	else if (_year == d._year && _month > d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day > d._day)
		return true;
	else
		return false;
}
bool Date::operator<(const Date& d)
{
	return !((*this == d) || (*this > d));
}
bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

Date& Date::operator=(const Date& d)//重载运算符=
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;//返回d的值
}

//d1 += 20
Date Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month > 12)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

//
Date Date::operator+(int day)
{
	Date ret(*this);//调用拷贝构造函数构造一个临时对象
	ret += day;
	return ret;
}

Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}

Date Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_day += GetMonthDay(_year, _month);
		--_month;
		if (_month <= 0)
		{
			--_year;
			_month = 12;
		}
	}
	return *this;
}
// 前置
Date Date::operator++()
{
	++_day;
	if (_day > GetMonthDay(_year, _month))
	{
		++_month;
		if (_month > 12)
		{
			++_year;
			_month = 1;
		}
		_day = 1;
	}
	return *this;

}
Date Date::operator--()
{
	--_day;
	if (_day <= 0)
	{
		--_month;
		if (_month <= 0)
		{
			--_year;
			_month = 12;
		}
		_day = GetMonthDay(_year, _month);
	}
	return *this;
}
//
// 后置
Date Date::operator++(int)
{
	Date ret(*this);//拷贝构造一个临时对象ret
	++_day;
	if (_day > GetMonthDay(_year, _month))
	{
		++_month;
		if (_month > 12)
		{
			++_year;
			_month = 1;
		}
		_day = 1;
	}
	return ret;
}
Date Date::operator--(int)
{
	Date ret(*this);
	if (_day <= 0)
	{
		--_month;
		if (_month <= 0)
		{
			--_year;
			_month = 12;
		}
		_day = GetMonthDay(_year, _month);
	}
	return ret;
}

// d1-d2
int Date::operator-(const Date& d)
{
	int day = 0;
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		min = *this;
		max = d;
		flag = -1;
	}

	while (min != max)
	{
		++day;
		++min;
	}

	return day * flag;
}
void Date::Display()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}


int main()
{
	Date d1(2018, 11, 20);
	Date d2(2018, 12, 5);
	//cout << d1.operator==(d2) << endl;
	//cout << d1.operator!=(d2) << endl;
	//cout << d1.operator>(d2) << endl;
	//cout << d1.operator<(d2) << endl;
	//d1.operator+(20);
	//d1.operator+=(20);
	//d2 = d1.operator+(20);
	//d2 = d1.operator-(100);
	//d1.operator++();
	//d1.operator--();
	//d1--;
	//--d1;

	cout << (d1 - d2) << endl;
	
}