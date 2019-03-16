#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//
//class A
//{
//public:
//	A()
//	{
//		printf("A ");
//	}
//
//	~A()
//	{
//		printf("deA ");
//	}
//};
//
//class B
//{
//public:
//	B()
//	{
//		printf("B ");
//	}
//	~B()
//	{
//		printf("deB ");
//	}
//};
//
//class C : public A, public B
//{
//public:
//	C()
//	{
//		printf("C ");
//	}
//	~C()
//	{
//		printf("deC ");
//	}
//};
//int main()
//{
//	A *a = new C();
//	delete a;
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;
//最大子序和
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int max = nums[0];
		int sum = 0;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			sum += nums[i];
			if (sum > max)
				max = sum;
			if (sum < 0)
				sum = 0;
		}
		return max;

	}
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(-2);
	nums.push_back(3);
	nums.push_back(-4);
	nums.push_back(9);
	nums.push_back(3);
	nums.push_back(-6);

	int ret = s.maxSubArray(nums);

	printf("%d\n", ret);
	return 0;
}