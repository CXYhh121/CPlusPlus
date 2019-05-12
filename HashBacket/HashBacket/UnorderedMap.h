#include "HashTable.h"
#include "common.h"

template<class K, class V,class HashFunc = HashFunc<K>>
class UnorderedMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& _kv)
		{
			return _kv.first;
		}
	};
public:
	typedef typename HashTable<K, pair<K, V>, MapKeyOfValue, HashFunc>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}


	pair<iterator,bool> Insert(const pair<K, V>& kv)
	{
		return _ht.Insert(kv);
	}

	V& operator[](const K& key)
	{
		std::pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
		return ret.first->second;
	}

private:
	HashTable<K, pair<K, V>, MapKeyOfValue,HashFunc> _ht;
};

void TestUnorderedMap()
{
	UnorderedMap<int, int> m;
	m.Insert(std::make_pair(15, 15));
	m.Insert(std::make_pair(5, 5));
	m.Insert(std::make_pair(25, 25));
	m[7] = 6;

	for (size_t i = 0; i < 11; ++i)
	{
		m.Insert(make_pair(i, i));
	}

	UnorderedMap<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
}

void TestUnorderedMap2()
{
	UnorderedMap<string, string> sm;
	sm.Insert(make_pair(string("sort"), string("ÅÅĞò")));
	sm.Insert(make_pair(string("left"), string("×ó±ß")));
	sm.Insert(make_pair(string("string"), string("×Ö·û´®")));
	sm.Insert(make_pair(string("insert"), string("²åÈë")));

	for (auto& kv : sm)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}