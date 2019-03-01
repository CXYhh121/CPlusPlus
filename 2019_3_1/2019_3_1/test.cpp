//#define _CRT_SECURE_NO_WARNINGS
//
//#include<iostream>
//using namespace std;
//class A{
//public:
//	A(char *s)
//	{
//		cout << s << endl;
//	}
//	~A(){}
//};
//class B :virtual public A
//{
//public:
//	B(char *s1, char*s2) :A(s1){
//		cout << s2 << endl;
//	}
//};
//class C :virtual public A
//{
//public:
//	C(char *s1, char*s2) :A(s1){
//		cout << s2 << endl;
//	}
//};
//class D :public B, public C
//{
//public:
//	D(char *s1, char *s2, char *s3, char *s4) :B(s1, s2), C(s1, s3), A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//int main() {
//	D *p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}