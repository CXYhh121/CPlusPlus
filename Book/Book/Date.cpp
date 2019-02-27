#define _CRT_SECURE_NO_WARNINGS

# include"Date.h"
ostream &operator<<(ostream &output, const Date &d)
{

	output << d.year << d.month << d.day << endl;
	return output;

}

Date::Date(int y, int m, int d)
{
	setDate(y, m, d);
}
Date::~Date()
{
	cout << "Destructors" << endl;
}
void Date::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
void Date::AddOneDate()
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
	{
		if (day<31)
			day = day + 1;
		else {
			day = 1;
			month = month + 1;
		}
	} return;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day<30)
			day = day + 1;
		else {
			day = 1;
			month = month + 1;
		}
	} return;
	if (month == 12)
	{
		if (day<31)
			day = day + 1;
		else{
			day = 1;
			month = 1;
		}
	} return;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		if (day<29)
			day = day + 1;
		else {
			day = 1;
			month = month + 1;
		}
	}
	else {
		if (day<28)
			day = day + 1;
		else{
			day = 1;
			month = month + 1;
		}
	}
}

void Date::print()
{
	cout << year << "Äê" << month << "ÔÂ" << day << "ÈÕ" << endl;
}

bool Date::operator<(Date& date2)
{
	if (year>date2.year)
		return false;
	else if (year<date2.year)
		return true;
	else if (month>date2.month)
		return false;
	else if (month<date2.month)
		return true;
	else if (day>date2.day)
		return false;
	else if (day<date2.day)
		return true;
	else
		return false;
}