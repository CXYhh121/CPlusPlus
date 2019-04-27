#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


//斐波那契数列
//class Solution {
//public:
//	int Fibonacci(int n) {
//		if (n == 0)
//			return 0;
//		if (n == 1)
//			return 1;
//		int numfn1 = 0;
//		int numfn2 = 1;
//		int currentnum;
//		for (int i = 2; i <= n; ++i)
//		{
//			currentnum = numfn1 + numfn2;
//			numfn1 = numfn2;
//			numfn2 = currentnum;
//		}
//		return currentnum;
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.Fibonacci(3) << endl;
//	return 0;
//}

//青蛙跳台阶fn = (fn-1) + (fn-2)
//class Solution {
//public:
//	int jumpFloor(int number) {
//		if (number == 0)
//			return 0;
//		if (number == 1)
//			return 1;
//		int fn1 = 1, fn2 = 1;
//		int fn;
//		for (int i = 2; i <= number; ++i)
//		{
//			fn = fn1 + fn2;
//			fn2 = fn1;
//			fn1 = fn;
//		}
//		return fn;
//	}
//};


//变态跳台阶，代码很简单，由青蛙跳台阶知道，如果能跳一次能跳1个,2个台阶时，fn = (fn-1) + (fn-2)
//那么如果一次能跳1个，2个，3个......n个时，fn = (fn-1) + (fn-2) + (fn-3)+......(f2) + f(1) + f(0)
//(fn-1) = (fn-2) + (fn-3)+......(f2) + f(1) + f(0)，fn = (fn-1) + (fn-1) = 2(fn-1)
//主要是得推导出公式fn = 2(fn-1)
//class Solution {
//public:
//	int jumpFloorII(int number) {
//		if (number == 0)
//			return 0;
//		int total = 1;
//		for (int i = 1; i < number; ++i)
//		{
//			total *= 2;
//		}
//		return total;
//	}
//};


//二叉树的下一个节点
/*
struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};
*/
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
//	}
//};