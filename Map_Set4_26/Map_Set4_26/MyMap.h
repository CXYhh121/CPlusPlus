#include "RBtree.h"

template<class K, class V>//�ⲿ����mapʱ��ʾʵ��������ʹ��K-V
class MyMap
{
	typedef pair<K, V> ValueType;//���������н���洢pair<K, V>
public:

	struct MapKeyOfValue//����������ķº���
	{
		const K& operator()(const ValueType& kv)
		{
			return kv.first;//������Ҫʹ��pair��first���бȽ�
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
		pair<iterator, bool> ret = t.Insert(make_pair(key,V()));//����ɹ���value����Ϊ���͵�Ĭ��ȱʡ����
		return ret.first->second;//ret.firstȡ������ڵ�ĵ�������ret.first->second���Զ�value�����޸�
	}

private:
	RBTree<K, ValueType, MapKeyOfValue> t;//��һ��������Kֵ �ڶ����������ڵ��д��ֵ �������������º���
};

void TestMyMap()
{
	MyMap<string, string> mm;
	mm.Insert(std::make_pair(string("sort"), string("����")));
	mm.Insert(std::make_pair(string("string"), string("�ַ���")));
	mm.operator[]("left");
	mm.operator[]("left") = "ʣ��";
	mm.operator[]("string") = "STLģ��";

	MyMap<string, string>::iterator it = mm.begin();
	while (it != mm.end())
	{
		cout << (*it).first << ":" << (*it).second << " ";
		++it;
	}
	cout << endl;
}