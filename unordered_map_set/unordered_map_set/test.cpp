#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//重复n次的元素
//class Solution {
//public:
//	int repeatedNTimes(vector<int>& A) {
//		unordered_map<int, int> countmap;
//		for (auto& e : A)
//		{
//			countmap[e]++;
//		}
//
//		for (auto& kv : countmap)
//		{
//			if (kv.second >= A.size() / 2)
//				return kv.first;
//		}
//		return 0;
//	}
//};
//两句话中不常见的单词
//class Solution {
//public:
//	vector<string> uncommonFromSentences(string A, string B) {
//		A += ' ';
//		A += B;//将A，B两个字符连接
//		vector<string> v;
//		unordered_map<string, int> countmap;
//		size_t start = 0;
//		size_t pos = 0;
//		do
//		{
//			pos = A.find(' ', start);//找出字符串中的空格
//			countmap[A.substr(start, pos - start)]++;//取出每个单词
//			start = pos + 1;
//		} while (pos != string::npos);
//
//
//		for (auto& kv : countmap)
//		{
//			if (kv.second == 1)
//				v.push_back(kv.first);
//		}
//		return v;
//	}
//};



//存在重复元素LeetCode217方法一
//class Solution {
//public:
//	bool containsDuplicate(vector<int>& nums) {
//		unordered_map<int, int> countmap;
//		for (auto& e : nums)
//		{
//			countmap[e]++;
//		}
//
//		for (auto& kv : countmap)
//		{
//			if (kv.second >= 2)
//				return true;
//		}
//
//		return false;
//	}
//};

//存在重复元素LeetCode217方法二
//class Solution {
//public:
//	bool containsDuplicate(vector<int>& nums) {
//		unordered_set<int> s;
//		for (auto& e : nums)
//		{
//			if (s.find(e) == s.end())
//			{
//				s.insert(e);
//			}
//			else
//				return true;
//		}
//		return false;
//	}
//};


//存在重复元素LeetCode217方法三
//class Solution {
//public:
//	bool containsDuplicate(vector<int>& nums) {
//		if (nums.empty())
//			return false;
//		sort(nums.begin(), nums.end());
//		for (int i = 0; i < nums.size() - 1; i++)
//		{
//			if (nums[i] == nums[i + 1])
//				return true;
//		}
//		return false;
//	}
//};

//两个数组的交集I
