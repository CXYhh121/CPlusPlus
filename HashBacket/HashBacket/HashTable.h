#pragma once

//��ɢ�н����ϣ��ͻ����ϣͰ��������
#include <iostream>
#include <vector>
using namespace std;

template<class V>
struct HashNode
{
	//����֮��Ҫ�ù�ϣͰ��װunordered_map/set�����������ܴ�pair<K,V>Ҳ���ܴ�value
	V _valuefiled;
	HashNode<V>* _next;//��ϣͰ�ṹ��һ��vector�����¹�����������һ��ָ��ָ����һ���ڵ��λ��

	HashNode(const V& v)
		:_valuefiled(v)
		, _next(nullptr)
	{}
};

//ǰ�����������ڹ�ϣ����Ҫ������������������Ҫ��ϣ��
template<class K, class V, class KeyOfValue,class HashFunc>
class HashTable;

//ʵ�ֹ�ϣ��ĵ�����
template<class K, class V, class KeyOfValue, class HashFunc>
struct HTIterator
{
	typedef HashNode<V> Node;
	typedef HTIterator<K, V, KeyOfValue, HashFunc> Self;

	Node* _node;//�ڵ�ָ��
	HashTable<K, V, KeyOfValue,HashFunc>* _ht;//��ϣ��ָ��

	HTIterator(Node* node, HashTable<K, V, KeyOfValue,HashFunc>* ht)
		:_node(node)
		, _ht(ht)
	{}

	V& operator*()//���ؽڵ��ֵ
	{
		return _node->_valuefiled;
	}
	
	V* operator->()//���ؽڵ�ָ��
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
			// ����һ��Ͱ�ĵ�һ���ڵ�λ��
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

//����֮��Ҫ�ù�ϣͰ��װunordered_map/set�����������ܴ�pair<K,V>Ҳ���ܴ�value
//����pair<K,V>�洢�Ƚϱ���ȡkey���ܱȽϣ���˴��º���ȡkey
//��HashFunc��Ϊ�˽�һ������ֱ��ȡģ��key���ͣ�eg��string
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
		//��������
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
		//�ߵ���˵��û����ͬ��Ԫ�أ����Խ��в��룬
		//���ڹ�ϣͰ���涨������ͻ����������,���Խ���ͷ��Ƚϼ�
		Node* newnode = new Node(v);
		newnode->_next = _table[index];
		_table[index] = newnode;

		++_size;
		return make_pair(iterator(newnode,this),true);
	}

	void CheckCapacity()
	{
		//����������==1ʱ����
		if (_table.size() == _size)
		{
			size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			//���ﲻ��֮ǰ��ɢ��һ������һ���µĹ�ϣ��
			//�ٵ���Insert��ԭ���Ǿɱ�Ľڵ����ֱ���õ��µ�vector�����н��в���
			vector<Node*> newtable;
			newtable.resize(newsize);

			//�����ɱ����µ�vector�������ҵ���Ӧλ�ã����ɱ�ڵ����
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				//���ڵ�Ӿɱ��в�����������¼���ڵ����±��е�λ�ý��в���
				while (cur)
				{
					Node* next = cur->_next;
					//size_t index = KeyOfValue()(cur->_valuefiled) % newsize;
					size_t index = HashIndex(KeyOfValue()(cur->_valuefiled), newsize);
					//ͷ�����±���
					cur->_next = newtable[index];
					newtable[index] = cur;

					cur = next;
				}
				//��ԭ���ı��ÿ�
				_table[i] = nullptr;
			}
			//�����¾��������Դ������������±��Զ��������������ͷžɱ���Դ
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
				if (prev == nullptr)//ͷɾ
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
	vector<Node*> _table;//vector�е�sizeΪ��ϣ��Ĵ�С
	size_t _size;//��ϣ���д洢����ЧԪ�صĸ���
};
