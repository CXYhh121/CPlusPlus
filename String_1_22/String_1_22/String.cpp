#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

using namespace std;
using namespace CXY;

//String::String()
//:_str(new char[1])
//{
//	_str[0] = '\0';
//}

//带参构造函数
//String::String(const char* str)
//:_str(new char[strlen(str)+1])
//{
//	strcpy(_str, str);
//}

//带缺省参数的构造函数
String::String(const char* str)
{
	assert(str);

	_size = strlen(str);
	_capacity = _size;
	_str = new char[_capacity + 1];
	strcpy(_str, str);
}

String::~String()//析构函数
{
	if (_str)
	{
		delete[] _str;
		_size = 0;
		_capacity = 0;
	}
}


void String::Swap(String& str)
{
	swap(_str, str._str);
	swap(_size, str._size);
	swap(_capacity, str._capacity);
}
//拷贝构造函数传统写法
//String::String(const String& str)
//:_str(new char[str._capacity+1])
//, _size(str._size)
//, _capacity(str._capacity)
//{
//	strcpy(_str, str._str);
//}
//拷贝构造函数现代写法
// copy(s1)

String::String(const String& str)
:_str(nullptr)
, _size(0)
, _capacity(0)
{
	String tmp(str._str);
	this->Swap(tmp);
}

bool String::operator<(const String& s)
{
	if (strcmp(_str, s._str) < 0)
		return true;
	else
		return false;
	      
}

bool String::operator==(const String& s)
{
	if (strcmp(_str, s._str) == 0)
		return true;
	else
		return false;
}

bool String::operator>(const String& s)
{
	return !((_str < s._str) || (_str == s._str));
}

bool String::operator<=(const String& s)
{
	return !(_str > s._str);
}

bool String::operator>=(const String& s)
{
	return !(_str < s._str);
}

//重载访问运算符[]
char& String::operator[](size_t pos)
{
	assert(pos < _size);
	return _str[pos];
}

//求字符串长度
size_t String::Size()
{
	return _size;
}

//求字符串空间大小
size_t String::Capacity()
{
	return _capacity;
}

//为字符串预留空间
void String::Reserve(size_t newcapacity)
{
	//如果旧容量小于新容量，开辟新空间
	if (newcapacity > _capacity)
	{
		//开辟新空间,将原空间的字符串拷贝到新空间
		char* tmp = new char[newcapacity+1];
		assert(tmp);
		strcpy(tmp, _str);

		//释放旧空间，使用新空间
		delete[] _str;
		_str = tmp;
		_capacity = newcapacity;
	}
	
}

//在字符串后追加一个字符
void String::PushBack(char ch)
{
	//if (_size == _capacity)
	Reserve(_capacity * 2);
	_str[_size] = ch;
	++_size;
	_str[_size] = '\0';
}

//在字符串后追加一个字符串
// "hello"  "xxxxxxxxxxxxxxxxxxxxxxxxxx"
void String::Append(const char* str)
{
	// 判断追加字符串是否到达了最大容量，是就增容
	//if (_size == _capacity)
	Reserve(_size + strlen(str) + 1);

	strcpy(_str + _size, str);
	_size += strlen(str);
}
const char* String::C_str() const
{
	return _str;
}

//重载运算符+=
String& String::operator+=(char ch)
{
	PushBack(ch);
	return *this;
}

String& String::operator+=(const char* str)
{
	Append(str);
	return *this;
}

//在指定位置pos处插入字符ch
void String::Insert(size_t pos, char ch)
{
	Reserve(_capacity * 2);

	for (size_t i = _size; i >= pos; --i)
	{
		_str[i + 1] = _str[i];
	}

	_str[pos] = ch;
	++_size;
}

//在指定位置pos处插入字符串str
void String::Insert(size_t pos, const char* str)
{
	Reserve(_size + strlen(str) + 1);

	size_t gap = strlen(str);
	for (size_t i = _size; i >= pos; --i)
	{
		_str[i + gap] = _str[i];
	}

	for (size_t i = 0; i < gap; ++i)
	{
		Insert(pos, str[i]);
		++pos;
	}
	_size += gap;
}

//在指定位置pos处删除长度为len的字符串
void String::Erase(size_t pos, size_t len)
{
	for (size_t i = pos + len; i <= _size; ++i)
	{
		_str[pos] = _str[i];
		++pos;
	}
	_size -= len;
}

//在字符串中寻找一个字符ch，返回该字符的下标
size_t String::Find(char ch, size_t pos)
{
	for (size_t i = pos; i < _size; ++i)
	{
		if (_str[i] == ch)
			return i;
	}
	return npos;
}

size_t String::Find(const char* str, size_t pos)
{
	size_t begin = Find(str[0]);
	size_t index = begin;
	int len = strlen(str);
	while (begin < _size)
	{
		int i = 0;
		char* arr = _str + begin;
		while (i < len)
		{
			if (arr[i] == str[i])
				++i;
			else
				break;
		}
		if (i == len)
			return index;
	}
	return npos;
}


int main()
{
	CXY::TestString();
	return 0;
}


