#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//int f(unsigned int n)
//{
//	unsigned int m = 0;
//	for (m = 0; n; ++m)
//	{
//		n &= (n - 1);
//	}
//	return m;
//}
//
//int main()
//{
//	cout << f(2486) << endl;
//	return 0;
//}

//int main()
//{
//	int x = 3, y;
//	int *px = &x;
//	y = *px++;
//	cout << x << " " << y << endl;
//	return 0;
//}



//虚函数和内联函数
//#include <iostream>
//using namespace std;
//class Base
//{
//public:
//	virtual void who()
//	{
//		cout << "I am Base\n";
//	}
//};
//class Derived : public Base
//{
//public:
//	void who()
//	{
//		cout << "I am Derived\n";
//	}
//};
//
//int main()
//{
//	// 此处的虚函数who()，是通过类的具体对象来调用的，编译期间就能确定了，所以它可以是内联的。
//	Base b;
//	b.who();
//
//	// 此处的虚函数是通过指针调用的，需要在运行时期间才能确定，所以不能为内联。
//	Base *ptr = new Derived();
//	ptr->who();
//
//	return 0;
//}