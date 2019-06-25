#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ʲô����ֵ   =��߶�����ֵ		 ���Ըı��ֵ
// ʲô����ֵ   =�ұߵĲ�һ������ֵ  �����Ըı��ֵ(���������ʽ����ֵ����ʱ����)
// ��ֵ���� int& lr = a;   ���κʹ�ֵ��λ����ʹ�ã����ٿ��������Ч��  
// ��ֵ���� int&& rr = 10; ��ֵ���غͽ���ֵ���Σ������ƶ�������ƶ���ֵ�����ٿ��������Ч��
// const��ֵ������������ֵ
// ��ֵ����move(��ֵ)
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	// ��������
	// String s(��ֵ����)
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;
		strcpy(_str, s._str);
	}

	// �ƶ�����
	// String s(����ֵ����) 
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(String&& s)" << endl;

		swap(_str, s._str);
	}

	// s1 = s2
	String& operator=(const String& s)
	{
		cout << "String& operator=(const String& s)" << endl;
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}


	// �ƶ���ֵ
	// s1 = s2
	String& operator=(String&& s)
	{
		cout << "String& operator=(String&& s)" << endl;
		swap(_str, s._str);

		return *this;
	}

	~String()
	{
		if (_str) delete[] _str;
	}

	// s1 += s2  ������ֵ���ã����κʹ�ֵ��λ�ü��ٿ��������Ч��  
	String& operator+=(const String& s)
	{
		//this->Append(s.c_str());
		return *this;
	}

	// s1 + s2
	String operator+(const String& s)
	{
		String tmp(*this);
		//tmp.Append(s.c_str());
		return tmp;
	}

	const char* c_str()
	{
		return _str;
	}


private:
	char* _str;
};

struct Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
//
//int main()
//{
//	String s1("hello");
//	String s2("hello");
//
//	//s1 += s2;
//	//String ret = s1 + s2;
//	String ret;
//	ret = s1 + s2;
//
//	vector<string> v;
//	string str("world");
//	v.push_back(str);
//	//v.push_back(move(str));
//	v.push_back("hello");
//
//	v.emplace_back("hello");
//	v.emplace_back(str);
//	v.emplace_back(move(str));
//
//	vector<Date> vd;
//	Date d1(2019, 6, 25);
//	vd.push_back(d1); // ��ֵ
//	vd.push_back(Date(2019, 6, 26)); // ��ֵ
//	//vd.push_back(2019, 6, 26);
//
//
//	vd.emplace_back(Date(2019, 6, 26));
//	vd.emplace_back(d1);
//	//vd.emplace_back(2019, 6, 26);
//
//
//	return 0;
//}