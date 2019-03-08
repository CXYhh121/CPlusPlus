#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//电话号码的组合
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
		////取得数字的对应字符
		//const string& letters = letterMap[digits[index] - '0'];
		////递归
		//for (size_t i = 0; i<letters.size(); ++i)
		//{
		//	_letterCombinations(vcombin, digits, index + 1, str + letters[i]);
		//}
//	}
//	vector<string> letterCombinations(string digits) {
//		vector<string> vcombin;//定义一个vector存放所有的字母组合
//		if (digits.empty())
//			return vcombin;
//
//		size_t index = 0;//定义一个下标，标志访问到一串数字的哪一个
//		string str;//定义一个字符串，存储数字相应的字符串
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

//杨辉三角
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