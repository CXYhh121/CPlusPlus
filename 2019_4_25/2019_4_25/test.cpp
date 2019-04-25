#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;


//LeetCode118杨辉三角形
//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int>> vv;//相当于创建了一个二维数组，一个vector里面存着一个vector
//
//		vv.resize(numRows);//为第一个vector开空间
//
//		for (size_t i = 0; i < vv.size(); ++i)
//		{
//			vv[i].resize(i + 1, 0);//为存在vv中的vector开辟空间,并把所有值置成0
//			vv[i][0] = 1;
//			vv[i][vv[i].size() - 1] = 1;
//		}
//
//		//重新遍历一遍vector，找到为0的位置
//		for (size_t i = 0; i < vv.size(); ++i)
//		{
//			for (size_t j = 0; j < vv[i].size(); ++j)
//			{
//				if (vv[i][j] == 0)
//				{
//					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//				}
//			}
//		}
//
//		return vv;
//
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	s.generate(10);
//	return 0;
//}




//LeetCode119杨辉三角形II
//class Solution {
//public:
//	vector<int> getRow(int rowIndex) {
//		vector<int> Row(rowIndex + 1, 1);//定义一个vector，将值全初始化为1
//		if (rowIndex == 0)
//			return Row;
//		for (int i = 1; i < rowIndex + 1; i++)
//		{
//			for (int j = i - 1; j > 0; j--)
//			{
//				Row[j] = Row[j] + Row[j - 1];
//			}
//		}
//		return Row;
//	}
//};

