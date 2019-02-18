#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//using namespace std;
//
//class Base
//{
//	int x;
//public:
//	Base(int b) : x(b) {}
//	virtual void display()
//	{
//		cout << x;
//	};
//};
//class Derived : public Base
//{
//	int y;
//public:
//	Derived(int d) : Base(d), y(d) {} void display()
//	{
//		cout << y;
//	}
//};
//
//int main()
//{
//	Base b(1);
//	Derived d(2);
//	Base *p = &d;
//	b.display();
//	d.display();
//	p->display();
//	return 0;
//
//}

#include "stdio.h"
#define N 9
int x[N];
int count = 0;

void dump() {
	int i = 0;
	for (i = 0; i < N; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}

void swap(int a, int b) {
	int t = x[a];
	x[a] = x[b];
	x[b] = t;
}

void run(int n) {
	int i;
	if (N - 1 == n) {
		dump();
		count++;
		return;
	}
	for (i = n; i < N; i++) {
		swap(n, i);
		run(n + 1);
		swap(n, i);
	}
}

int main() {
	int i;
	for (i = 0; i < N; i++) {
		x[i] = i + 1;
	}
	run(0);
	printf("* Total: %d\n", count);
}