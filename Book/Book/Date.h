#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include <ctime>
#include <cstdio>
using namespace std;

class Date{
	friend ostream &operator<<(ostream &, const Date &);
	//friend istream &operator>>( istream &, Date & );

public:
	Date();
	Date(int y, int m, int d);
	~Date();
	void setDate(int y, int m, int d);
	void AddOneDate();
	void print();
	bool operator<(Date& data2);
private:
	int year;
	int month;
	int day;
};
#endif