#define _CRT_SECURE_NO_WARNINGS

//�����������
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


//ƽ�������
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


//����������һ���ڵ�
//class Solution {
//public:
//	TreeLinkNode* GetNext(TreeLinkNode* pNode)
//	{
//		if (pNode == NULL)
//			return NULL;
//		//���������
//		//1��pNode����������Ϊ�գ���ʱ������������ڵ㣬��ΪpNode����һ���ڵ�
//		else if (pNode->right)
//		{
//			TreeLinkNode* left = pNode->right;
//			while (left->left)
//			{
//				left = left->left;
//			}
//			pNode = left;
//		}
//		//2��pNode��������Ϊ�գ���ʱ��Ҫ�Ҳ��Ǹ��ڵ���Һ��ӵĽڵ㣬���ظýڵ�ĸ��ڵ�
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