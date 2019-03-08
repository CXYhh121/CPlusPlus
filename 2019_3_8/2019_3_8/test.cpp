#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//class B
//{
//public:
//	B()
//	{
//		cout << "default constructor" << " ";
//	}
//	~B()
//	{
//		cout << "destructed" << " ";
//	}
//	B(int i) : data(i)
//	{
//		cout << "constructed by parameter" << data << " ";
//	}
//private: int data;
//};
//B Play(B b)
//{
//	return b;
//}
//int main(int argc, char *argv[])
//{
//	B temp = Play(5);
//	return 0;
//}


//最小栈的实现
//class MinStack {
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//
//	}
//
//	void push(int x) {
//		st.push(x);
//		if (minst.empty() || minst.top() >= x)
//		{
//			minst.push(x);
//		}
//
//	}
//
//	void pop() {
//		if (minst.top() == st.top())
//			minst.pop();
//
//		st.pop();
//	}
//
//	int top() {
//		return st.top();
//
//	}
//
//	int getMin() {
//		return minst.top();
//
//	}
//private:
//	stack<int> st;
//	stack<int> minst;
//};
//
//int main()
//{
//	MinStack Mst;
//	Mst.push(1);
//	Mst.push(2);
//	Mst.push(3);
//	Mst.push(2);
//
//	Mst.getMin();
//	return 0;
//}



//栈的压入，弹出序列
//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		if (pushV.size() != popV.size())
//			return false;
//		size_t index = 0;//入栈序列的下标
//		size_t outdex = 0;//出栈序列的下标
//		stack<int> st;
//
//		while (outdex < popV.size())
//		{
//			while (st.empty() || st.top() != popV[outdex])
//			{
//				if (index < pushV.size())
//					st.push(pushV[index++]);
//				else
//					return false;
//			}
//			st.pop();
//			++outdex;
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> pushV;
//	vector<int> popV;
//	pushV.push_back(1);
//	pushV.push_back(2);
//	pushV.push_back(3);
//
//	popV.push_back(3);
//	popV.push_back(1);
//	popV.push_back(2);
//
//	s.IsPopOrder(pushV, popV);
//	return 0;
//}


