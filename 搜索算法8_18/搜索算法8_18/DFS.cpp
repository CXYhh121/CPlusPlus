#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
	void DFS(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& book, int x, int y)
	{
		//将当前位置标记为*
		book[x][y] = 1;
		//搜索该位置上下左右四个位置是否有相连的O
		for (int k = 0; k < 4; k++)
		{
			int p = x + pos[k][0];
			int q = y + pos[k][1];

			//如果该位置不合法，则继续搜索其他位置
			if (p < 0 || p >= row || q < 0 || q >= col)
				continue;
			if (grid[p][q] == '1' && book[p][q] == 0)
				DFS(grid, row, col, book, p, q);
		}

	}

	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;
		int ret = 0;
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> book;
		book.resize(row);
		for (int i = 0; i < row; ++i)
			book[i].resize(col, 0);
		//以每一个网格点为渲染起点开始
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == '1' && book[i][j] == 0)
				{
					++ret;
					DFS(grid, row, col, book, i, j);
				}
			}
		}
		return ret;
	}

};
