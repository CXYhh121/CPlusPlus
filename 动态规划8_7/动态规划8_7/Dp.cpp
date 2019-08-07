#define _CRT_SECURE_NO_WARNINGS
//斐波那契数列
//动态规划 状态 : F(n)
//状态递推 : F(n) = F(n - 1) + F(n - 2) 
//初始值 : F(1) = F(2) = 1 
//返回结果 : F(N)

//class Solution {
//public:
//	int Fibonacci(int n) {
//		if (n <= 0)
//			return 0;
//		if (n == 1 || n == 2)
//			return 1;
//		int fn, f1, f2;
//		f1 = f2 = 1;
//		for (int i = 3; i <= n; i++)
//		{
//			fn = f1 + f2;
//			f2 = f1;
//			f1 = fn;
//		}
//		return fn;
//	}
//};


//变态跳台阶
//状态: 子状态 : 跳上1级，2级，3级，...，n级台阶的跳法数 f(n) : 还剩n个台阶的跳法数
//状态递推 : n级台阶，第一步有n种跳法 : 跳1级、跳2级、到跳n级 跳1级，剩下n - 1级，则剩下跳法是f(n - 1) 跳2级，剩下n - 2级，则剩下跳法是f(n - 2)
//	   f(n) = f(n - 1) + f(n - 2) + ... + f(n - n)
//	   f(n) = f(n - 1) + f(n - 2) + ... + f(0)
//	   f(n - 1) = f(n - 2) + ... + f(0)
//	   f(n) = 2 * f(n - 1)
//初始值 :
//	   f(1) = 1
//	   f(2) = 2 * f(1) = 2 f(3) = 2 * f(2) = 4 f(4) = 2 * f(3) = 8
//所以它是一个等比数列 f(n) = 2 ^ (n - 1)
//   返回结果 : f(N)



//class Solution {
//public:
//	int jumpFloorII(int number) {
//		if (number == 0)
//			return 0;
//		if (number == 1)
//			return 1;
//		return 2 * jumpFloorII(number - 1);
//	}
//};



//矩阵覆盖问题
//状态F[i]:用i个2*1的小矩形无重叠覆盖一个2*i的大矩形的方法数
//F[i]:F[i - 1] + F[i - 2]
//返回值：F[n]

//class Solution {
//public:
//	int rectCover(int number) {
//		if (number <= 0)
//			return 0;
//		if (number == 1 || number == 2)
//			return number;
//		int fn, f1, f2;
//		f1 = 2; f2 = 1;
//		for (int i = 3; i <= number; i++)
//		{
//			fn = f1 + f2;
//			f2 = f1;
//			f1 = fn;
//		}
//		return fn;
//	}
//};

//最大连续子序列和
//方法:动态规划 
//状态 :
//子状态 : 长度为1，2，3，..., n的子数组和的最大值 F(i) : 长度为i的子数组和的最大值，这种定义不能形成递推关系，舍弃 F(i) : 以array[i]为末尾元素的子数组和的最大值
//状态递推 :
//F(i) = max(F(i - 1) + array[i]，array[i])
//F(i) = (F(i - 1) > 0) ? F(i - 1) + array[i] : array[i]
//初始值 : F(0) = array[0] 
//返回结果 :maxsum : 所有F(i)中的最大值

//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		if (array.empty())
//			return 0;
//		int value = array[0];
//		int maxvalue = array[0];
//		for (size_t i = 1; i < array.size(); i++)
//		{
//			value = max(value + array[i], array[i]);
//			maxvalue = max(value, maxvalue);
//		}
//		return maxvalue;
//	}
//};

//字符串切割word-break

