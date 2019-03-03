#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>//头文件错误
//class A
//{
//public:
//	virtual void f(){}
//public:
//	A()
//	{
//		f();
//	}
//};
//class B1 :public A//继承错误，不需要括号
//{
//private:
//	char *_s;
//public:
//	B1()
//	{
//		_s = new char[1024];
//	}
//private:
//	void f()
//	{
//		delete[] _s;//delete[] _s;
//		_s = NULL;
//	}
//};//带分号
//class B2 :public A
//{
//private:
//	int * _m;
//public:
//	B2()
//	{
//		_m = new int(2016);
//	}
//private:
//	virtual void f()
//	{
//		delete _m;
//		_m = NULL;
//	}
//};//类后应该带分号
//int main()
//{
//	A* a1 = new int [1];//错误
//	A* a2 = new C;//错误
//	delete a1;
//	delete a2;
//	return 0;
//}