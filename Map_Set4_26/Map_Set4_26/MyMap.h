#include "RBtree.h"

template<class K, class V>//外部定义map时显示实例化还是使用K-V
class MyMap
{
	typedef pair<K, V> ValueType;//这里红黑树中将会存储pair<K, V>
public:

	struct MapKeyOfValue//传给红黑树的仿函数
	{
		const K& operator()(const ValueType& kv)
		{
			return kv.first;//我们需要使用pair的first进行比较
		}
	};
	typedef typename RBTree<K, ValueType, MapKeyOfValue>::iterator iterator;
	
	iterator begin()
	{
		return t.begin();
	}

	iterator end()
	{
		return t.end();
	}

	pair<iterator,bool> Insert(const ValueType& key)
	{
		return t.Insert(key);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = t.Insert(make_pair(key,V()));//插入成功将value设置为类型的默认缺省类型
		return ret.first->second;//ret.first取到这个节点的迭代器，ret.first->second可以对value进行修改
	}

private:
	RBTree<K, ValueType, MapKeyOfValue> t;//第一个参数：K值 第二个参数：节点中存的值 第三个参数：仿函数
};

void TestMyMap()
{
	MyMap<string, string> mm;
	mm.Insert(std::make_pair(string("sort"), string("排序")));
	mm.Insert(std::make_pair(string("string"), string("字符串")));
	mm.operator[]("left");
	mm.operator[]("left") = "剩余";
	mm.operator[]("string") = "STL模板";

	MyMap<string, string>::iterator it = mm.begin();
	while (it != mm.end())
	{
		cout << (*it).first << ":" << (*it).second << " ";
		++it;
	}
	cout << endl;
}