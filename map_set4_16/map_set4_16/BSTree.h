#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace CXY
{
	//键值对
	//template <class K, class V>
	//struct pair
	//{
	//	K first;
	//	V second;
	//	pair(const K& k,const V& v)
	//		:first(k)
	//      , second(v)
	//};

	template <class K, class V>
	inline pair<K, V>& make_pair(const K& k, const V& v)
	{//比自己直接指定类型构造要简单，通过模板来推导参数的类型
		return pair<K, V>(k, v);//构造匿名对象并返回
	}

	//二叉搜索树，支持增(Insert)删(Erase)查(Find)
	template <class K,class V>
	struct BSTNode
	{
		BSTNode(const pair<K,V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _kv(kv)
		{}

		BSTNode<K,V>* _left;
		BSTNode<K,V>* _right;
		pair<K, V> _kv;
	};

	template <class K,class V>
	class BSTree
	{
		typedef BSTNode<K,V> Node;
	public:
		BSTree()//构造函数
			:_root(nullptr)
		{}

		Node* CopyTree(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			Node* copyroot = new Node(root->_kv);
			copyroot->_left = CopyTree(root->_left);
			copyroot->_right = CopyTree(root->_right);

			return copyroot;
		}
		BSTree(const BSTree<K,V>& tree)//拷贝构造函数
		{
			_root = CopyTree(tree._root);//无法直接递归，创建一个子函数进行递归
		}

		BSTree<K,V>& operator=(const BSTree<K, V>& tree)
		{
			if (this != &tree)
			{
				Destroy(this->_root);
				this->_root = CopyTree(tree._root);
			}
			return *this;
		}
		void Destroy(Node* root)
		{
			if (root == nullptr)
				return;
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}
		~BSTree()//析构函数
		{
			Destroy(_root);//无法直接递归，因此创建一个Destroy函数
		}

		bool Insert(const pair<K,V>& kv)//插入一个元素
		{
			if (_root == nullptr)//若树为空时，可直接插入
			{
				_root = new Node(kv);
				return true;
			}

			//查找元素在二叉搜索树中应该插入的位置
			Node* cur = _root;
			Node* parent = nullptr;//记录cur的双亲节点，方便插入新节点

			while (cur)
			{
				parent = cur;
				if (kv.first > cur->_kv.first)
					cur = cur->_right;
				else if (kv.first < cur->_kv.first)
					cur = cur->_left;
				else//元素在树中已经存在，返回false
					return false;
			}
			//找到对应位置，插入元素
			cur = new Node(kv);
			if (kv.first > parent->_kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;

			return true;
		}

		Node* Find(const K& key)//查找一个元素，时间复杂度为O(logN)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_kv.first)
					cur = cur->_right;
				else if (key < cur->_kv.first)
					cur = cur->_left;
				else
					return cur;
			}
			return nullptr;
		}

		bool Erase(const pair<K,V>& kv)//删除一个元素
		{
			if (_root == nullptr)//如果树为空，删除失败
				return false;

			//查找元素在二叉搜索树中应该删除的位置
			Node* cur = _root;
			Node* parent = nullptr;//记录cur的双亲节点，方便插入新节点

			while (cur)
			{
				if (kv.first > cur->_kv.first)//若是查找的元素大于cur的值，到cur的右树中找
				{
					parent = cur;
					cur = cur->_right;
				}

				else if (kv.first < cur->_kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else//已经找到，跳出循环
					break;
			}

			Node* del = cur;
			if (cur == nullptr)
				return false;

			//1、节点左为空，父亲指向节点的右，删除节点
			if (cur->_left == nullptr)
			{
				if (parent == nullptr)
					_root = cur->_right;
				else
				{
					if (parent->_left == cur)//如果cur是父亲节点的左孩子
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
			}

			//2、节点右为空，父亲指向节点的左，删除节点
			else if (cur->_right == nullptr)
			{
				if (parent == nullptr)
					_root = cur->_left;
				else
				{
					if (parent->_left == cur)//如果cur是父亲节点的左孩子
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
			}

			//3、节点左右均不为空，找左树的最右节点或是右树的最左节点作为替代节点与该节点交换之后再删除
			else
			{
				Node* P_replace = cur;//保存替代节点的双亲节点
				Node* replace = cur->_left;//找左树的最右节点

				while (replace->_right)
				{
					P_replace = replace;
					replace = replace->_right;
				}

				cur->_kv = replace->_kv;//交换要删除节点的值与替代节点的值

				//判断替代节点是其双亲节点的左孩子还是右孩子
				//左树的最右节点的右孩子必定为空
				if (P_replace->_left == replace)
					P_replace->_left = replace->_left;
				else
					P_replace->_right = replace->_left;

				del = replace;
			}
			delete del;
			return true;
		}

		void _Inorder(Node* root)
		{
			if (root == nullptr)
				return;
			_Inorder(root->_left);
			cout << root->_kv.first << ":" << root->_kv.second << " ";
			_Inorder(root->_right);
		}
		//本来调用中序遍历时需要传参数，但是由于_root为类的私有成员，在类外不可见
		//因此在类外调用不需要参数的接口，并在此接口中调用需要参数的函数，类内可以调用私有成员
		void Inorder()
		{
			_Inorder(_root);
		}
	private:
		Node* _root;
	};

	void TestBSTree()
	{
		BSTree<int, int> t;
		int a[] = { 4, 5, 6, 2, 3, 8, 9, 0 };
		for (auto e : a)
		{
			t.Insert(pair<int, int>(e, e));
		}
		t.Inorder();
		BSTree<int, int> copy(t);//拷贝构造
		//copy = t;//operator=
		
		copy.Inorder();
	}
	void TestBSTreeKV1()
	{
		BSTree<int, int> t;
		int a[] = { 4, 5, 6, 2, 3, 8, 9, 0 };
		for (auto e : a)
		{
			t.Insert(pair<int, int>(e, e));
		}

		t.Inorder();
	}

	void TestBSTreeKV2()//简单模拟实现一个字典
	{
		BSTree<string, string> dict;
		dict.Insert(pair<string, string>("sort", "排序"));
		dict.Insert(std::make_pair("string", "字符串"));
		dict.Insert(std::make_pair("left", "左边"));

		string str;
		while (cin >> str)
		{
			BSTNode<string, string>* node = dict.Find(str);
			if (node)
			{
				cout << "翻译：" << node->_kv.second << endl;
			}
			else
			{
				cout << "不存在该词，请重新输入" << endl;
			}
		}
	}
}