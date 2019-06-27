#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

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

	// 拷贝构造
	// String s(左值对象)
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;
		strcpy(_str, s._str);
	}

	// 移动构造
	// String s(将亡值对象) 
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(String&& s)" << endl;
		swap(_str, s._str);
	}

	// s1 = s2 正常赋值
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

	// 移动赋值
	// s1 = s2
	String& operator=(String&& s)
	{
		cout << "String& operator=(String&& s)" << endl;
		swap(_str, s._str);

		return *this;
	}

	// s1 += s2  体现左值引用，传参和传值的位置减少拷贝，提高效率  
	String& operator+=(const String& s)
	{
		//this->Append(s.c_str());
		return *this;
	}

	// s1 + s2 体现右值引用，将亡值tmp自动调用移动构造和移动赋值以减少拷贝
	String operator+(const String& s)
	{
		String tmp(*this);
		//tmp.Append(s.c_str());
		return tmp;
	}


	~String()
	{
		if (_str) delete[] _str;
	}

	const char* c_str()
	{
		return _str;
	}


private:
	char* _str;
};

//int main()
//{
//	String s1("hello");
//	String s2("world");
//
//	//s1 += s2;//测试一下左值引用
//	String ret;
//	ret = s1 + s2;
//	return 0;
//}


void Fun(int &x){ cout << "lvalue ref" << endl; }
void Fun(int &&x){ cout << "rvalue ref" << endl; }
//void Fun(const int &x){ cout << "const lvalue ref" << endl; }
//void Fun(const int &&x){ cout << "const rvalue ref" << endl; }

template<typename T>
void PerfectForward(T &&t){ Fun(std::forward<T>(t)); }

int main()
{
	PerfectForward(10); // rvalue re
	int a;
	PerfectForward(a);			   // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref

	//const int b = 8;
	//PerfectForward(b); // const lvalue ref
	//PerfectForward(std::move(b)); // const rvalue ref

	return 0;
}