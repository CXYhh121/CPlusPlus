#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;
//
////测试string类的构造函数
//void TestString1()
//{
//	//string()
//	string s1; //构造空的string类对象s1
//	//string(const char* s)
//	string s2("hello world!"); //用c格式的字符串构造函数来构造string类对象s2
//	//string(size_t n,char c)
//	string s3(10, 'a');//用10个字符'a'构造string类对象s3
//	//string(const string& s)
//	string s4(s2);//用s2拷贝构造s4
//	//string(const string& s,size_t n)
//	string s5(s3, 5);//用s2中的前5个字符构造string类对象s5
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//
//}
//
//int main()
//{
//	TestString1();
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
////测试string类对象的容量操作
//
//void TestString()
//{
//	string s1("hello world!");
//	//计算字符串长度，包括空格，遇\0停止，不算\0
//	//size_t size() const 常用
//	cout << s1.length() << endl;//12
//	cout << s1.size() << endl;//12
//	
//	//size_t capacity() const 返回总空间的大小
//	cout << s1.capacity() << endl;//输出是15，开了2^4个空间
//	
//	//bool empty() const 判断字符串是否为空串，是返回true，否返回false
//	cout << s1.empty() << endl;//输出0
//	
//	//void clear() 清空有效字符,只是改变size的值，不改变底层空间的大小
//	s1.clear();
//	cout << s1 << endl;
//	cout << s1.capacity() << endl;//输出是依旧是15
//
//	//void resize(size_t n,char c) 将有效字符个数改为n个，多出的空间用字符c填充
//	string s2(5, 'a');
//	cout << s2.capacity() << endl;//输出为15
//	s2.resize(20, 'b');
//	cout << s2 << endl;
//	cout << s2.capacity() << endl;//输出为31
//	//void resize(size_t n) 将有效字符个数改为n个，多出的空间用0填充
//	s2.resize(3);
//	cout << s2 << endl;
//	cout << s2.capacity() << endl;//输出为31
//	//resize在改变元素个数时，如果是将元素个数增多，可能会改变底层容量的大小，如果是将元素个数减少，底层空间总大小不变
//
//}
//
//void TestString2()
//{
//	string s;
//	//void reserve(size_t res_aeg = 0) 为字符串预留空间，带缺省值
//	//1.测试reserve是否会改变string中有效元素个数
//	s.reserve(100);
//	cout << s.size() << endl;//输出0，说明reserve不会改变string中有效元素的个数
//	cout << s.capacity() << endl;//输出111
//
//	// 2.测试reserve参数小于string的底层空间大小时，是否会将空间缩小
//	s.reserve(50);
//	cout << s.size() << endl;//输出0
//	cout << s.capacity() << endl;//输出111，说明reserve参数小于string的底层空间大小时，空间不会缩小
//}
//int main()
//{
//	TestString2();
//	return 0;
//}
//
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <list>
//
//using namespace std;
//
////测试string类对象的访问操作
//void TestString1()
//{
//	string s1("hello");
//	const string s2("Hello world");
//	cout << s1 << " " << s2 << endl;
//	cout << s1[0] << " " << s2[0] << endl;
//
//	s1[0] = 'H';
//	cout << s1 << endl;
//	// s2[0] = 'h'; 代码编译失败，因为const类型对象不能修改
//
//	//遍历字符串的两种方式
//	//for循环遍历
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	//使用迭代器遍历
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//vector迭代器
//	vector<int> v(10, 5);
//	vector<int>::iterator vit = v.begin();
//	while (vit != v.end())
//	{
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//
//	//list迭代器
//	list<int> l(5, 10);
//	list<int>::iterator lit = l.begin();
//	while (lit != l.end())
//	{
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//
//	//范围for遍历，支持所有容器的遍历，底层依赖迭代器实现
//	for (auto ch:s1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	for (auto e : l)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//}
//
////逆置字符串
//string ReverseStr(const string& s)
//{
//	string ret;
//	string::const_reverse_iterator it = s.rbegin();
//	while (it != s.rend())
//	{
//		ret += *it;
//		++it;
//	}
//	return ret;
//}
//
//void TestString()
//{
//	string str("hello");
//	string::reverse_iterator rit = str.rbegin();
//	while (rit != str.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//	cout << ReverseStr(str) << endl;
//}
//
//int main()
//{
//	//TestString1();
//	TestString();
//	return 0;
//}
//
//#include <iostream>
//#include <string>
//
//using namespace std;
////测试string类对象的修改操作
//
//void TestString()
//{
//	string str;
//	str.push_back(' '); // 在str后插入空格
//	str.append("hello"); // 在str后追加一个字符"hello"
//	str += 'w'; // 在str后追加一个字符'w'
//	str += "orld"; // 在str后追加一个字符串"orld"
//	cout << str << endl;
//	cout << str.c_str() << endl; // 以C语言的方式打印字符串
//
//	//获取file的后缀
//	
//	string file1("test.cpp");
//	string file2("test.c.zip");
//
//	size_t pos = file1.rfind(".");
//	if (pos != string::npos)//npos是string里的一个静态成员变量
//	{
//		string suffix(file1.substr(pos,file1.size()-1));//拷贝构造一个suffix，存储.到最后位置的字符串
//		cout << suffix << endl;
//	}
//
//	pos = file2.rfind(".");
//	if (pos != string::npos)//npos是string里的一个静态成员变量
//	{
//		string suffix(file2.substr(pos, file2.size() - 1));//拷贝构造一个suffix，存储.到最后位置的字符串
//		cout << suffix << endl;
//	}
//   
//}
//void TestString1()
//{
//	// 取出url中的域名
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//		return;
//	}
//	start += 3;
//	size_t finish = url.find('/', start);
//	string address = url.substr(start, finish - start);
//	cout << address << endl;
//
//	// 删除url的协议前缀
//
//	size_t pos = url.find("://");
//	url.erase(0, pos + 3);
//	cout << url << endl;
//}
//
//int main()
//{
//	TestString1();
//	return 0;
//}