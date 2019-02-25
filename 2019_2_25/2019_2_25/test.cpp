#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//using namespace std;
//
//void f(char * x)
//{
//	x++;
//	*x = 'a';
//}
//int main()
//{
//	char str[sizeof("hello")];
//	strcpy(str, "hello");
//	f(str);
//	cout << str;
//	return 0;
//}

#include <iostream>
using namespace std;

int func(int n)
{
	if (n < 1)
		return 1;
	else
		return n + func(n - 1);
	return 0;
}
int main()
{
	cout << func(5) << endl;
	return 0;
}