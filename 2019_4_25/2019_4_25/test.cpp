#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;


//LeetCode118���������
//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int>> vv;//�൱�ڴ�����һ����ά���飬һ��vector�������һ��vector
//
//		vv.resize(numRows);//Ϊ��һ��vector���ռ�
//
//		for (size_t i = 0; i < vv.size(); ++i)
//		{
//			vv[i].resize(i + 1, 0);//Ϊ����vv�е�vector���ٿռ�,��������ֵ�ó�0
//			vv[i][0] = 1;
//			vv[i][vv[i].size() - 1] = 1;
//		}
//
//		//���±���һ��vector���ҵ�Ϊ0��λ��
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




//LeetCode119���������II
//class Solution {
//public:
//	vector<int> getRow(int rowIndex) {
//		vector<int> Row(rowIndex + 1, 1);//����һ��vector����ֵȫ��ʼ��Ϊ1
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

