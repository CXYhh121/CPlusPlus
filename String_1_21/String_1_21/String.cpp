#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;
//
////����string��Ĺ��캯��
//void TestString1()
//{
//	//string()
//	string s1; //����յ�string�����s1
//	//string(const char* s)
//	string s2("hello world!"); //��c��ʽ���ַ������캯��������string�����s2
//	//string(size_t n,char c)
//	string s3(10, 'a');//��10���ַ�'a'����string�����s3
//	//string(const string& s)
//	string s4(s2);//��s2��������s4
//	//string(const string& s,size_t n)
//	string s5(s3, 5);//��s2�е�ǰ5���ַ�����string�����s5
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
////����string��������������
//
//void TestString()
//{
//	string s1("hello world!");
//	//�����ַ������ȣ������ո���\0ֹͣ������\0
//	//size_t size() const ����
//	cout << s1.length() << endl;//12
//	cout << s1.size() << endl;//12
//	
//	//size_t capacity() const �����ܿռ�Ĵ�С
//	cout << s1.capacity() << endl;//�����15������2^4���ռ�
//	
//	//bool empty() const �ж��ַ����Ƿ�Ϊ�մ����Ƿ���true���񷵻�false
//	cout << s1.empty() << endl;//���0
//	
//	//void clear() �����Ч�ַ�,ֻ�Ǹı�size��ֵ�����ı�ײ�ռ�Ĵ�С
//	s1.clear();
//	cout << s1 << endl;
//	cout << s1.capacity() << endl;//�����������15
//
//	//void resize(size_t n,char c) ����Ч�ַ�������Ϊn��������Ŀռ����ַ�c���
//	string s2(5, 'a');
//	cout << s2.capacity() << endl;//���Ϊ15
//	s2.resize(20, 'b');
//	cout << s2 << endl;
//	cout << s2.capacity() << endl;//���Ϊ31
//	//void resize(size_t n) ����Ч�ַ�������Ϊn��������Ŀռ���0���
//	s2.resize(3);
//	cout << s2 << endl;
//	cout << s2.capacity() << endl;//���Ϊ31
//	//resize�ڸı�Ԫ�ظ���ʱ������ǽ�Ԫ�ظ������࣬���ܻ�ı�ײ������Ĵ�С������ǽ�Ԫ�ظ������٣��ײ�ռ��ܴ�С����
//
//}
//
//void TestString2()
//{
//	string s;
//	//void reserve(size_t res_aeg = 0) Ϊ�ַ���Ԥ���ռ䣬��ȱʡֵ
//	//1.����reserve�Ƿ��ı�string����ЧԪ�ظ���
//	s.reserve(100);
//	cout << s.size() << endl;//���0��˵��reserve����ı�string����ЧԪ�صĸ���
//	cout << s.capacity() << endl;//���111
//
//	// 2.����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
//	s.reserve(50);
//	cout << s.size() << endl;//���0
//	cout << s.capacity() << endl;//���111��˵��reserve����С��string�ĵײ�ռ��Сʱ���ռ䲻����С
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
////����string�����ķ��ʲ���
//void TestString1()
//{
//	string s1("hello");
//	const string s2("Hello world");
//	cout << s1 << " " << s2 << endl;
//	cout << s1[0] << " " << s2[0] << endl;
//
//	s1[0] = 'H';
//	cout << s1 << endl;
//	// s2[0] = 'h'; �������ʧ�ܣ���Ϊconst���Ͷ������޸�
//
//	//�����ַ��������ַ�ʽ
//	//forѭ������
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	//ʹ�õ���������
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//vector������
//	vector<int> v(10, 5);
//	vector<int>::iterator vit = v.begin();
//	while (vit != v.end())
//	{
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//
//	//list������
//	list<int> l(5, 10);
//	list<int>::iterator lit = l.begin();
//	while (lit != l.end())
//	{
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//
//	//��Χfor������֧�����������ı������ײ�����������ʵ��
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
////�����ַ���
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
////����string�������޸Ĳ���
//
//void TestString()
//{
//	string str;
//	str.push_back(' '); // ��str�����ո�
//	str.append("hello"); // ��str��׷��һ���ַ�"hello"
//	str += 'w'; // ��str��׷��һ���ַ�'w'
//	str += "orld"; // ��str��׷��һ���ַ���"orld"
//	cout << str << endl;
//	cout << str.c_str() << endl; // ��C���Եķ�ʽ��ӡ�ַ���
//
//	//��ȡfile�ĺ�׺
//	
//	string file1("test.cpp");
//	string file2("test.c.zip");
//
//	size_t pos = file1.rfind(".");
//	if (pos != string::npos)//npos��string���һ����̬��Ա����
//	{
//		string suffix(file1.substr(pos,file1.size()-1));//��������һ��suffix���洢.�����λ�õ��ַ���
//		cout << suffix << endl;
//	}
//
//	pos = file2.rfind(".");
//	if (pos != string::npos)//npos��string���һ����̬��Ա����
//	{
//		string suffix(file2.substr(pos, file2.size() - 1));//��������һ��suffix���洢.�����λ�õ��ַ���
//		cout << suffix << endl;
//	}
//   
//}
//void TestString1()
//{
//	// ȡ��url�е�����
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
//	// ɾ��url��Э��ǰ׺
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