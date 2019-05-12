#pragma once

//开散列解决哈希冲突，哈希桶、拉链法
#include <iostream>
#include <vector>
using namespace std;

template<class V>
struct HashNode
{
	//由于之后要用哈希桶封装unordered_map/set，因此这里可能存pair<K,V>也可能存value
	V _valuefiled;
	HashNode<V>* _next;//哈希桶结构是一个vector数组下挂着链表，定义一个指针指向下一个节点的位置

	HashNode(const V& v)
		:_valuefiled(v)
		, _next(nullptr)
	{}
};

//前置声明，由于哈希表需要迭代器，迭代器又需要哈希表
template<class K, class V, class KeyOfValue,class HashFunc>
class HashTable;

//实现哈希表的迭代器
template<class K, class V, class KeyOfValue, class HashFunc>
struct HTIterator
{
	typedef HashNode<V> Node;
	typedef HTIterator<K, V, KeyOfValue, HashFunc> Self;

	Node* _node;//节点指针
	HashTable<K, V, KeyOfValue,HashFunc>* _ht;//哈希表指针

	HTIterator(Node* node, HashTable<K, V, KeyOfValue,HashFunc>* ht)
		:_node(node)
		, _ht(ht)
	{}

	V& operator*()//返回节点的值
	{
		return _node->_valuefiled;
	}
	
	V* operator->()//返回节点指针
	{
		return &_node->_valuefiled;
	}

	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			// 找下一个桶的第一个节点位置
			//size_t i = KeyOfValue()(_node->_valuefiled) % _ht->_table.size();
			size_t i = _ht->HashIndex(KeyOfValue()(_node->_valuefiled), _ht->_table.size());
			++i;
			for (; i < _ht->_table.size(); ++i)
			{
				if (_ht->_table[i] != nullptr)
				{
					_node = _ht->_table[i];
					break;
				}
			}

			if (i == _ht->_table.size())
			{
				_node = nullptr;
			}
		}

		return *this;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
};

//由于之后要用哈希桶封装unordered_map/set，因此这里可能存pair<K,V>也可能存value
//由于pair<K,V>存储比较必须取key才能比较，因此传仿函数取key
//传HashFunc是为了将一个不能直接取模的key类型，eg：string
template<class K, class V, class KeyOfValue, class HashFunc>
class HashTable
{
	typedef HashNode<V> Node;
public:
	template<class K, class V, class KeyOfValue, class HashFunc>
	friend struct HTIterator;
	typedef HTIterator<K, V, KeyOfValue,HashFunc> iterator;

	HashTable()
		:_size(0)
	{}

	iterator begin()
	{
		for (size_t i = 0; i < _table.size(); ++i)
		{
			if (_table[i] != nullptr)
			{
				return iterator(_table[i], this);
			}
		}

		return iterator(nullptr, this);
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	pair<iterator,bool> Insert(const V& v)
	{
		//考虑增容
		CheckCapacity();

		KeyOfValue kov;
		const K& key = kov(v);
		//size_t index = key % _table.size();
		size_t index = HashIndex(key, _table.size());

		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_valuefiled) == key)
				return make_pair(iterator(cur, this), false);
			cur = cur->_next;
		}
		//走到这说明没有相同的元素，可以进行插入，
		//由于哈希桶不规定产生冲突的序列有序,可以进行头插比较简单
		Node* newnode = new Node(v);
		newnode->_next = _table[index];
		_table[index] = newnode;

		++_size;
		return make_pair(iterator(newnode,this),true);
	}

	void CheckCapacity()
	{
		//当负载因子==1时扩容
		if (_table.size() == _size)
		{
			size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			//这里不像之前开散列一样创建一个新的哈希表
			//再调用Insert的原因是旧表的节点可以直接拿到新的vector数组中进行插入
			vector<Node*> newtable;
			newtable.resize(newsize);

			//遍历旧表，在新的vector数组中找到对应位置，将旧表节点插入
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				//将节点从旧表中拆出来，再重新计算节点在新表中的位置进行插入
				while (cur)
				{
					Node* next = cur->_next;
					//size_t index = KeyOfValue()(cur->_valuefiled) % newsize;
					size_t index = HashIndex(KeyOfValue()(cur->_valuefiled), newsize);
					//头插入新表中
					cur->_next = newtable[index];
					newtable[index] = cur;

					cur = next;
				}
				//将原来的表置空
				_table[i] = nullptr;
			}
			//交换新旧两标的资源，出作用域后新表自动调用析构函数释放旧表资源
			_table.swap(newtable);
		}
	}

	Node* Find(const K& key)
	{
		//size_t index = key % _table.size();
		size_t index = HashIndex(key, _table.size());
		Node* cur = _table[index];
		while (cur)
		{
			if (KeyOfValue()(cur->_valuefiled) == key)
				return cur;

			cur = cur->_next;
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		//size_t index = key % _table.size();
		size_t index = HashIndex(key, _table.size());
		Node* cur = _table[index];
		Node* prev = nullptr;

		while (cur)
		{
			if (KeyOfValue()(cur->_valuefiled) == key)
			{
				if (prev == nullptr)//头删
					_table[index] = cur->_next;
				else
					prev->_next = cur->_next;

				delete cur;
				--_size;
				return true;
			}
		}
		return false;
	}

	size_t HashIndex(const K& key, size_t size)
	{
		HashFunc hf;
		return hf(key) % size;
	}
private:
	vector<Node*> _table;//vector中的size为哈希表的大小
	size_t _size;//哈希表中存储的有效元素的个数
};
