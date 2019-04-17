#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace CXY
{
	//��ֵ��
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
	{//���Լ�ֱ��ָ�����͹���Ҫ�򵥣�ͨ��ģ�����Ƶ�����������
		return pair<K, V>(k, v);//�����������󲢷���
	}

	//������������֧����(Insert)ɾ(Erase)��(Find)
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
		BSTree()//���캯��
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
		BSTree(const BSTree<K,V>& tree)//�������캯��
		{
			_root = CopyTree(tree._root);//�޷�ֱ�ӵݹ飬����һ���Ӻ������еݹ�
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
		~BSTree()//��������
		{
			Destroy(_root);//�޷�ֱ�ӵݹ飬��˴���һ��Destroy����
		}

		bool Insert(const pair<K,V>& kv)//����һ��Ԫ��
		{
			if (_root == nullptr)//����Ϊ��ʱ����ֱ�Ӳ���
			{
				_root = new Node(kv);
				return true;
			}

			//����Ԫ���ڶ�����������Ӧ�ò����λ��
			Node* cur = _root;
			Node* parent = nullptr;//��¼cur��˫�׽ڵ㣬��������½ڵ�

			while (cur)
			{
				parent = cur;
				if (kv.first > cur->_kv.first)
					cur = cur->_right;
				else if (kv.first < cur->_kv.first)
					cur = cur->_left;
				else//Ԫ���������Ѿ����ڣ�����false
					return false;
			}
			//�ҵ���Ӧλ�ã�����Ԫ��
			cur = new Node(kv);
			if (kv.first > parent->_kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;

			return true;
		}

		Node* Find(const K& key)//����һ��Ԫ�أ�ʱ�临�Ӷ�ΪO(logN)
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

		bool Erase(const pair<K,V>& kv)//ɾ��һ��Ԫ��
		{
			if (_root == nullptr)//�����Ϊ�գ�ɾ��ʧ��
				return false;

			//����Ԫ���ڶ�����������Ӧ��ɾ����λ��
			Node* cur = _root;
			Node* parent = nullptr;//��¼cur��˫�׽ڵ㣬��������½ڵ�

			while (cur)
			{
				if (kv.first > cur->_kv.first)//���ǲ��ҵ�Ԫ�ش���cur��ֵ����cur����������
				{
					parent = cur;
					cur = cur->_right;
				}

				else if (kv.first < cur->_kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else//�Ѿ��ҵ�������ѭ��
					break;
			}

			Node* del = cur;
			if (cur == nullptr)
				return false;

			//1���ڵ���Ϊ�գ�����ָ��ڵ���ң�ɾ���ڵ�
			if (cur->_left == nullptr)
			{
				if (parent == nullptr)
					_root = cur->_right;
				else
				{
					if (parent->_left == cur)//���cur�Ǹ��׽ڵ������
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
			}

			//2���ڵ���Ϊ�գ�����ָ��ڵ����ɾ���ڵ�
			else if (cur->_right == nullptr)
			{
				if (parent == nullptr)
					_root = cur->_left;
				else
				{
					if (parent->_left == cur)//���cur�Ǹ��׽ڵ������
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
			}

			//3���ڵ����Ҿ���Ϊ�գ������������ҽڵ��������������ڵ���Ϊ����ڵ���ýڵ㽻��֮����ɾ��
			else
			{
				Node* P_replace = cur;//��������ڵ��˫�׽ڵ�
				Node* replace = cur->_left;//�����������ҽڵ�

				while (replace->_right)
				{
					P_replace = replace;
					replace = replace->_right;
				}

				cur->_kv = replace->_kv;//����Ҫɾ���ڵ��ֵ������ڵ��ֵ

				//�ж�����ڵ�����˫�׽ڵ�����ӻ����Һ���
				//���������ҽڵ���Һ��ӱض�Ϊ��
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
		//���������������ʱ��Ҫ����������������_rootΪ���˽�г�Ա�������ⲻ�ɼ�
		//�����������ò���Ҫ�����Ľӿڣ����ڴ˽ӿ��е�����Ҫ�����ĺ��������ڿ��Ե���˽�г�Ա
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
		BSTree<int, int> copy(t);//��������
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

	void TestBSTreeKV2()//��ģ��ʵ��һ���ֵ�
	{
		BSTree<string, string> dict;
		dict.Insert(pair<string, string>("sort", "����"));
		dict.Insert(std::make_pair("string", "�ַ���"));
		dict.Insert(std::make_pair("left", "���"));

		string str;
		while (cin >> str)
		{
			BSTNode<string, string>* node = dict.Find(str);
			if (node)
			{
				cout << "���룺" << node->_kv.second << endl;
			}
			else
			{
				cout << "�����ڸôʣ�����������" << endl;
			}
		}
	}
}