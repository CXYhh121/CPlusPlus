#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//int main()
//{
//	char ccString1[] = "Is Page Fault??";
//	char ccString2[] = "No Page Fault??";
//	strcpy(ccString1, "No");
//	if (strcmp(ccString1, ccString2) == 0)
//		cout << ccString2;
//	else
//		cout << ccString1;
//	return 0;
//}

class A{
	int i;
};
class B{
	A *p;
public:
	B(){ p = new A; }
	~B(){ delete p; }
};
void sayHello(B b){
}
int main(){
	B b;
	sayHello(b);
}
