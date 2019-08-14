#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//Ա������Ҫ��
//class Solution {
//public:
//	void DFS(unordered_map<int, Employee*>& info, int& sum, int id)
//	{
//		//���ﲻ�ö��������������Ϊ��Ա������������Ϊ�գ���ݹ����
//		sum += info[id]->importance;
//		for (auto& sub : info[id]->subordinates)
//			DFS(info, sum, sub);
//	}
//	int getImportance(vector<Employee*> employees, int id) {
//		if (employees.empty())
//			return 0;
//		//��unordered_map�洢Ա����Ӧid����Ϣ
//		//����֮�����ʱ��ͨ��id���ʶ�Ӧ��Ա����Ϣ
//		unordered_map<int, Employee*> info;
//		for (auto& kv : employees)
//			info[kv->id] = kv;
//		int sum = 0;
//		DFS(info, sum, id);
//		return sum;
//	}
//};


//ͼ����Ⱦ��������������㷨
/*
������Ŀ����˼: ��λ��(1��1)��ʼ��������Ⱦ��ֻҪ��Ⱦ�����ɫֵ��(1��1)λ�õ���ɫֵ��ͬ��������� ����Ⱦ
1 1 1  2 2 2
1 1 0  2 2 0
1 0 1  2 0 1 
����ÿһ������Ҫ��ĵ㶼Ҫ���ĸ�������Ⱦ
�߽�:λ���Ƿ�Խ�� ������Ҫ�õı�ǣ������ظ��޸ģ�ʹʱ�临�ӶȲ�����O(row * col)
*/

//class Solution {
//public:
//	int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//	void DFS(vector<vector<int>>& image, vector<vector<int>>& book, int sr, int sc, int oldColor, int newColor)
//	{
//		image[sr][sc] = newColor;
//		book[sr][sc] = 1;
//		//�����������ĸ���������
//		for (int k = 0; k < 4; ++k)
//		{
//			int p = sr + pos[k][0];
//			int q = sc + pos[k][1];
//			//���λ�ò��Ϸ�����������������λ��
//			if (p < 0 || p >= image.size() || q < 0 || q >= image[0].size())
//				continue;
//			//�����λ�õ���ɫ��֮ǰ����ɫһ������û��Ⱦɫ���ͽ���λ��Ⱦɫ,������������λ��
//			if (image[p][q] == oldColor && book[p][q] == 0)
//				DFS(image, book, p, q, oldColor, newColor);
//		}
//	}
//	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//		if (image.empty())
//			return image;
//		int row = image.size();
//		int col = image[0].size();
//		//����һ����imageһ����С�����飬��¼��λ���Ƿ���Ⱦ
//		vector<vector<int>> book(row, vector<int>(col, 0));
//		int oldColor = image[sr][sc];
//		DFS(image, book, sr, sc, oldColor, newColor);
//
//		return image;
//	}
//};

//
/* �������˼����Χ�����䲻������ڱ߽��ϣ����Ա߽��ϵ�O�Լ���O��ͨ�Ķ���������Χ��
ֻҪ�ѱ߽��ϵ�o�Լ���֮�� ͨ��o�������⴦��ʣ�µ�o�滻��x���ɡ�
������ת��Ϊ�����Ѱ�Һͱ߽���ͨ��o��������Ҫ�������������
X X X X
X O O X
X X O X
X O O X
��ÿһ����Ե��o��ʼ��ֻҪ�ͱ�Ե��o��ͨ��������û�б���Χ�� 
1.����Ѱ�ұ��ϵ�ÿһ��o�����û�У���ʾ���е�o������Χ
2.���ڱ��ϵ�ÿһ��o����dfs������ɢ���Ȱѱ��ϵ�ÿһ��o��������ű�ǣ�����*��#�ȣ�
3.�Ѻ������ڵ�o���滻Ϊ������ţ�ÿһ���µ�λ�ö�����ͬ��dfs����
4.������ɢ����֮�󣬰�������ŵ�λ��(�ͱ߽���ͨ)��ԭΪo,ԭ��Ϊo��λ��(�ͱ߽粻��ͨ)�滻Ϊx���ɡ�
����һ��Ҫע�������Ǵ�'O'�ʹ�'X' */
//class Solution {
//public:
//	int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//	void DFS(vector<vector<char>>& board, int row, int col, int x, int y)
//	{
//		//����ǰλ�ñ��Ϊ*
//		board[x][y] = '*';
//		//������λ�����������ĸ�λ���Ƿ���������O
//		for (int k = 0; k < 4; k++)
//		{
//			int p = x + pos[k][0];
//			int q = y + pos[k][1];
//
//			//�����λ�ò��Ϸ����������������λ��
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
//		//������һ�к����һ�У���O
//		for (int i = 0; i < col; i++)
//		{
//			if (board[0][i] == 'O')
//				DFS(board, row, col, 0, i);
//			if (board[row - 1][i] == 'O')
//				DFS(board, row, col, row - 1, i);
//		}
//		//������һ�к����һ�У���O
//		for (int j = 0; j < row; j++)
//		{
//			if (board[j][0] == 'O')
//				DFS(board, row, col, j, 0);
//			if (board[j][col - 1] == 'O')
//				DFS(board, row, col, j, col - 1);
//		}
//
//		//����������飬�ҳ����λ�ñ�ΪO
//		//�ҳ���������֮������ΪO��λ���滻ΪX
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