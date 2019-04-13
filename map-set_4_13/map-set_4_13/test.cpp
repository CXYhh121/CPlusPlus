#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
using namespace std;


//void TestMap()
//{
//	string words[] = { "i", "string", "i", "love", "love", "like" };
//	map<string, int> countmap;
//	for(auto& e: words)
//	{
//		map<string,int>::iterator it = countmap.find(e);
//		if(it != countmap.end())
//		{
//			it->second++;
//		}
//		else{
//			countmap.insert(make_pair(e,1));
//		}
//	}
//	for (auto& e : countmap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//
//	//for(auto& e : words)
//	//{
//	//	//pair<map<string,int>::iterator,bool> ret = countmap.insert(make_pair(e,1));
//	//	auto ret = countmap.insert(make_pair(e,1));
//	//	if(ret.second == false)
//	//	{
//	//		ret.first->second++;
//	//	}
//	//}
//
//}


//前k个高频单词

//class Solution {
//public:
//	vector<string> topKFrequent(vector<string>& words, int k) 
//	{
//		map<string, int> countmap;
//		for (auto& e : words)
//		{
//			countmap[e]++;
//		}
//
//		vector<string> v;
//		multimap<int, string , greater<int>> sortmap;
//		for (auto& kv : countmap)
//		{
//			sortmap.insert(make_pair(kv.second, kv.first));
//		}            
//
//		multimap<int, string>::iterator it = sortmap.begin();
//		while (it != sortmap.end() && k--)
//		{
//			v.push_back(it->second);
//			++it;
//		}
//
//		return v;
//	}
//};
//int main()
//{
//	//TestMap();
//	//string words[] = { "i", "string", "i", "love", "love", "like" };
//	vector<string> words;
//	words.push_back("i");
//	words.push_back("love");
//	words.push_back("i");
//	words.push_back("i");
//	words.push_back("you");
//	words.push_back("you");
//	words.push_back("love");
//	words.push_back("like");
//	words.push_back("string");
//
//	Solution s;
//	vector<string> v = s.topKFrequent(words, 3);
//
//	for (auto& e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}
//前k个高频单词

//class Solution {
//public:
//	vector<string> topKFrequent(vector<string>& words, int k)
//	{
//		vector<pair<int, string>>res;
//		vector<string>re;
//		map<string, int>temp;
//		for (auto i : words)temp[i]++;
//		for (auto i : temp) res.emplace_back(pair<int, string>(i.second, i.first));
//
//		sort(res.begin(), res.end(), [](auto lhs, auto rhs)
//		{
//			if (lhs.first == rhs.first)
//				return lhs.second<rhs.second;
//			else
//				return lhs.first>rhs.first;
//		});
//
//		for (int i = 0; i<k; i++)re.emplace_back(res[i].second);
//
//		return re;
//	}
//};



//前k个高频元素
//class Solution {
//public:
//	vector<int> topKFrequent(vector<int>& nums, int k) {
//		map<int, int> countmap;
//		vector<int> v;
//		for (auto& e : nums)
//		{
//			countmap[e]++;
//		}
//
//		multimap<int, int, greater<int>> sortmap;
//		for (auto& kv : countmap)
//		{
//			sortmap.insert(make_pair(kv.second, kv.first));
//		}
//
//		auto it = sortmap.begin();
//		while (it != sortmap.end() && k--)
//		{
//			v.push_back(it->second);
//			++it;
//		}
//		return v;
//	}
//};