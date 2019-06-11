#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	void print()
//	{
//		cout << "A:print()";
//	}
//};
//class B : private A
//{
//public:
//	void print()
//	{
//		cout << "B:print()";
//	}
//};
//class C : public B
//{
//public:
//	void print()
//	{
//		//A::print();B对A的继承是私有继承
//	}
//};
//int main()
//{
//	C b;
//	b.print();
//}



//#include <iostream>
//using namespace std;
//class A {
//public:
//	~A() 
//	{
//		cout << "~A()";
//	}
//};
//class B{
//public:
//	virtual ~B()
//	{
//		cout << "~B()";
//	}
//};
//class C : public A, public B {
//public:
//	~C()
//	{
//		cout << "~C()";
//	}
//};
//int main() 
//{
//	C * c = new C;
//	B * b1 = dynamic_cast<B *>(c);
//	A * a2 = dynamic_cast<A *>(b1);
//	delete a2;
//}


//超长正整数相加
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		size_t size = (str1.size() > str2.size()) ? str1.size() : str2.size();
		reverse(str1.begin(), str1.end());
		reverse(str2.begin(), str2.end());

		int carry = 0;
		string ret;
		for (size_t i = 0; i < size; ++i)
		{
			const int s1 = (i < str1.size()) ? (str1[i] - '0') : 0;
			const int s2 = (i < str2.size()) ? (str2[i] - '0') : 0;
			const int val = (s1 + s2 + carry) % 10;
			carry = (s1 + s2 + carry) / 10;
			ret.insert(ret.begin(), val + '0');
		}
		if (carry == 1)
		{
			ret.insert(ret.begin(), 1);
		}
		cout << ret << endl;
		//ret.clear();
		//carry = 0;
	}
	return 0;
}



//杨辉三角形的变形
#include <iostream>
#include <vector>
using namespace std;
int yanghui(int n, int k)
{
	if (k == 1 || k == n * 2 - 1)
		return 1;
	if (k < 1 || k > n * 2 - 1)
		return 0;
	return yanghui(n - 1, k - 1) + yanghui(n - 1, k - 2) + yanghui(n - 1, k);
}
int main()
{
	int num;
	while (cin >> num)
	{
		for (int i = 1; i < num * 2 - 1; ++i)
		{
			if (yanghui(num, i) % 2 == 0)
			{
				cout << i << endl;
				break;
			}
			else if (i == (num * 2 - 1))
				cout << -1 << endl;
		}
	}
	return 0;
}