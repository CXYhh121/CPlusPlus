#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{
public:
	//String()//默认构造函数
	//	:_str (new char[1])
	//{
	//	_str[0] = '\0';
	//}
	//String(const char* str)
	//	:_str(new char[strlen(str) + 1])
	//{
	//	strcpy(_str, str);
	//}
	String(const char* str = "")//带缺省值的构造函数
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
			delete[] _str;
		_str = nullptr;
	}

	//s1(s2)
	String(const String& s)//拷贝构造函数
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	
	//s0 = s1 = s2
	String& operator=(const String& s)//赋值运算符=
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}

		return *this;
	}

private:
	char* _str;
};