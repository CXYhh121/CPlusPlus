#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


//动态规划路径总数
/*方法:动态规划 状态 :
子状态 : 从(0, 0)到达(1, 0), (1, 1), (2, 1), ...(m - 1, n - 1)的路径数
	F(i, j) : 从(0, 0)到达F(i, j)的路径数 状态递推 :
	F(i, j) = { F(i - 1, j) + F(i, j - 1) } OR{ 0, if obstacleGrid(i, j) = 1 }
初始化:
特殊情况 : 第1行和第1列
	  F(0, i) = { 1 } OR{ 0, if obstacleGrid(0, j) = 1, j <= i } F(i, 0) = { 1 } OR{ 0, if obstacleGrid(j, 0) = 1, j <= i }
返回结果:
	  F(m - 1, n - 1)
*/


//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
//		if (obstacleGrid.empty())
//			return 0;
//		int row = obstacleGrid.size();
//		int col = obstacleGrid[0].size();
//
//		//定义存储状态方程求出结果的数组
//		vector<vector<int>> Fv(row, vector<int>(col, 0));
//		//若是第一行某个位置有障碍物，则之后位置都无法到达
//		for (int j = 0; j < col; j++)
//		{
//			if (obstacleGrid[0][j] == 1)
//				break;
//			else
//				Fv[0][j] = 1;
//		}
//		//若是第一列某个位置有障碍物，则之后的位置都无法到达
//		for (int i = 0; i < row; ++i)
//		{
//			if (obstacleGrid[i][0] == 1)
//				break;
//			else
//				Fv[i][0] = 1;
//		}
//		//其他位置要是遇到障碍物就是无法到达的
//		for (int i = 1; i < row; ++i)
//		{
//			for (int j = 1; j < col; ++j)
//			{
//				if (obstacleGrid[i][j] == 1)
//					continue;
//				else
//					Fv[i][j] = Fv[i - 1][j] + Fv[i][j - 1];
//			}
//		}
//		return Fv[row - 1][col - 1];
//	}
//};


//动态规划最小路劲和
/*状态:
子状态 : 从(0, 0)到达(1, 0), (1, 1), (2, 1), ...(m - 1, n - 1)的最短路径
	F(i, j) : 从(0, 0)到达F(i, j)的最短路径 状态递推 :
	F(i, j) = min{ F(i - 1, j), F(i, j - 1) } +(i, j)
初始化 :
	F(0, 0) = (0, 0) 
特殊情况 : 第0行和第0列 F(0, i) = F(0, i - 1) + (0, i) F(i, 0) = F(i - 1, 0) + (i, 0)
返回结果 :
	F(m - 1, n - 1)
*/

//class Solution {
//public:
//	int minPathSum(vector<vector<int> > &grid) {
//		if (grid.empty() || grid[0].empty())
//			return 0;
//		int row = grid.size();
//		int col = grid[0].size();
//		//定义一个数组存储路径和
//		vector<vector<int>> Fv(row, vector<int>(col, 0));
//		//处理第一行，第一行的路径只能由前一个位置来
//		Fv[0][0] = grid[0][0];
//		for (int j = 1; j < col; ++j)
//		{
//			Fv[0][j] = Fv[0][j - 1] + grid[0][j];
//		}
//		//处理第一列和第一行情况一样
//		for (int i = 1; i < row; i++)
//		{
//			Fv[i][0] = Fv[i - 1][0] + grid[i][0];
//		}
//		//其余位置的最小路径和等于前面能到该位置中最小值+该位置的值
//		for (int i = 1; i < row; i++)
//		{
//			for (int j = 1; j < col; ++j)
//			{
//				Fv[i][j] = min(Fv[i - 1][j], Fv[i][j - 1]) + grid[i][j];
//			}
//		}
//
//		return Fv[row - 1][col - 1];
//	}
//};
//
//int main()
//{
//	vector<vector<int>> grid = {{ 2, 3, 4 }, { 1, 2, 5 }, { 2, 6, 8 }};
//	Solution ss;
//	cout << ss.minPathSum(grid) << endl;
//	return 0;
//}


//动态规划，回文串分割
/*状态:
子状态 : 到第1, 2, 3, ..., n个字符需要的最小分割数
	F(i) : 到第i个字符需要的最小分割数 状态递推 :
	F(i) = min{ F(i), 1 + F(j) }, where j < i && j + 1到i是回文串 
上式表示如果从j + 1到i判断为回文字符串，且已经知道从第1个字符 到第j个字符的最小切割数，那么只需要再切一次，就可以保证
		  1-->j, j + 1-->i都为回文串。
初始化 :
	  F(i) = i - 1 上式表示到第i个字符需要的最大分割数 比如单个字符只需要切0次，因为单子符都为回文串 2个字符最大需要1次，3个2次......
返回结果 :
	  F(n)
遗留问题 : 如何判断一段字符串为回文串
	 循环判断首尾元素是否相同，如果全部相同，则是回文串
*/
//解法一
//class Solution {
//public:
//	int minCut(string s) {
//		if (s.empty()) return 0;
//		int len = s.size();
//		vector<int> cut;
//		 //F(i)初始化
//		 //F(0)= -1，必要项，如果没有这一项，对于重叠字符串“aaaaa”会产生错误的结果 
//		for (int i = 0; i < 1 + len; ++i) {
//			cut.push_back(i - 1);
//		}
//		for (int i = 1; i < 1 + len; ++i) {
//			for (int j = 0; j < i; ++j) {
//				// F(i) = min{F(i), 1 + F(j)}, where j<i && j+1到i是回文串 
//				 //从最长串判断，如果从第j+1到i为回文字符串
//				 //则再加一次分割，从1到j，j+1到i的字符就全部分成了回文字符串
//				if (isPalindrome(s, j, i - 1)) {
//					cut[i] = min(cut[i], 1 + cut[j]);
//				}
//			}
//		}
//		return cut[len];
//	}
//	//判断是否回文串
//	bool isPalindrome(string s, int i, int j)
//	{
//		while (i < j) {
//			if (s[i] != s[j]){
//				return false;
//			} 
//			i++; 
//			j--;
//		}
//		return true;
//	}
//};


//解法二
//class Solution {
//public:
//	int minCut(string s) {
//		if (s.empty())
//			return 0;
//		int len = s.size();
//		vector<int> Cut;
//		//初始化Cut
//		for (int i = 0; i < len + 1; i++)
//			Cut.push_back(i - 1);
//		vector<vector<bool> > mat = getMat(s);
//		for (int i = 1; i < len + 1; ++i)
//		{
//			for (int j = 0; j < i; j++)
//			{
//				if (mat[j][i - 1])
//					Cut[i] = min(Cut[i], 1 + Cut[j]);
//			}
//		}
//		return Cut[len];
//	}
//	vector<vector<bool> > getMat(string s) {
//		int len = s.size();
//		vector<vector<bool>> mat = vector<vector<bool>>(len, vector<bool>(len, false));
//		for (int i = len - 1; i >= 0; --i) {
//			for (int j = i; j < len; ++j) {
//				if (j == i) {
//					// 单字符为回文字符串
//					mat[i][j] = true;
//				}
//				else if (j == i + 1) {
//					// 相邻字符如果相同，则为回文字符串 
//					mat[i][j] = (s[i] == s[j]);
//				}
//				else {
//					mat[i][j] = ((s[i] == s[j]) && mat[i + 1][j - 1]);
//				}
//			}
//		}
//		return mat;
//	}
//};
