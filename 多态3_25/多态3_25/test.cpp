#define _CRT_SECURE_NO_WARNINGS


//虚函数表
//class Base
//{
//public:
//	void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	Base b;  
//	printf("%d\n", sizeof(Base));
//	return 0;
//}


//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	printf("Base:%d\n", sizeof(Base));
//    printf("Derive:%d\n", sizeof(Derive));
//
//	return 0;
//}


//多态的实现原理
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}


//单继承中的虚函数表
//
//#include <iostream>
//using namespace std;

//typedef void(* VFPTR) ();//将fun函数定义为一个虚函数指针VFPTR
//
//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive : public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//
//
//void PrintVTable(VFPTR* vTable)//打印出虚函数表中存储的虚函数指针
//{
//	cout << "虚表地址->" << vTable << endl;
//
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf("第%d个虚函数的地址:0x%x->", i, vTable[i]);
//		VFPTR f = vTable[i];
//    //调用一下存在虚表对应地址的函数，输出对应函数的实现，就能知道调用的是哪个函数了
//		f();
//	}
//}
//int main()
//{
//	Base b;
//	Derive d;
//
//	VFPTR* vTableb = (VFPTR*)(*(int*)&b);//取对象前四个字节就是虚表指针
//	PrintVTable(vTableb);
//
//	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTabled);
//
//	return 0;
//}


//多继承中的虚函数表

//#include <iostream>
//using namespace std;
//
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//class Derive : public Base1, public Base2 
//{
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//typedef void(* VFPTR) ();
//void PrintVTable(VFPTR* vTable)
//{
//	cout << "虚表地址->" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf("第%d个虚函数地址:0x%x->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//}
//int main()
//{
//	Derive d;
//
//	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTableb1);
//
//	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
//	PrintVTable(vTableb2);
//
//	return 0;
//}