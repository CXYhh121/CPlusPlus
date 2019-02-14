//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//template<class T> class Foo{
//	T tVar;
//public:
//	Foo(T t) : tVar(t) { }
//};
//
//template<class T> class FooDerived :public Foo<T>
//{
//};
//
//int main()
//{
//	FooDerived<int> d(5);
//	return 0;
//}

#include <iostream>
using namespace std;

void fun1(int &x) {
	x++;
}

void fun2(int x) {
	x++;
}

int main() {
	int abc = 100, xyz = 13;
	fun1(xyz);
	abc = xyz;
	fun2(abc);
	printf("%d\n", abc);
}