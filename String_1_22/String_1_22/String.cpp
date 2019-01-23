#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

using namespace std;
using namespace CXY;

//String::String()
//:_str(new char[1])
//{
//	_str[0] = '\0';
//}

//���ι��캯��
//String::String(const char* str)
//:_str(new char[strlen(str)+1])
//{
//	strcpy(_str, str);
//}

//��ȱʡ�����Ĺ��캯��
String::String(const char* str)
{
	assert(str);

	_size = strlen(str);
	_capacity = _size;
	_str = new char[_capacity + 1];
	strcpy(_str, str);
}

String::~String()//��������
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
//�������캯����ͳд��
//String::String(const String& str)
//:_str(new char[str._capacity+1])
//, _size(str._size)
//, _capacity(str._capacity)
//{
//	strcpy(_str, str._str);
//}
//�������캯���ִ�д��
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

//���ط��������[]
char& String::operator[](size_t pos)
{
	assert(pos < _size);
	return _str[pos];
}

//���ַ�������
size_t String::Size()
{
	return _size;
}

//���ַ����ռ��С
size_t String::Capacity()
{
	return _capacity;
}

//Ϊ�ַ���Ԥ���ռ�
void String::Reserve(size_t newcapacity)
{
	//���������С���������������¿ռ�
	if (newcapacity > _capacity)
	{
		//�����¿ռ�,��ԭ�ռ���ַ����������¿ռ�
		char* tmp = new char[newcapacity+1];
		assert(tmp);
		strcpy(tmp, _str);

		//�ͷžɿռ䣬ʹ���¿ռ�
		delete[] _str;
		_str = tmp;
		_capacity = newcapacity;
	}
	
}

//���ַ�����׷��һ���ַ�
void String::PushBack(char ch)
{
	//if (_size == _capacity)
	Reserve(_capacity * 2);
	_str[_size] = ch;
	++_size;
	_str[_size] = '\0';
}

//���ַ�����׷��һ���ַ���
// "hello"  "xxxxxxxxxxxxxxxxxxxxxxxxxx"
void String::Append(const char* str)
{
	// �ж�׷���ַ����Ƿ񵽴�������������Ǿ�����
	//if (_size == _capacity)
	Reserve(_size + strlen(str) + 1);

	strcpy(_str + _size, str);
	_size += strlen(str);
}
const char* String::C_str() const
{
	return _str;
}

//���������+=
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

//��ָ��λ��pos�������ַ�ch
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

//��ָ��λ��pos�������ַ���str
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

//��ָ��λ��pos��ɾ������Ϊlen���ַ���
void String::Erase(size_t pos, size_t len)
{
	for (size_t i = pos + len; i <= _size; ++i)
	{
		_str[pos] = _str[i];
		++pos;
	}
	_size -= len;
}

//���ַ�����Ѱ��һ���ַ�ch�����ظ��ַ����±�
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


