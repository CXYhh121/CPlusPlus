#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//�ظ�n�ε�Ԫ��
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
//���仰�в������ĵ���
//class Solution {
//public:
//	vector<string> uncommonFromSentences(string A, string B) {
//		A += ' ';
//		A += B;//��A��B�����ַ�����
//		vector<string> v;
//		unordered_map<string, int> countmap;
//		size_t start = 0;
//		size_t pos = 0;
//		do
//		{
//			pos = A.find(' ', start);//�ҳ��ַ����еĿո�
//			countmap[A.substr(start, pos - start)]++;//ȡ��ÿ������
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



//�����ظ�Ԫ��LeetCode217����һ
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

//�����ظ�Ԫ��LeetCode217������
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


//�����ظ�Ԫ��LeetCode217������
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

//��������Ľ���I
