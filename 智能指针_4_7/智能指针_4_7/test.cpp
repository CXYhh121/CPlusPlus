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
//		, _pmtx(new mutex)//�����̰߳�ȫ���⣬��ֻ֤��һ���̶߳�pcount����++
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
//		if (_Ptr)//����һ����ָ�����ü���
//			AddRefcount();
//	}
//
//	//sp = sp1
//	SharedPtr<int>& operator=(SharedPtr<int> const& sp)
//	{//�ȼ��sp�Ƿ������һ��ָ����Դ�Ķ�����������ͷ���Դ
//		if (_Ptr != sp._Ptr)//���������ͬ�Ķ���Ž��и�ֵ
//		{
//			Release();//�ͷ�ԭ���Ŀռ䣬ָ���µĿռ�
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
//		//��֤��ԭ�Ӳ���
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
//		//���ü�����һ���������0�������һ��ʹ����Դ�Ķ��󣬾��ͷ���Դ
//		if (--(*_pcount) == 0)
//		{
//			cout << "deleteS:" << _Ptr << endl;
//			delete _Ptr;
//			delete _pcount;
//			deleteflag = true;
//		}
//		if (deleteflag == true)//��������һ������Ҳ������Դ�ͷ�
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
//		// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
//		//SharedPtr<Date> copy(sp);
//		// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ�������
//		//�տ����Ľ������һ���Ǽ���2n
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



// ��������������ü����ĳ����£��ѽڵ��е�_prev��_next�ĳ�weak_ptr�Ϳ�����
// ԭ����ǣ�node1->_next = node2;��node2->_prev = node1;ʱweak_ptr��_next��_prev��������
//node1��node2�����ü�����

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