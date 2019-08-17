#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;


class LRUCache {
public:
	// ���� -1 (δ�ҵ�)
	// �ò�����ʹ����Կ 1 ���� // ���� -1 (δ�ҵ�) //����3
	//����4
	LRUCache(int capacity) {
		_capacity = capacity;
	}
	int get(int key) {
		// ���key��Ӧ��ֵ���ڣ���listitȡ��������Ϳ��Կ���hashmap��value�����list��iterator�ĺô�:�ҵ�key
		// Ҳ���ҵ�key���ֵ��list�е�iterator��Ҳ��ֱ��ɾ�����ٽ���ͷ�壬ʵ��O(1)������Ų���� 
		auto hashit = _hashmap.find(key);
		if (hashit != _hashmap.end())
		{
			auto listit = hashit->second;
			pair<int, int> kv = *listit;
			_list.erase(listit);
			_list.push_front(kv);
			_hashmap[key] = _list.begin();
			return kv.second;
		}
		else
		{
			return -1;
		}
	}
	void put(int key, int value)
	{
		// 1.���û����������в�������
		// 2.�����������������ݸ���
		auto hashit = _hashmap.find(key);
		if (hashit == _hashmap.end())
		{
			{
				// ��������ʱ����������Ѿ��ﵽ���ޣ���ɾ������ͷ�����ݺ�hashmap�е����ݣ�����ɾ����
				if (_list.size() >= _capacity)
				_hashmap.erase(_list.back().first);
				_list.pop_back();
			}
			_list.push_front(make_pair(key, value));
			_hashmap[key] = _list.begin();
		}
		else
		{
			//�ٴ�put��������Ų��listǰ��
			auto listit = hashit->second; 
			pair<int, int> kv = *listit; 
			kv.second = value;
			_list.erase(listit);
			_list.push_front(kv);
			_hashmap[key] = _list.begin();
		}
	}
private:
	list<pair<int, int>> _list;
	size_t _capacity;
	// ������ù����������Ͷ���ƶ�������LRU // ������С�����������򻻳�������LRU
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
	// ʹ��unordered_map��������Ч�ʴﵽO(1)
	// ��Ҫע��:�������ɵ���ƾ��ǽ�unordered_map��value type�ų�
	//list<pair<int,int >>::iterator����Ϊ��������getһ�����е�ֵ�Ժ󣬾Ϳ���ֱ���ҵ�key��list�ж�Ӧ��iterator��Ȼ�� �����ֵ�ƶ��������ͷ��������LRU��
};