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



//�麯������������
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
//	// �˴����麯��who()����ͨ����ľ�����������õģ������ڼ����ȷ���ˣ������������������ġ�
//	Base b;
//	b.who();
//
//	// �˴����麯����ͨ��ָ����õģ���Ҫ������ʱ�ڼ����ȷ�������Բ���Ϊ������
//	Base *ptr = new Derived();
//	ptr->who();
//
//	return 0;
//}