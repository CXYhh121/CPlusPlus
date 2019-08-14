#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//员工的重要性
//class Solution {
//public:
//	void DFS(unordered_map<int, Employee*>& info, int& sum, int id)
//	{
//		//这里不用定义结束条件，因为若员工下属的数组为空，则递归结束
//		sum += info[id]->importance;
//		for (auto& sub : info[id]->subordinates)
//			DFS(info, sum, sub);
//	}
//	int getImportance(vector<Employee*> employees, int id) {
//		if (employees.empty())
//			return 0;
//		//用unordered_map存储员工对应id及信息
//		//方便之后遍历时，通过id访问对应的员工信息
//		unordered_map<int, Employee*> info;
//		for (auto& kv : employees)
//			info[kv->id] = kv;
//		int sum = 0;
//		DFS(info, sum, id);
//		return sum;
//	}
//};


//图像渲染，广度优先搜索算法
/*
比如题目的意思: 以位置(1，1)开始，向外渲染，只要渲染点的颜色值和(1，1)位置的颜色值相同，则继续向 外渲染
1 1 1  2 2 2
1 1 0  2 2 0
1 0 1  2 0 1 
这里每一个符合要求的点都要向四个方向渲染
边界:位置是否越界 这里需要用的标记，避免重复修改，使时间复杂度不超过O(row * col)
*/

//class Solution {
//public:
//	int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//	void DFS(vector<vector<int>>& image, vector<vector<int>>& book, int sr, int sc, int oldColor, int newColor)
//	{
//		image[sr][sc] = newColor;
//		book[sr][sc] = 1;
//		//向上下左右四个方向延伸
//		for (int k = 0; k < 4; ++k)
//		{
//			int p = sr + pos[k][0];
//			int q = sc + pos[k][1];
//			//如果位置不合法，继续搜索其他的位置
//			if (p < 0 || p >= image.size() || q < 0 || q >= image[0].size())
//				continue;
//			//如果该位置的颜色和之前的颜色一样，且没被染色，就将该位置染色,继续搜索其他位置
//			if (image[p][q] == oldColor && book[p][q] == 0)
//				DFS(image, book, p, q, oldColor, newColor);
//		}
//	}
//	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//		if (image.empty())
//			return image;
//		int row = image.size();
//		int col = image[0].size();
//		//定义一个和image一样大小的数组，记录该位置是否被渲染
//		vector<vector<int>> book(row, vector<int>(col, 0));
//		int oldColor = image[sr][sc];
//		DFS(image, book, sr, sc, oldColor, newColor);
//
//		return image;
//	}
//};

//
/* 本题的意思被包围的区间不会存在于边界上，所以边界上的O以及与O联通的都不算做包围，
只要把边界上的o以及与之联 通的o进行特殊处理，剩下的o替换成x即可。
故问题转化为，如何寻找和边界联通的o，我们需要考虑如下情况。
X X X X
X O O X
X X O X
X O O X
从每一个边缘的o开始，只要和边缘的o联通，则它就没有被包围。 
1.首先寻找边上的每一个o，如果没有，表示所有的o都被包围
2.对于边上的每一个o进行dfs进行扩散，先把边上的每一个o用特殊符号标记，比如*，#等，
3.把和它相邻的o都替换为特殊符号，每一个新的位置都做相同的dfs操作
4.所有扩散结束之后，把特殊符号的位置(和边界连通)还原为o,原来为o的位置(和边界不连通)替换为x即可。
这里一定要注意这里是大'O'和大'X' */
//class Solution {
//public:
//	int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//	void DFS(vector<vector<char>>& board, int row, int col, int x, int y)
//	{
//		//将当前位置标记为*
//		board[x][y] = '*';
//		//搜索该位置上下左右四个位置是否有相连的O
//		for (int k = 0; k < 4; k++)
//		{
//			int p = x + pos[k][0];
//			int q = y + pos[k][1];
//
//			//如果该位置不合法，则继续搜索其他位置
//			if (p < 0 || p >= row || q < 0 || q >= col)
//				continue;
//			if (board[p][q] == 'O')
//				DFS(board, row, col, p, q);
//		}
//
//	}
//	void solve(vector<vector<char>>& board) {
//		if (board.empty())
//			return;
//		int row = board.size();
//		int col = board[0].size();
//		//遍历第一行和最后一行，找O
//		for (int i = 0; i < col; i++)
//		{
//			if (board[0][i] == 'O')
//				DFS(board, row, col, 0, i);
//			if (board[row - 1][i] == 'O')
//				DFS(board, row, col, row - 1, i);
//		}
//		//遍历第一列和最后一列，找O
//		for (int j = 0; j < row; j++)
//		{
//			if (board[j][0] == 'O')
//				DFS(board, row, col, j, 0);
//			if (board[j][col - 1] == 'O')
//				DFS(board, row, col, j, col - 1);
//		}
//
//		//遍历这个数组，找出标记位置变为O
//		//找出经过搜索之后依旧为O的位置替换为X
//		for (int i = 0; i < row; ++i)
//		{
//			for (int j = 0; j < col; ++j)
//			{
//				if (board[i][j] == '*')
//					board[i][j] = 'O';
//				else if (board[i][j] == 'O')
//					board[i][j] = 'X';
//			}
//		}
//	}
//};