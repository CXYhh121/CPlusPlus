#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


//����unordered_map
//int main()
//{
//	unordered_map<string, string> um;
//	um.insert(make_pair(string("sort"), string("����")));
//	um.insert(make_pair(string("string"), string("�ַ���")));
//	um.insert(make_pair(string("left"), string("���")));
//	um.insert(make_pair(string("lost"), string("��ʧ")));
//	um.insert(make_pair(string("come"), string("����")));
//	
//	cout << um.empty() << endl;//�ж��Ƿ�Ϊ��
//	cout << um.size() << endl;//Ԫ�صĸ���
//
//
//	unordered_map<string, string>::iterator it = um.begin();
//	while (it != um.end())
//	{
//		cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//
//	return 0;
//}


//����unordered_set
//int main()
//{
//	unordered_set<int> us;
//	us.insert(9);
//	us.insert(6);
//	us.insert(8);
//	us.insert(10);
//	us.insert(7);
//	us.insert(3);
//	us.insert(6);
//	us.insert(7);
//	us.insert(4);
//
//	cout << us.empty() << endl;
//	cout << us.size() << endl;
//
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	return 0;
//}