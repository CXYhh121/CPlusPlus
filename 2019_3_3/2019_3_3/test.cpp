#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>//ͷ�ļ�����
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
//class B1 :public A//�̳д��󣬲���Ҫ����
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
//};//���ֺ�
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
//};//���Ӧ�ô��ֺ�
//int main()
//{
//	A* a1 = new int [1];//����
//	A* a2 = new C;//����
//	delete a1;
//	delete a2;
//	return 0;
//}