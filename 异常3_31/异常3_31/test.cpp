#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;

//void Test()
//{
//	 string str =  "�����쳣!";
//	 throw str;
//}
//
//int main()
//{
//	try
//	{
//		Test();
//	}
//	catch (string& s)
//	{
//		cout << s << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪����" << endl;
//	}
//	return 0;
//}


//�쳣��ʹ��
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		//throw 5;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//
//	int i = 0;
//}
//
//
//int main()
//{
//	try 
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...){
//		cout << "unkown exception" << endl;
//	}
//	return 0;
//}


//catch(...)�ɲ������������쳣����ֹ�׳����쳣δ�������³�����������
//#include <iostream>
//#include <string>
//
//using namespace std;
//void Test()
//{
//	//throw 5;
//	//throw 1.111111;
//	throw "�������";
//}
//
//int main()
//{
//	try
//	{
//		Test();
//	}
//	catch (...)
//	{
//		cout << "δ֪����" << endl;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//void Func()
//{
//	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
//	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
//	// �����׳�ȥ��
//	int* array = new int[10];
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw;
//	}
//	// ...
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	return 0;
//}


//�쳣�İ�ȫ����

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void Test()
//{
//	char *p = new char[100];
//
//	 string str = "�����쳣";
//	 throw str;
//
//	delete[] p;
//}
//
//int main()
//{
//	try
//	{
//		Test();
//	}
//	catch (string& s)
//	{
//		cout << s << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪����" << endl;
//	}
//	return 0;
//}


//�Զ����쳣��ϵ����
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// ������������ͨ��ʹ�õ��쳣�̳���ϵ
//class Exception
//{
//protected:
//	string _errmsg;
//	int _id;
//	int _line;
//
//public:
//	Exception(string err, int id, int line)
//		:_errmsg(err)
//		, _id(id)
//		, _line(line)
//	{}
//
//
//};
//class SqlException : public Exception
//{};
//class CacheException : public Exception
//{};
//class HttpServerException : public Exception
//{};
//int main()
//{
//	try{
//		// server.Start();
//		// �׳����������������
//	}
//	catch (const Exception& e) // ���ﲶ�������Ϳ���
//	{
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}
//	return 0;
//}


//C++��׼����쳣��ϵʹ�ò���
//#include <iostream>
//#include <vector>
//#include <exception>
//using namespace std;
//
//int main()
//{
//	try
//	{
//		vector<int> v(10, 5);
//
//		//��ʱ����Խ����׳��쳣
//		v.at(10);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪����" << endl;
//	}
//	return 0;
//}

//α���룬����ִ��
//template<class T>
//class EG
//{
//public:
//	
//	T& operator[](size_t pos)
//	{
//		if (pos < Size())
//			return _array[pos];
//		else
//		{
//			throw out_of_range();
//		}
//	}
//
//};




