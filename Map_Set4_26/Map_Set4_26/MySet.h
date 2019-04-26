#include "RBtree.h"


template<class K>
class Myset
{
	typedef K ValueType;
public:
	struct SetKeyOfValue//传给红黑树的仿函数
	{
		const ValueType& operator()(const ValueType& key)
		{
			return key;
		}
	};

	typedef typename RBTree<K, ValueType, SetKeyOfValue>::iterator iterator;
	iterator begin()
	{
		return t.begin();
	}

	iterator end()
	{
		return t.end();
	}

	pair<iterator, bool> Insert(const ValueType& key)
	{
		return t.Insert(key);
	}
private:
	RBTree<K, ValueType,SetKeyOfValue> t;
};


void TestMySet()
{
	Myset<int> ms;
	ms.Insert(1);
	ms.Insert(2);
	ms.Insert(5);
	ms.Insert(8);

	Myset<int>::iterator it = ms.begin();
	while (it != ms.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
