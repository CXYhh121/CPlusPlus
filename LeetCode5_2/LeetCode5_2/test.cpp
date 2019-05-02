#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int _val;
	TreeNode(int value)
		:left(nullptr)
		, right(nullptr)
		, _val(value)
	{}
};

//路径总和I
//class Solution {
//public:
//	bool hasPathSum(TreeNode* root, int sum)
//	{
//		if (root == nullptr)
//			return false;
//		if (root->left == nullptr && root->right == nullptr)
//			return sum - root->_val == 0;
//		
//		return hasPathSum(root->left, sum - root->_val)
//			|| hasPathSum(root->right, sum - root->_val);
//	}
//};


//路径总和II
class Solution
{
	void _pathSum(TreeNode* root,int sum,vector<int>& tmp,vector<vector<int>>& ans)
	{
		if (root == nullptr)
			return;
		tmp.push_back(root->_val);
		if (root->left == nullptr && root->right == nullptr)
		{
			if (sum - root->_val == 0)
				ans.push_back(tmp);
			tmp.pop_back();
			return;
		}

		_pathSum(root->left, sum - root->_val, tmp, ans);
		_pathSum(root->right, sum - root->_val, tmp, ans);
		tmp.pop_back();

	}
	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		vector<int> tmp;
		vector<vector<int>> ans;

		_pathSum(root, sum, tmp, ans);
		return ans;
	}
};



//路径总和III
class Solution {
public:
	int _pathSum_cur(TreeNode* root, int sum)
	{
		if (root == nullptr)
			return 0;
		int count = 0;
		sum -= root->_val;
		if (sum == 0)
			count++;
		count += _pathSum_cur(root->left, sum);
		count += _pathSum_cur(root->right, sum);

		return count;
	}
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return 0;
		int ans = 0;
		ans += _pathSum_cur(root, sum);
		ans += pathSum(root->left, sum);
		ans += pathSum(root->right, sum);

		return ans;
	}
};