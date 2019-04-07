#define _CRT_SECURE_NO_WARNINGS

//class Date
//{
//private:
//	int _year;
//	int _mouth;
//	int _day;
//};
//template <class T>
//class SharedPtr
//{
//public:
//	SharedPtr(T* ptr)
//		:_Ptr(ptr)
//		, _pcount(new int(1))
//		, _pmtx(new mutex)//处理线程安全问题，保证只有一个线程对pcount进行++
//	{}
//	~SharedPtr()
//	{
//		/*if (--(*_pcount) == 0)
//		{
//		cout << "delete:" << _ptr << endl;
//		delete _ptr;
//		delete _pcount;
//		}*/
//		Release();
//	}
//
//	//CXY::SharedPtr<int> copy(sp);
//	SharedPtr(SharedPtr<int> const& sp)
//		:_Ptr(sp._Ptr)
//		, _pcount(sp._pcount)
//		, _pmtx(sp._pmtx)
//	{
//		if (_Ptr)//若是一个空指针则不用计数
//			AddRefcount();
//	}
//
//	//sp = sp1
//	SharedPtr<int>& operator=(SharedPtr<int> const& sp)
//	{//先检查sp是否是最后一个指向资源的对象，如果是先释放资源
//		if (_Ptr != sp._Ptr)//如果不是相同的对象才进行赋值
//		{
//			Release();//释放原来的空间，指向新的空间
//
//			_Ptr = sp._Ptr;
//			_pcount = sp._pcount;
//			_pmtx = sp._pmtx;
//
//			AddRefcount();
//		}
//
//		return *this;
//	}
//
//	int AddRefcount()
//	{
//		//保证是原子操作
//		_pmtx->lock();
//		++(*_pcount);
//		_pmtx->unlock();
//
//		return *_pcount;
//	}
//
//	void Release()
//	{
//		bool deleteflag = false;
//		//引用计数减一，如果减到0即是最后一个使用资源的对象，就释放资源
//		if (--(*_pcount) == 0)
//		{
//			cout << "deleteS:" << _Ptr << endl;
//			delete _Ptr;
//			delete _pcount;
//			deleteflag = true;
//		}
//		if (deleteflag == true)//如果是最后一个对象，也把锁资源释放
//			delete _pmtx;
//	}
//	T& operator*()
//	{
//		return *_Ptr;
//	}
//
//	T* operator->()
//	{
//		return _Ptr;
//	}
//
//	int use_count()
//	{
//		return *_pcount;
//	}
//private:
//	T* _Ptr;
//	int* _pcount;
//	mutex* _pmtx;
//};

//void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
//{
//	cout << sp.Get() << endl;
//	for (size_t i = 0; i < n; ++i)
//	{
//		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
//		//SharedPtr<Date> copy(sp);
//		// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最
//		//终看到的结果，并一定是加了2n
//			copy->_year++;
//		copy->_month++;
//		copy->_day++;
//	}
//}
//int main()
//{
//	SharedPtr<Date> p(new Date);
//	cout << p.Get() << endl;
//
//	const size_t n = 100;
//	thread t1(SharePtrFunc, p, n);
//	thread t2(SharePtrFunc, p, n);
//	t1.join();
//	t2.join();
//	cout << p->_year << endl;
//	cout << p->_month << endl;
//	cout << p->_day << endl;
//	return 0;
//}


//#include <iostream>
//#include <memory>
//using namespace std;

//struct ListNode
//{
//	int _data;
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl; 
//	}
//};
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}



// 解决方案：在引用计数的场景下，把节点中的_prev和_next改成weak_ptr就可以了
// 原理就是，node1->_next = node2;和node2->_prev = node1;时weak_ptr的_next和_prev不会增加
//node1和node2的引用计数。

//struct ListNode
//{
//	int _data;
//	weak_ptr<ListNode> _prev;
//	weak_ptr<ListNode> _next;
//	~ListNode(){ cout << "~ListNode()" << endl; }
//};
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}