#define _CRT_SECURE_NO_WARNINGS

//动态规划字符串分割
//状态 :
//子状态 : 前1，2，3，..., n个字符能否根据词典中的词被成功分词
//F(i) : 前i个字符能否根据词典中的词被成功分词 
//状态递推 :
//F(i) : true{j <i && F(j) && substr[j + 1, i]能在词典中找到} OR false 在j小于i中，只要能找到一个F(j)为true，并且从j + 1到i之间的字符能在词典 中找到，则F(i)为true
//初始值 : 对于初始值无法确定的，可以引入一个不代表实际意义的空状态，作为状态的起始 空状态的值需要保证状态递推可以正确且顺利的进行，到底取什么值可以通过简单 的例子进行验证
//F(0) = true
//返回结果 : F(n)

//class Solution {
//public:
//	bool wordBreak(string s, unordered_set<string> &dict) {
//		if (s.empty())
//			return false;
//		if (dict.empty())
//			return false;
//		int len = s.size();
//		vector<bool> v(len + 1, false);
//		v[0] = true;
//		for (int i = 1; i <= len; i++)
//		{
//			for (int j = i - 1; j >= 0; j--)
//			{
//				if (v[j] && dict.find(s.substr(j, i - j)) != dict.end())
//				{
//					v[i] = true;
//					break;
//				}
//			}
//		}
//		return v[len];
//	}
//};


//动态规划三角矩阵
/*方法:动态规划 状态 :
子状态 : 从(0, 0)到(1, 0), (1, 1), (2, 0), ...(n, n)的最短路径和
F(i, j) : 从(0, 0)到(i, j)的最短路径和 状态递推 :
F(i, j) = min(F(i - 1, j - 1), F(i - 1, j)) + triangle[i][j]
初始值 :
	F(0, 0) = triangle[0][0]
返回结果 :
	min(F(n - 1, i))
*/
//class Solution {
//public:
//	int minimumTotal(vector<vector<int> > &triangle) {
//		if (triangle.empty())
//			return 0;
//		vector<vector<int>> Fv(triangle);
//		int row = triangle.size();
//		for (int i = 1; i < row; ++i)
//		{
//			for (int j = 0; j <= i; ++j)
//			{
//				if (j == 0)
//					Fv[i][j] = Fv[i - 1][j];
//				else if (j == i)
//					Fv[i][j] = Fv[i - 1][j - 1];
//				else
//					Fv[i][j] = min(Fv[i - 1][j - 1], Fv[i - 1][j]);
//
//				Fv[i][j] += triangle[i][j];
//			}
//		}
//		int result = Fv[row - 1][0];
//		// min(F(n-1, i))
//		for (int i = 1; i < row; i++){
//			result = min(Fv[row - 1][i], result);
//		}
//		return result;
//	}
//};


//动态规划路径总数
/*方法:动态规划 状态 :
子状态 : 从(0, 0)到达(1, 0), (1, 1), (2, 1), ...(m - 1, n - 1)的路径数
F(i, j) : 从(0, 0)到达F(i, j)的路径数 状态递推 :
F(i, j) = F(i - 1, j) + F(i, j - 1)
初始化 : 特殊情况 : 第0行和第0列 F(0, i) = 1
		F(i, 0) = 1
返回结果 :
		F(m - 1, n - 1)
*/

//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        if(m < 1 || n < 1)
//            return 0;
//        vector<vector<int>> Fv(m,vector<int>(n,1));
//        
//        for(int i = 1;i < m;i++)
//        {
//            for(int j = 1;j < n;j++)
//            {
//                Fv[i][j] = Fv[i - 1][j] + Fv[i][j - 1];
//            }
//        }
//        return Fv[m - 1][n - 1];
//    }
//};

