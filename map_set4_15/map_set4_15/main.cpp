#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//#include <string>
//using std::cout;
//using std::endl;
//
//#include <map>
//#include <set>
//
//void test_set()
//{
//	// 1.在不在
//	// 2.排序+去重
//	// 3.去重
//	std::set<int> s;
//	s.insert(2);
//	s.insert(3);
//	s.insert(1);
//	s.insert(5);
//	s.insert(5);
//	s.insert(3);
//	s.insert(3);
//	s.insert(5);
//	s.insert(5);
//	s.insert(5);
//	s.insert(4);
//	s.insert(5);
//	s.insert(5);
//	s.insert(5);
//
//	std::set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	auto it1 = std::find(s.begin(), s.end(), 5); // O(N)
//	auto it2 = s.find(5); // O(logN)
//	if (it2 != s.end())
//	{
//		s.erase(it2);
//	}
//
//	s.erase(5);
//	s.erase(1);
//	s.clear();
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test_mutil_set()
//{
//	std::multiset<int> s;
//	typedef std::multiset<int>::iterator msiter;
//	s.insert(3);
//	s.insert(3);
//	s.insert(1);
//	s.insert(2);
//	s.insert(3);
//	s.insert(2);
//	s.insert(5);
//	s.insert(3);
//	s.insert(4);
//
//	//msiter it = s.begin();
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	it = s.find(2);
//	cout << *it << endl;
//	++it;
//	cout << *it << endl;
//	++it;
//	cout << *it << endl;
//}

#include "BSTree.h"

void Test_map()
{

}

int main()
{

	//test_set();
	//test_mutil_set();
	return 0;
}



//class A
//{
//public:
//	A()
//	{
//		printf("0");
//	}
//	A(int a)
//	{
//		printf("1");
//	}
//	A& operator=(const A& a)
//	{
//		printf("2");
//		return  *this;
//	}
//};
//int main()
//{
//	A al;
//	al = 10;
//}