#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mutex>
#include <memory>
#include <thread>
using namespace std;

// 1.C++98 智能指针auto_ptr,管理权转移，设计缺陷，严禁使用
// 2.C++11 unique_ptr 防拷贝，简单粗暴的设计，鼓励使用
// 3.C++11 shared_ptr 引用计数，支持拷贝，鼓励使用
namespace CXY
{
	// 1.C++98智能指针auto_ptr,管理权转移，设计缺陷，严禁使用
	template<class T>
	class AutoPtr//模拟实现auto_ptr
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

		// CXY::AutoPtr<int> copy(ap);拷贝构造
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


	// 2.C++11 unique_ptr 防拷贝，简单粗暴的设计，鼓励使用
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
		//C++98防拷贝方式，只声明不实现+声明为私有
		//必须声明为私有，这样类外也无法实现，才能防拷贝
		//只声明编译无错误，为了防止系统生成默认的拷贝构造函数
		UniquePtr(UniquePtr<int> const& up);
		UniquePtr<int>& operator=(UniquePtr<int> const& up);
		
		//C++11防拷贝方式，delete
		//UniquePtr(UniqurPtr<int> const&)up = delete;
		//UniquePtr<int>& operator=(UniquePtr<int> const& up) = delete;

		T* _Ptr;
	};

	// 3.C++11 shared_ptr 引用计数，支持拷贝，鼓励使用
	template <class T>
	class SharedPtr
	{
	public:
		SharedPtr(T* ptr)
			:_Ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)//处理线程安全问题，保证只有一个线程对pcount进行++
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
			if (_Ptr)//若是一个空指针则不用计数
				AddRefcount();
		}

		//sp = sp1
		SharedPtr<int>& operator=(SharedPtr<int> const& sp)
		{//先检查sp是否是最后一个指向资源的对象，如果是先释放资源
			if (_Ptr != sp._Ptr)//如果不是相同的对象才进行赋值
			{
				Release();//释放原来的空间，指向新的空间

				_Ptr = sp._Ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				AddRefcount();
			}

			return *this;
		}

		int AddRefcount()
		{
			//保证是原子操作
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();

			return *_pcount;
		}

		void Release()
		{
			bool deleteflag = false;
			//引用计数减一，如果减到0即是最后一个使用资源的对象，就释放资源
			if (--(*_pcount) == 0)
			{
				cout << "deleteS:" << _Ptr << endl;
				delete _Ptr;
				delete _pcount;
				deleteflag = true;
			}
			if (deleteflag == true)//如果是最后一个对象，也把锁资源释放
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