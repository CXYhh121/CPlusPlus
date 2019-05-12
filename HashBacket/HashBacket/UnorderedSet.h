#include "HashTable.h"
#include "common.h"

template<class K,class HashFunc = HashFunc<K>>
class UnorderedSet
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef typename HashTable<K, K, SetKeyOfValue, HashFunc>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

	pair<iterator,bool> Insert(const K& key)
	{
		return _ht.Insert(key);
	}
private:
	HashTable<K, K, SetKeyOfValue,HashFunc> _ht;
};

void TestUnorderedSet()
{
	UnorderedSet<int> s;
	s.Insert(1);
	s.Insert(5);
	s.Insert(3);
	s.Insert(10);
	s.Insert(5);
	s.Insert(19);
	s.Insert(3);
	s.Insert(2);
	s.Insert(8);

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}