#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


//��̬�滮·������
/*����:��̬�滮 ״̬ :
��״̬ : ��(0, 0)����(1, 0), (1, 1), (2, 1), ...(m - 1, n - 1)��·����
	F(i, j) : ��(0, 0)����F(i, j)��·���� ״̬���� :
	F(i, j) = { F(i - 1, j) + F(i, j - 1) } OR{ 0, if obstacleGrid(i, j) = 1 }
��ʼ��:
������� : ��1�к͵�1��
	  F(0, i) = { 1 } OR{ 0, if obstacleGrid(0, j) = 1, j <= i } F(i, 0) = { 1 } OR{ 0, if obstacleGrid(j, 0) = 1, j <= i }
���ؽ��:
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
//		//����洢״̬����������������
//		vector<vector<int>> Fv(row, vector<int>(col, 0));
//		//���ǵ�һ��ĳ��λ�����ϰ����֮��λ�ö��޷�����
//		for (int j = 0; j < col; j++)
//		{
//			if (obstacleGrid[0][j] == 1)
//				break;
//			else
//				Fv[0][j] = 1;
//		}
//		//���ǵ�һ��ĳ��λ�����ϰ����֮���λ�ö��޷�����
//		for (int i = 0; i < row; ++i)
//		{
//			if (obstacleGrid[i][0] == 1)
//				break;
//			else
//				Fv[i][0] = 1;
//		}
//		//����λ��Ҫ�������ϰ�������޷������
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


//��̬�滮��С·����
/*״̬:
��״̬ : ��(0, 0)����(1, 0), (1, 1), (2, 1), ...(m - 1, n - 1)�����·��
	F(i, j) : ��(0, 0)����F(i, j)�����·�� ״̬���� :
	F(i, j) = min{ F(i - 1, j), F(i, j - 1) } +(i, j)
��ʼ�� :
	F(0, 0) = (0, 0) 
������� : ��0�к͵�0�� F(0, i) = F(0, i - 1) + (0, i) F(i, 0) = F(i - 1, 0) + (i, 0)
���ؽ�� :
	F(m - 1, n - 1)
*/

//class Solution {
//public:
//	int minPathSum(vector<vector<int> > &grid) {
//		if (grid.empty() || grid[0].empty())
//			return 0;
//		int row = grid.size();
//		int col = grid[0].size();
//		//����һ������洢·����
//		vector<vector<int>> Fv(row, vector<int>(col, 0));
//		//�����һ�У���һ�е�·��ֻ����ǰһ��λ����
//		Fv[0][0] = grid[0][0];
//		for (int j = 1; j < col; ++j)
//		{
//			Fv[0][j] = Fv[0][j - 1] + grid[0][j];
//		}
//		//�����һ�к͵�һ�����һ��
//		for (int i = 1; i < row; i++)
//		{
//			Fv[i][0] = Fv[i - 1][0] + grid[i][0];
//		}
//		//����λ�õ���С·���͵���ǰ���ܵ���λ������Сֵ+��λ�õ�ֵ
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


//��̬�滮�����Ĵ��ָ�
/*״̬:
��״̬ : ����1, 2, 3, ..., n���ַ���Ҫ����С�ָ���
	F(i) : ����i���ַ���Ҫ����С�ָ��� ״̬���� :
	F(i) = min{ F(i), 1 + F(j) }, where j < i && j + 1��i�ǻ��Ĵ� 
��ʽ��ʾ�����j + 1��i�ж�Ϊ�����ַ��������Ѿ�֪���ӵ�1���ַ� ����j���ַ�����С�и�������ôֻ��Ҫ����һ�Σ��Ϳ��Ա�֤
		  1-->j, j + 1-->i��Ϊ���Ĵ���
��ʼ�� :
	  F(i) = i - 1 ��ʽ��ʾ����i���ַ���Ҫ�����ָ��� ���絥���ַ�ֻ��Ҫ��0�Σ���Ϊ���ӷ���Ϊ���Ĵ� 2���ַ������Ҫ1�Σ�3��2��......
���ؽ�� :
	  F(n)
�������� : ����ж�һ���ַ���Ϊ���Ĵ�
	 ѭ���ж���βԪ���Ƿ���ͬ�����ȫ����ͬ�����ǻ��Ĵ�
*/
//�ⷨһ
//class Solution {
//public:
//	int minCut(string s) {
//		if (s.empty()) return 0;
//		int len = s.size();
//		vector<int> cut;
//		 //F(i)��ʼ��
//		 //F(0)= -1����Ҫ����û����һ������ص��ַ�����aaaaa�����������Ľ�� 
//		for (int i = 0; i < 1 + len; ++i) {
//			cut.push_back(i - 1);
//		}
//		for (int i = 1; i < 1 + len; ++i) {
//			for (int j = 0; j < i; ++j) {
//				// F(i) = min{F(i), 1 + F(j)}, where j<i && j+1��i�ǻ��Ĵ� 
//				 //������жϣ�����ӵ�j+1��iΪ�����ַ���
//				 //���ټ�һ�ηָ��1��j��j+1��i���ַ���ȫ���ֳ��˻����ַ���
//				if (isPalindrome(s, j, i - 1)) {
//					cut[i] = min(cut[i], 1 + cut[j]);
//				}
//			}
//		}
//		return cut[len];
//	}
//	//�ж��Ƿ���Ĵ�
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


//�ⷨ��
//class Solution {
//public:
//	int minCut(string s) {
//		if (s.empty())
//			return 0;
//		int len = s.size();
//		vector<int> Cut;
//		//��ʼ��Cut
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
//					// ���ַ�Ϊ�����ַ���
//					mat[i][j] = true;
//				}
//				else if (j == i + 1) {
//					// �����ַ������ͬ����Ϊ�����ַ��� 
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
