#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


//쳲���������
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

//������̨��fn = (fn-1) + (fn-2)
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


//��̬��̨�ף�����ܼ򵥣���������̨��֪�����������һ������1��,2��̨��ʱ��fn = (fn-1) + (fn-2)
//��ô���һ������1����2����3��......n��ʱ��fn = (fn-1) + (fn-2) + (fn-3)+......(f2) + f(1) + f(0)
//(fn-1) = (fn-2) + (fn-3)+......(f2) + f(1) + f(0)��fn = (fn-1) + (fn-1) = 2(fn-1)
//��Ҫ�ǵ��Ƶ�����ʽfn = 2(fn-1)
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


//����������һ���ڵ�
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
//	}
//};