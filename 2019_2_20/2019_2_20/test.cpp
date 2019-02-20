#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//inline int ADD(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 3;
//	int b = 4;
//	int c = ADD(a, b);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//void GetMemeory(char *p)
//{
//	p = (char *)malloc(100);
//}
//void Test()
//{
//	char *str = NULL;
//	GetMemeory(str);
//	strcpy(str, "Thunder");
//	strcat(str + 2, "Downloader");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//设计一个类，该类只能在堆上创建对象
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly() {}

	// C++98
	// 1.只声明,不实现。因为实现可能会很麻烦，而你本身不需要
	// 2.声明成私有
	HeapOnly(const HeapOnly&);

		// or

		// C++11
		HeapOnly(const HeapOnly&) = delete;
};

//设计一个类，该类只能在栈上创建对象
class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly() {}
};class StackOnly
{
public:
	StackOnly() {}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};//单例模式实现模式// 饿汉模式
// 优点：简单
// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}

private:
	// 构造函数私有
	Singleton(){};

	// C++98 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	// or

	// C++11
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;

	static Singleton m_instance;
};
Singleton Singleton::m_pInstance; // 在程序入口之前就完成单例对象的初始化

//单例模式实现模式
// 懒汉
// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
// 缺点：复杂
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class Singleton
{
public:
	static Singleton* GetInstance() {
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		if (nullptr == m_pInstance) {
			m_mtx.lock();
			if (nullptr == m_pInstance) {				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// 实现一个内嵌垃圾回收类
	class CGarbo {
	public:
		~CGarbo(){
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:
	// 构造函数私有
	Singleton(){};
	// 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	static Singleton* m_pInstance; // 单例对象指针
	static mutex m_mtx; //互斥锁
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}
// 多线程环境下演示上面GetInstance()加锁和不加锁的区别。
int main()
{
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
}