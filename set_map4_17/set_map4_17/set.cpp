#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <functional>
#include <set>

using namespace std;


void Testset()//测试构造函数、拷贝构造、插入、删除、查找
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(3);
	s.insert(4);
	s.insert(2);
	s.insert(8);
	s.insert(4);
	s.insert(5);
	s.insert(3);
	s.insert(6);

	//set<int>::iterator it = s.begin();
	//while (it != s.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	set<int> copy(s);
	set<int>::iterator it = copy.begin();
	while (it != copy.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	auto t1 = s.find(5);//set自己的find函数,时间复杂度O(logN)
	auto t2 = std::find(s.begin(), s.end(), 5);//算法中的find函数，时间复杂度为O(N)
	if (t2 != s.end())
	{
		s.erase(t2);
	}

	s.erase(5);
	s.erase(3);
	//s.clear();
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	
	
}

//测试multiset，基本接口个set一样，唯一区别是multiset允许序列中有重复元素
void Test_multiset()
{
	multiset<int> ms;
	ms.insert(2);
	ms.insert(3);
	ms.insert(5);
	ms.insert(4);
	ms.insert(5);
	ms.insert(1);
	ms.insert(5);
	ms.insert(2);
	ms.insert(7);
	ms.insert(6);

	multiset<int>::iterator mit = ms.begin();
	while (mit != ms.end())
	{
		cout << *mit << " ";
		++mit;
	}
	cout << endl;
}


//int main()
//{
//	//Testset();
//	//Test_multiset();
//	return 0;
//}