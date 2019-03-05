#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{
public:
	//String()//Ĭ�Ϲ��캯��
	//	:_str (new char[1])
	//{
	//	_str[0] = '\0';
	//}
	//String(const char* str)
	//	:_str(new char[strlen(str) + 1])
	//{
	//	strcpy(_str, str);
	//}
	String(const char* str = "")//��ȱʡֵ�Ĺ��캯��
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
	String(const String& s)//�������캯��
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	
	//s0 = s1 = s2
	String& operator=(const String& s)//��ֵ�����=
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