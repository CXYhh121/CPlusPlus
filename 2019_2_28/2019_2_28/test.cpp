#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//class Base
//{
//public:
//	virtual   ~Base(){ std::cout << "Base Destructor" << std::endl; }
//};
//class Derived : public Base
//{
//public:
//	~Derived(){ std::cout << "Derived   Destructor" << std::endl; }
//};
//
//int main()
//{
//	Base* p = new Derived();
//	delete p;
//	return 0;
//}

//
//class A {
//private:
//	int &a;
//};
//class B : public A {
//private:
//	int a;
//public:
//	const int b;
//	A c;
//	static const char* d;
//	A* e;
//};


//四种格式控制符
//setw

#include <iostream>
using namespace std;

#include <iomanip>

//int main()
//{
//	cout << setw(10) << 77 << endl;
//	return 0;
//}

//setfill
//
//int main()
//{
//	cout << setfill('c') <<setw(10)<< 77 << endl;
//	return 0;
//}

// setbase example
//#include <iostream>     // std::cout, std::endl
//#include <iomanip>      // std::setbase
//
//int main() {
//	std::cout << std::setbase(16);
//	std::cout << 110 << std::endl;
//	return 0;
//}

// setprecision example
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
using namespace std;
//int main() {
//	double f = 3.14159;
//	std::cout << std::setprecision(5) << f << '\n';
//	std::cout << std::setprecision(9) << f << '\n';
//	std::cout << std::fixed;
//	std::cout << std::setprecision(5) << f << '\n';
//	std::cout << std::setprecision(9) << f << '\n';
//	return 0;
//}

int main()
{
	double d = 3.1415926;

	cout << setprecision(4) << d << endl;
	cout << setprecision(8) << d << endl;
	cout << fixed;
	cout << setprecision(9) << d << endl;

	return 0;
}


//
//#include <iostream>        
//#include <iomanip>        
//
//int main()
//{
//	double amount = 22.0 / 7;
//
//	cout << amount << endl;
//	cout << setprecision(0) << amount << endl
//		<< setprecision(1) << amount << endl
//		<< setprecision(2) << amount << endl
//		<< setprecision(3) << amount << endl
//		<< setprecision(4) << amount << endl;
//
//	cout << setiosflags(ios::fixed);
//	cout << setprecision(8) << amount << endl;
//	cout << setiosflags(ios::scientific) << amount << endl;
//	cout << setprecision(6); //重新设置成原默认设置        
//
//	return 0;
//}