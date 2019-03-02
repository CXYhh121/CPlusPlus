#define _CRT_SECURE_NO_WARNINGS

#include "iostream"  
#include "vector"  
using namespace std;
//
//int main(void)
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//	}
//	return 0;
//}

//计算一个类的大小
#pragma pack(2)
class A
{
	int i;
	union U
	{
		char buff[13];
		int i;
	}u;
	void foo(){};
	typedef char* (*f)(void*);
	enum { Red, Green, Bule } color;
};

int main()
{
	printf("%d\n", sizeof(A));
	return 0;
}


//计算枚举类型所占空间大小
//enum
//{
//	red,
//	green,
//	bule,
//	yellow
//}e;
//
//int main()
//{
//	printf("%d\n",sizeof(e));
//	return 0;
//}