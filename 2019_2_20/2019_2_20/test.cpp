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

//���һ���࣬����ֻ���ڶ��ϴ�������
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
	// 1.ֻ����,��ʵ�֡���Ϊʵ�ֿ��ܻ���鷳�����㱾����Ҫ
	// 2.������˽��
	HeapOnly(const HeapOnly&);

		// or

		// C++11
		HeapOnly(const HeapOnly&) = delete;
};

//���һ���࣬����ֻ����ջ�ϴ�������
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
};//����ģʽʵ��ģʽ// ����ģʽ
// �ŵ㣺��
// ȱ�㣺���ܻᵼ�½�����������������ж�����������ʵ������˳��ȷ����class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}

private:
	// ���캯��˽��
	Singleton(){};

	// C++98 ������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	// or

	// C++11
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;

	static Singleton m_instance;
};
Singleton Singleton::m_pInstance; // �ڳ������֮ǰ����ɵ�������ĳ�ʼ��

//����ģʽʵ��ģʽ
// ����
// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
// ȱ�㣺����
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class Singleton
{
public:
	static Singleton* GetInstance() {
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		if (nullptr == m_pInstance) {
			m_mtx.lock();
			if (nullptr == m_pInstance) {				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// ʵ��һ����Ƕ����������
	class CGarbo {
	public:
		~CGarbo(){
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
private:
	// ���캯��˽��
	Singleton(){};
	// ������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	static Singleton* m_pInstance; // ��������ָ��
	static mutex m_mtx; //������
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}
// ���̻߳�������ʾ����GetInstance()�����Ͳ�����������
int main()
{
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
}