#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void Fun(int &x){ cout << "lvalue ref" << endl; }
void Fun(int &&x){ cout << "rvalue ref" << endl; }
//void Fun(const int &x){ cout << "const lvalue ref" << endl; }
//void Fun(const int &&x){ cout << "const rvalue ref" << endl; }

template<typename T>
void PerfectForward(T &&t){ Fun(std::forward<T>(t)); }

//int main()
//{
//	PerfectForward(10); // rvalue re
//	int a;
//	PerfectForward(a);			   // lvalue ref
//	PerfectForward(std::move(a)); // rvalue ref
//
//	//const int b = 8;
//	//PerfectForward(b); // const lvalue ref
//	//PerfectForward(std::move(b)); // const rvalue ref
//
//	return 0;
//}
typedef bool(*GTF)(int, int);
bool greater_func1(int l, int r)
{
	return l > r;
}

struct greater_func2
{
	bool operator()(int l, int r)
	{
		return l > r;
	}
};

//int main()
//{
//	// 函数指针、仿函数、lamber用法上是一样的。
//	// 函数指针 类型定义难理解
//	// 仿函数  运算符重载  先定义好，再用
//	// lamber 现定义现用
//	//GTF f1 = greater_func1;
//	bool(*f1)(int, int) = greater_func1;
//	cout << f1(1, 2) << endl;
//
//	greater_func2 f2;
//	cout << f2(1, 2) << endl;
//
//	//       捕捉列表 参数列表 返回值 函数体
//	auto f3 = [](int l, int r)->bool{return l > r; };
//	cout << f3(1, 2) << endl;
//
//	int a[] = { 1, 4, 5, 2, 6, 9, 8, 7 };
//	sort(a, a + sizeof(a) / sizeof(int), f1);
//	sort(a, a + sizeof(a) / sizeof(int), f2);
//	sort(a, a + sizeof(a) / sizeof(int), f3);
//
//
//	return 0;
//}

struct Goods
{
	string _name;
	double _price;
	double _appraise;
};

int main()
{
	Goods gds[] = { { "苹果", 2.1, 10 }, { "相交", 3, 8 }, { "橙子", 2.2, 7 }, { "菠萝", 1.5, 10 } };

	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
	{return g1._price > g2._price; });

	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
	{return g1._appraise > g2._appraise; });

	return 0;
}