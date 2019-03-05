#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
class Sample{
public:
	Sample(int x){
		p = new int(x);
	}
	~Sample(){
		if (p) delete p;
	}
	int show(){
		return *p;
	}
private:
	int*p;
};
int main(){
	Sample S(5);
	cout << S.show() << endl;
	return 0;
}