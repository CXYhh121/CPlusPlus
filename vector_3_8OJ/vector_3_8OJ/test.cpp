#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//�绰��������
//string letterMap[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//class Solution {
//public:
//	void _letterCombinations(vector<string>& vcombin, const string& digits, size_t index, string str)
//	{
		//if (index == digits.size())
		//{
		//	vcombin.push_back(str);
		//	return;
		//}
		////ȡ�����ֵĶ�Ӧ�ַ�
		//const string& letters = letterMap[digits[index] - '0'];
		////�ݹ�
		//for (size_t i = 0; i<letters.size(); ++i)
		//{
		//	_letterCombinations(vcombin, digits, index + 1, str + letters[i]);
		//}
//	}
//	vector<string> letterCombinations(string digits) {
//		vector<string> vcombin;//����һ��vector������е���ĸ���
//		if (digits.empty())
//			return vcombin;
//
//		size_t index = 0;//����һ���±꣬��־���ʵ�һ�����ֵ���һ��
//		string str;//����һ���ַ������洢������Ӧ���ַ���
//
//
//		_letterCombinations(vcombin, digits, index, str);
//
//		return vcombin;
//	}
//};
//
//int main()
//{
//	Solution s;
//	string digits = "23";
//	s.letterCombinations(digits);
//	return 0;
//}

//�������
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		vv.resize(numRows);

		for (size_t i = 0; i < vv.size(); ++i)
		{
			vv[i].resize(i + 1, 0);
			vv[i][0] = 1;
			vv[i][vv[i].size() - 1] = 1;
		}

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}

			}
		}

		return vv;
	}
};

int main()
{
	Solution s;
	s.generate(5);
	return 0;
}