#include <iostream>
#include <algorithm>//算法头文件
using namespace std;

namespace CXY
{
	template<class T>
	struct _ListNode //封装一个节点
	{
		_ListNode<T>* _prev;
		_ListNode<T>* _next;

		T _data;

		_ListNode(const T& value = T())//构造函数带缺省值
			:_data(value)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};

	// typedef __ListIterator<T, T&, T*> iterator;
	// typedef __ListIterator<T, const T&, const T*> const_iterator;
	template<class T,class Ref,class Ptr>
	struct _Listiterator//封装一个迭代器
	{
		typedef _ListNode<T> Node;
		typedef _Listiterator<T, Ref, Ptr> self;
		
		Node* _node;

		_Listiterator()
			:_node(nullptr)
		{}
		_Listiterator(Node* newnode)
			:_node(newnode)
		{}

		Ref operator*()//迭代器解引用
		{
			return _node->_data;
		}

		Ptr operator->()//当迭代器指向一个自定义类型时
		{
			return &_node->_data
		}

		self& operator++()//迭代器++，返回下一个位置的迭代器
		{
			_node = _node->_next;
			return *this;
		}

		bool operator!=(const self& self)
		{
			return _node != self._node;
		}
	
	};

	template<class T>
	class List
	{
		typedef _ListNode<T> Node;
		
	public:
		typedef _Listiterator<T, T&, T*> iterator;//迭代器
		typedef _Listiterator<T, const T&, const T*> const_iterator;//const迭代器

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator cbegin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator cend() const
		{
			return const_iterator(_head);
		}

		List()//构造函数
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		~List()//析构函数
		{}
		//拷贝构造函数l1(l2)
		List(const List<T>& l);
		//重载赋值运算符= l1 = l2 = l3;
		List<T>& operator=(const List<T>& l);

		void PushBack(const T& value)//尾插
		{
			Node* newnode = new Node(value);//创建一个新的结点

			newnode->_next = _head;
			newnode->_prev = _head->_prev;

			_head->_prev = newnode;
			newnode->_prev->_next = newnode;
		}

		void PopBack()//尾删
		{
			Node* cur = _head->_prev;

			if (cur != _head)
			{
				_head->_prev = cur->_prev;
				cur->_prev->_next = _head;
				delete cur;
			}
		}
		void PushFront(const T& value)//头插
		{
			Insert(begin(), value);
		}
		void PopFront()
		{
			Erase(begin());
		}

		//在随机位置pos前插入一个value
		void Insert(iterator pos, const T& value)
		{
			Node* newnode = new Node(value);
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			newnode->_next = cur;
			newnode->_prev = prev;

			prev->_next = newnode;
			cur->_prev = newnode;
		}

		iterator Erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* next = cur->_next;

			cur->_prev->_next = next;
			next->_prev = cur->_prev;
			delete cur;

			return iterator(next);
		}

	private:
		Node* _head;
		
	};

	void TestList1()//测试构造函数，PushBack,PopBack,迭代器的使用
	{
		List<int> l;
		l.PushBack(1);
		l.PushBack(2);
		l.PushBack(3);
		l.PushBack(4);
		l.PushBack(5);

		l.PopBack();

		
		List<int>::iterator it = l.begin();

		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void TestList2()//测试Insert，Erase，和const迭代器
	{
		List<int> l;
		l.PushBack(1);
		l.PushBack(2);
		l.PushBack(3);
		l.PushBack(4);
		l.PushBack(5);

		//List<int>::iterator pos = find(l.begin(), l.end(), 3);
		//不能使用算法中的find，find对接收的迭代器有一定要求
		auto pos = l.begin();
		l.Insert(pos, 30);//调用Insert

		//++pos;
		l.Erase(pos);
		List<int>::iterator cit = l.begin();
		while (cit != l.end())
		{
			cout << *cit << " ";
			++cit;
		}
		cout << endl;
	}


	void TestList3()//测试PushFront,PopFront
	{
		List<int> l;
		l.PushFront(1);
		l.PushFront(2);
		l.PushFront(3);
		l.PushFront(4);

		l.PopFront();

		List<int>::iterator cit = l.begin();
		while (cit != l.end())
		{
			cout << *cit << " ";
			++cit;
		}
		cout << endl;

	}
}