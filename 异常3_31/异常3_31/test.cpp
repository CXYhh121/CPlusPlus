#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;

//void Test()
//{
//	 string str =  "程序异常!";
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
//		cout << "未知错误" << endl;
//	}
//	return 0;
//}


//异常的使用
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
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


//catch(...)可捕获任意类型异常，防止抛出的异常未被捕获导致程序崩溃的情况
//#include <iostream>
//#include <string>
//
//using namespace std;
//void Test()
//{
//	//throw 5;
//	//throw 1.111111;
//	throw "程序崩溃";
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
//		cout << "未知错误" << endl;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//void Func()
//{
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
//	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
//	// 重新抛出去。
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


//异常的安全问题

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void Test()
//{
//	char *p = new char[100];
//
//	 string str = "程序异常";
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
//		cout << "未知错误" << endl;
//	}
//	return 0;
//}


//自定义异常体系测试
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// 服务器开发中通常使用的异常继承体系
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
//		// 抛出对象都是派生类对象
//	}
//	catch (const Exception& e) // 这里捕获父类对象就可以
//	{
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}
//	return 0;
//}


//C++标准库的异常体系使用测试
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
//		//此时访问越界会抛出异常
//		v.at(10);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知错误" << endl;
//	}
//	return 0;
//}

//伪代码，不能执行
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




