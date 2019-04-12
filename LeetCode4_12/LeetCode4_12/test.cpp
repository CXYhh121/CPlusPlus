#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//求最长公共前缀方法一
//class Solution {
//public:
//	string longestCommonPrefix(vector<string>& strs) {
//		if (strs.size() == 0)
//			return "";
//		string s = "";
//		int min = strs[0].size();
//		int col = 0;
//		int flag;
//		while (col < min)
//		{
//			//找出每一列公共的
//			int row = 0;
//			while (row + 1<strs.size())
//			{
//				flag = 1;
//				if (strs[row][col] != strs[row + 1][col])
//				{
//					flag = 0;
//					break;
//				}
//				row++;
//			}
//			//把公共前缀连接起来
//			if (flag == 1)
//			{
//				s += strs[row][col];
//				col++;
//			}
//			else
//				return s;
//		}
//		return s;
//	}
//};

//求最长公共前缀方法二，用substr函数
//class Solution {
//public:
//	string longestCommonPrefix(vector<string>& strs) {
//		if (strs.size() == 0)
//			return "";
//		if (strs.size() == 1)
//			return strs[0];
//
//		for (size_t i = 0; i < strs[0].size(); ++i)
//		{
//			for (size_t j = 1; j < strs.size(); ++j)
//			{
//				if (strs[j][i] != strs[0][i])
//					//生成子字符串,string substr（size_t pos = 0，size_t len = npos）const;
//					return strs[0].substr(0, i);
//			}
//		}
//		return strs[0];
//
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<string> strs;
//	strs.push_back("abcd");
//	strs.push_back("abcjhg");
//	strs.push_back("abcuaudiouo");
//	cout << s.longestCommonPrefix(strs)<<endl;
//	return 0;
//}


//有序数组转换为二叉搜索树
//class Solution {
//public:
//	TreeNode* _sortedArrayToBST(vector<int>& nums, int left, int right)
//	{
//		if (left > right)
//			return NULL;
//		int mid = left + (right - left) / 2;
//		TreeNode* root = new TreeNode(nums[mid]);
//
//		root->left = _sortedArrayToBST(nums, left, mid - 1);
//		root->right = _sortedArrayToBST(nums, mid + 1, right);
//
//		return root;
//	}
//	TreeNode* sortedArrayToBST(vector<int>& nums) {
//		return _sortedArrayToBST(nums, 0, nums.size() - 1);
//	}
//};