#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <exception>
#include <string>
using namespace std;

//void Test()
//{
//	int* tmp = (int*)malloc(sizeof(int)* 100);
//	int* p = new int;
//	
//	vector<int> v1(1000000000, 10);
//	vector<int> v2(10, 10);
//	//v2[10] = 20;
//
//		free(tmp);
//		delete p;
//}
//int main()
//{
//	try
//	{
//		Test();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪����" << endl;
//	}
//	return 0;
//}

//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//		cout << "~SmatrPtr()" << endl;
//	}
//private:
//	T* _ptr;
//};
//
//void Test()
//{
//	int* tmp = (int*)malloc(sizeof(int)* 100);
//	//��tmpָ��ί�и�sp������sp�������tmpָ�����ռ䣬ֱ��tmpָ�뱻����
//	SmartPtr<int> sp(tmp);
//	//vector<int> v(100000000, 10);
//	string s = "�������";
//	throw s;
//
//	free(tmp);
//}
//int main()
//{
//	try
//	{
//		Test();
//	}
//	catch (string& s)
//	{
//		cout << s << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪����" << endl;
//	}
//	return 0;
//}


//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//		cout << "~SmatrPtr()" << endl;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//struct Date
//{
//	int _year;
//	int _mouth;
//	int _day;
//};
//
//int main()
//{
//	SmartPtr<int> sp1(new int);
//	//sp1.operator*() = 10;
//	*sp1 = 10;
//	cout << *sp1 << endl;
//
//
//	SmartPtr<Date> sp2(new Date);
//	//sp2.operator->()->_year = 2019;
//	sp2->_year = 2019;
//	sp2->_mouth = 10;
//	sp2->_day = 19;
//
//	return 0;
//}


// C++���е�����ָ�붼������memory���ͷ�ļ���
//#include <memory>
//class Date
//{
//public:
//	Date() { cout << "Date()" << endl; }
//	~Date(){ cout << "~Date()" << endl; }
//	int _year;
//	int _month;
//	int _day;
//};//////int main()//{//	auto_ptr<Date> ap(new Date);//	auto_ptr<Date> copy(ap);//	//	ap->_year = 2019;//	return 0;//}//#include <memory>////class Date
//{
//public:
//	Date() { cout << "Date()" << endl; }
//	~Date(){ cout << "~Date()" << endl; }
//	int _year;
//	int _month;
//	int _day;
//};////int main()
//{
//	unique_ptr<Date> up(new Date);
//
//	// unique_ptr�����˼·�ǳ��Ĵֱ�-��������Ҳ���ǲ��ÿ����͸�ֵ��
//	unique_ptr<Date> copy(up);
//	return 0;
//}// ģ��ʵ��һ�ݼ���UniquePtr,�˽�ԭ��
//template<class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T * ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~UniquePtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//private:
//	// C++98�������ķ�ʽ��ֻ������ʵ��+������˽��
//	UniquePtr(UniquePtr<T> const &);
//	UniquePtr & operator=(UniquePtr<T> const &);
//
//	// C++11�������ķ�ʽ��delete
//	UniquePtr(UniquePtr<T> const &) = delete;
//	UniquePtr & operator=(UniquePtr<T> const &) = delete;
//
//private:
//	T * _ptr;
//};