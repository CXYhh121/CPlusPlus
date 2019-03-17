#include <iostream>
#include <algorithm>//�㷨ͷ�ļ�
using namespace std;

namespace CXY
{
	template<class T>
	struct _ListNode //��װһ���ڵ�
	{
		_ListNode<T>* _prev;
		_ListNode<T>* _next;

		T _data;

		_ListNode(const T& value = T())//���캯����ȱʡֵ
			:_data(value)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};

	// typedef __ListIterator<T, T&, T*> iterator;
	// typedef __ListIterator<T, const T&, const T*> const_iterator;
	template<class T,class Ref,class Ptr>
	struct _Listiterator//��װһ��������
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

		Ref operator*()//������������
		{
			return _node->_data;
		}

		Ptr operator->()//��������ָ��һ���Զ�������ʱ
		{
			return &_node->_data
		}

		self& operator++()//������++��������һ��λ�õĵ�����
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
		typedef _Listiterator<T, T&, T*> iterator;//������
		typedef _Listiterator<T, const T&, const T*> const_iterator;//const������

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

		List()//���캯��
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		~List()//��������
		{}
		//�������캯��l1(l2)
		List(const List<T>& l);
		//���ظ�ֵ�����= l1 = l2 = l3;
		List<T>& operator=(const List<T>& l);

		void PushBack(const T& value)//β��
		{
			Node* newnode = new Node(value);//����һ���µĽ��

			newnode->_next = _head;
			newnode->_prev = _head->_prev;

			_head->_prev = newnode;
			newnode->_prev->_next = newnode;
		}

		void PopBack()//βɾ
		{
			Node* cur = _head->_prev;

			if (cur != _head)
			{
				_head->_prev = cur->_prev;
				cur->_prev->_next = _head;
				delete cur;
			}
		}
		void PushFront(const T& value)//ͷ��
		{
			Insert(begin(), value);
		}
		void PopFront()
		{
			Erase(begin());
		}

		//�����λ��posǰ����һ��value
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

	void TestList1()//���Թ��캯����PushBack,PopBack,��������ʹ��
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

	void TestList2()//����Insert��Erase����const������
	{
		List<int> l;
		l.PushBack(1);
		l.PushBack(2);
		l.PushBack(3);
		l.PushBack(4);
		l.PushBack(5);

		//List<int>::iterator pos = find(l.begin(), l.end(), 3);
		//����ʹ���㷨�е�find��find�Խ��յĵ�������һ��Ҫ��
		auto pos = l.begin();
		l.Insert(pos, 30);//����Insert

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


	void TestList3()//����PushFront,PopFront
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