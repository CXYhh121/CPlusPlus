#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <assert.h>
using namespace std;

namespace CXY
{
	class String
	{
	public:
		typedef char* Iterator;//������
		Iterator begin()
		{
			return _str;//�����ַ�����ͷλ��
		}
		Iterator end()
		{
			return _str + _size;//�����ַ���������λ��
		}

	public:
		//String();//�޲ι��캯��
		//String(const char* str);//���ι��캯��
		String(const char* str = "");//��ȱʡ�����Ĺ��캯��
		String(const String& str);//�������캯��
		String& operator=(const String& str);//���ظ�ֵ�����
		~String();//��������
		bool operator<(const String& s);
		bool operator>(const String& s);
		bool operator<=(const String& s);
		bool operator>=(const String& s);
		bool operator==(const String& s);
		bool operator!=(const String& s);

		void Swap(String& str);
		const char* C_str() const;
		char& operator[](size_t pos);
		size_t Size();
		size_t Capacity();
		
		void Reserve(size_t n);
		void PushBack(char ch);
		void Append(const char* str);
		

		String& operator+=(char ch);
		String& operator+=(const char* str);
		void Insert(size_t pos, char ch);
		void Insert(size_t pos, const char* str);

		void Erase(size_t pos, size_t len);
		size_t Find(char ch, size_t pos = 0);
		size_t Find(const char* str, size_t pos = 0);


	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};
	size_t String::npos = -1;
	void TestString()
	{
		String s1("hello world");
		cout << s1.C_str() << endl;
		String s2(s1);
		cout << s2.C_str() << endl;
		String s3("world");
		cout << (s1 < s3) << endl;
		cout << (s1 == s2) << endl;
		cout << (s1 > s3) << endl;

		//s1.PushBack('w');
		//cout << s1.C_str() << endl;
		//s2.Append(" world");
		//cout << s2.C_str() << endl;

		//s3 += 'w';
		//cout << s3.C_str() << endl;

		//s3 += " hello";
		//cout << s3.C_str() << endl;

		//s1.Insert(3, 'a');
		//cout << s1.C_str() << endl;

		//s1.Insert(3, "whkk");
		//cout << s1.C_str() << endl;


		//s1.Erase(2, 2);
		//cout << s1.C_str() << endl;

		//cout << s1.Find('e') << endl;

		cout << s1.Find("world") << endl;
	}

}