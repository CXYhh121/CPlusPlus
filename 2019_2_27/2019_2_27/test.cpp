#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class A
{
	int i;
	union U
	{
		char buff[13];
		int i;
	}u;
	void foo() {    }
	typedef char* (*f)(void*);
	enum{ red, green, blue } color;
}a;

int main()
{
	printf("%d\n", sizeof(a));
	return 0;
}