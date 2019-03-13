#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//int main()
//{
//	char p1[10] = "abcd", *p2, str[10] = "xyz";
//
//	p2 = "ABCD";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf(" %s", str);
//	return 0;
//}

//
//class A
//{
//public:
//	void *p1;
//private:
//	void *p2;
//protected:
//	void *p3;
//};
//class B : public A {};
//
//int main()
//{
//	printf("%d\n", sizeof(B));
//	return 0;
//}

//最长公共前缀
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		if (strs.size() == 1)
			return strs[0];

		for (size_t i = 0; i < strs[0].size(); ++i)
		{
			for (size_t j = 1; j < strs.size(); ++j)
			{
				if (strs[j][i] != strs[0][i])
					return strs[0].substr(0, i);
			}
		}
		return strs[0];

	}
};

int main()
{
	Solution s;
	vector<string> str;
	str.push_back("flower");
	str.push_back("flas");
	str.push_back("floadac");
	str.push_back("flower");
	str.push_back("flower");

	string rstr = s.longestCommonPrefix(str);

	printf("%s\n", rstr);
	return 0;
}


//搜索插入位置
//class Solution {
//public:
//	int searchInsert(vector<int>& nums, int target) {
//		vector<int>::iterator it = nums.begin();
//		int count = 0;
//		while (it != nums.end())
//		{
//			if (*it < target)
//			{
//
//				++count;
//				++it;
//			}
//			else
//				break;
//		}
//		return count;
//	}
//};