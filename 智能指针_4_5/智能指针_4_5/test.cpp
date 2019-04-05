#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mutex>
#include <memory>
#include <thread>
using namespace std;

// 1.C++98 ����ָ��auto_ptr,����Ȩת�ƣ����ȱ�ݣ��Ͻ�ʹ��
// 2.C++11 unique_ptr ���������򵥴ֱ�����ƣ�����ʹ��
// 3.C++11 shared_ptr ���ü�����֧�ֿ���������ʹ��
namespace CXY
{
	// 1.C++98����ָ��auto_ptr,����Ȩת�ƣ����ȱ�ݣ��Ͻ�ʹ��
	template<class T>
	class AutoPtr//ģ��ʵ��auto_ptr
	{
	public:
		AutoPtr(T* Ptr)
			:_Ptr(Ptr)
		{}
		~AutoPtr()
		{
			if (_Ptr)
			{
				cout << "deleteA:" << _Ptr << endl;
				delete _Ptr;
			}
		}

		// CXY::AutoPtr<int> copy(ap);��������
		AutoPtr(AutoPtr<T>& ap)
		{
			_Ptr = ap._Ptr;
			ap._Ptr = nullptr;
		}

		T& operator*()
		{
			return *_Ptr;
		}

		T* operator->()
		{
			return _Ptr;
		}
	private:
		T* _Ptr;
	};


	// 2.C++11 unique_ptr ���������򵥴ֱ�����ƣ�����ʹ��
	template<class T>
	class UniquePtr
	{
	public:
		UniquePtr(T* ptr)
			:_Ptr(ptr)
		{}

		~UniquePtr()
		{
			cout << "deleteU:" << _Ptr << endl;
			delete _Ptr;
		}

		T& operator*()
		{
			return *_Ptr;
		}

		T* operator->()
		{
			return _Ptr;
		}

	private:
		//C++98��������ʽ��ֻ������ʵ��+����Ϊ˽��
		//��������Ϊ˽�У���������Ҳ�޷�ʵ�֣����ܷ�����
		//ֻ���������޴���Ϊ�˷�ֹϵͳ����Ĭ�ϵĿ������캯��
		UniquePtr(UniquePtr<int> const& up);
		UniquePtr<int>& operator=(UniquePtr<int> const& up);
		
		//C++11��������ʽ��delete
		//UniquePtr(UniqurPtr<int> const&)up = delete;
		//UniquePtr<int>& operator=(UniquePtr<int> const& up) = delete;

		T* _Ptr;
	};

	// 3.C++11 shared_ptr ���ü�����֧�ֿ���������ʹ��
	template <class T>
	class SharedPtr
	{
	public:
		SharedPtr(T* ptr)
			:_Ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)//�����̰߳�ȫ���⣬��ֻ֤��һ���̶߳�pcount����++
		{}
		~SharedPtr()
		{
			/*if (--(*_pcount) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;
			}*/
			Release();
		}

		//CXY::SharedPtr<int> copy(sp);
		SharedPtr(SharedPtr<int> const& sp)
			:_Ptr(sp._Ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			if (_Ptr)//����һ����ָ�����ü���
				AddRefcount();
		}

		//sp = sp1
		SharedPtr<int>& operator=(SharedPtr<int> const& sp)
		{//�ȼ��sp�Ƿ������һ��ָ����Դ�Ķ�����������ͷ���Դ
			if (_Ptr != sp._Ptr)//���������ͬ�Ķ���Ž��и�ֵ
			{
				Release();//�ͷ�ԭ���Ŀռ䣬ָ���µĿռ�

				_Ptr = sp._Ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				AddRefcount();
			}

			return *this;
		}

		int AddRefcount()
		{
			//��֤��ԭ�Ӳ���
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();

			return *_pcount;
		}

		void Release()
		{
			bool deleteflag = false;
			//���ü�����һ���������0�������һ��ʹ����Դ�Ķ��󣬾��ͷ���Դ
			if (--(*_pcount) == 0)
			{
				cout << "deleteS:" << _Ptr << endl;
				delete _Ptr;
				delete _pcount;
				deleteflag = true;
			}
			if (deleteflag == true)//��������һ������Ҳ������Դ�ͷ�
				delete _pmtx;
		}
		T& operator*()
		{
			return *_Ptr;
		}

		T* operator->()
		{
			return _Ptr;
		}

		int use_count()
		{
			return *_pcount;
		}
	private:
		T* _Ptr;
		int* _pcount;
		mutex* _pmtx;
	};
}


void TestAutoPtr()
{
	CXY::AutoPtr<int> ap(new int);
	CXY::AutoPtr<int> copy(ap);
}

void TestUniquePtr()
{
	CXY::UniquePtr<int> up(new int);
	//BIT::UniquePtr<int> copy(ap);
}

void TestSharedPtr()
{
	CXY::SharedPtr<int> sp(new int);
	CXY::SharedPtr<int> copy(sp);

	cout << sp.use_count() << endl;

	CXY::SharedPtr<int> sp1(new int);
	CXY::SharedPtr<int> sp2(sp1);

	cout << sp.use_count() << endl;

	//sp = sp1;
	//copy = sp1;

	sp1 = sp1;
	sp1 = sp2;
}


int main()
{
	//TestAutoPtr();
	//TestUniquePtr();
	TestSharedPtr();
	return 0;
}