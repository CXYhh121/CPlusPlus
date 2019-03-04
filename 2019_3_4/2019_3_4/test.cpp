#define _CRT_SECURE_NO_WARNINGS
//class A{
//	int a1;
//protected:
//	int a2;
//public:
//	int a3;
//};
//class B : public A{
//	int b1;
//protected:
//	int b2;
//public:
//	int b3;
//};
//class C :private B{
//	int c1;
//protected:
//	int c2;
//public:
//	int c3;
//};
//int main(){
//	B obb;
//	C obc;
//	cout << obb.a1;//1
//	cout << obb.a2;//2
//	cout << obb.a3;//3
//	cout << obc.b1;//4
//	cout << obc.b2;//5
//	cout << obc.b3;//6
//	cout << obc.c3;//7
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class A {
//public:
//	int b;
//	char c;
//	virtual void print() {
//		cout << "this is father’s fuction! " << endl;
//	}
//};
//class B : A {
//public:
//	virtual void print() {
//		cout << "this is children’s fuction! " << endl;
//	}
//};
//
//int main() 
//{
//	cout << sizeof(A) << "" << sizeof(B) << endl;
//	return 0;
//}



#include <iostream>
#include <vector>
using namespace std;

//删除排序数组中的重复项
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		if (nums.empty() == 1)
//			return 0;
//		int size = 0;
//		for (size_t i = 0; i < nums.size(); ++i)
//		{
//			if (nums[size] != nums[i])
//			{
//				nums[++size] = nums[i];
//			}
//		}
//		return ++size;
//	}
//};

//只出现一次的数字I
class Solution{
public:
	int singleNumber1(vector<int>& nums)
	{
		int value = 0;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			value ^= nums[i];
		}
		return value;
	}
};
//只出现一次的数字II
//class Solution{
//public:
//	int singleNumber(vector<int>& nums)
//	{
//		int value = 0;
//		for (size_t i = 0; i < 32; ++i)
//		{
//			int mask = 1 << i;
//			int count = 0;
//			for (size_t j = 0; j < nums.size(); ++j)
//			{
//				if (nums[j] & mask)
//					++count;
//			}
//			if (count % 3)
//				value |= mask;
//		}
//		return value;
//	}
//};
int main()
{
	Solution s;
	vector<int> num = { 1, 3, 3, 4, 4 };
	//cout << s.removeDuplicates(num) << endl;
	cout << s.singleNumber1(num) << endl;
	//cout << s.singleNumber(num) << endl;

	return 0;
}