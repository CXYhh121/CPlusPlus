#define _CRT_SECURE_NO_WARNINGS

//二叉树的深度
//class Solution {
//public:
//	int TreeDepth(TreeNode* pRoot)
//	{
//		if (pRoot == NULL)
//			return 0;
//		int leftdepth = TreeDepth(pRoot->left);
//		int rightdepth = TreeDepth(pRoot->right);
//
//		return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
//
//	}
//};


//平衡二叉树
//class Solution {
//public:
//	int TreeDepth(TreeNode* pRoot)
//	{
//		if (pRoot == NULL)
//			return 0;
//		int leftdepth = TreeDepth(pRoot->left);
//		int rightdepth = TreeDepth(pRoot->right);
//
//		return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
//
//	}
//	bool IsBalanced_Solution(TreeNode* pRoot) {
//		if (pRoot == NULL)
//			return true;
//		int leftdepth = TreeDepth(pRoot->left);
//		int rightdepth = TreeDepth(pRoot->right);
//
//		return abs(leftdepth - rightdepth) < 2
//			&& IsBalanced_Solution(pRoot->left)
//			&& IsBalanced_Solution(pRoot->right);
//
//	}
//};


//二叉树的下一个节点
//class Solution {
//public:
//	TreeLinkNode* GetNext(TreeLinkNode* pNode)
//	{
//		if (pNode == NULL)
//			return NULL;
//		//分两种情况
//		//1、pNode的右子树不为空，此时右子树的最左节点，即为pNode的下一个节点
//		else if (pNode->right)
//		{
//			TreeLinkNode* left = pNode->right;
//			while (left->left)
//			{
//				left = left->left;
//			}
//			pNode = left;
//		}
//		//2、pNode的右子树为空，此时需要找不是父节点的右孩子的节点，返回该节点的父节点
//		else{
//			TreeLinkNode* parent = pNode->next;
//			TreeLinkNode* cur = pNode;
//			while (parent && cur != parent->right)
//			{
//				cur = parent;
//				parent = cur->next;
//			}
//			pNode = cur->next;
//		}
//		return pNode;
//	}
//};


//class Solution {
//public:
//	TreeLinkNode* GetNext(TreeLinkNode* pNode)
//	{
//		if (pNode == NULL)
//			return NULL;
//		if (pNode->right != NULL)
//		{
//			pNode = pNode->right;
//			while (pNode->left != NULL)
//				pNode = pNode->left;
//			return pNode;
//		}
//		while (pNode->next != NULL)
//		{
//			TreeLinkNode *proot = pNode->next;
//			if (proot->left == pNode)
//				return proot;
//			pNode = pNode->next;
//		}
//		return NULL;
//	}
//};