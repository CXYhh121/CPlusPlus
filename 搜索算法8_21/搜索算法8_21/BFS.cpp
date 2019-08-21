#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/*
����������ҵ����еĸ������ӣ���ӣ��õ�һ��������һ�����õ�����
ÿ��ƥ���Ӷ�����һ����֮�ڸ���,���Դ������ת��Ϊ��BFSִ�еĴ�ѭ���Ĵ��� 
�����step�ĸ�����Ҫ��һ����ǣ�ֻ���µĸ��õ����Ӽ��룬step�����Լ�
���BFSִ����֮��˵�����п��Ա����õĶ�����ˣ���ȥ����grid,��λ��� ֵΪ1�ģ�
˵��û�а취��ȫ���ã�����-1,���û�У��򷵻�step
*/

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) { 
		//��pair���λ��
		queue<pair<int, int>> q;
		int row = grid.size();
		int col = grid[0].size(); //�Ѿ����õ�λ�����
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == 2)
					q.push(make_pair(i, j));
			}
		}
		//�������ӵķ���
		static int nextP[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; int step = 0;
		while (!q.empty())
		{
			int n = q.size();
			int flag = 0; //�õ�ǰ��һ���Ѿ����õ����Ӵ�����һ��Ҫ���õ����� //��Ҫ���������е�����λ��
			while (n--)
			{
				auto Curpos = q.front(); q.pop(); //��ǰλ�����ĸ���������
				for (int i = 0; i < 4; ++i)
				{
					int nx = Curpos.first + nextP[i][0];
					int ny = Curpos.second + nextP[i][1]; //���λ��Խ������ǿո񣬻����Ѿ��Ǹ��õ�λ�ã������� 
					if (nx >= row || nx < 0 
						|| ny >= col || ny < 0
						|| grid[nx][ny] != 1)
						continue;
					//������µı�����
					flag = 1;
					grid[nx][ny] = 2; q.push(make_pair(nx, ny));
				}
			}
			
			//������µĸ��ã���++ if(flag)
			++step;
		}
		//�ж��Ƿ����޷����õ�
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == 1)
					return -1;
			}
		}
		return step;
	}
};



//
/*
1.ͨ��BFS, ������beginWord����ת��һ����ĸ֮�����п��ܵĽ�� 
2.ÿһ����Ҫ�Ѷ�������һ����ӵ����е���ת��һ�飬��̵�ת���϶�����Щ���ʵ��У� 
  ������Щ�ʵ�ת��ֻ����һ ��ת������Ϊ������һ��ת�������ģ�
  �������ÿ�����ʵ�ÿ��λ�ö�������26����ĸ����ת��������һ������һ��ת�� �Ŀ�����:���ʵĳ��� * 26
3.��ת���ɹ����´���ӣ�������һ����ת��
4.�������ת���ĳ��Ⱦͺ�BFSִ�еĴ�����ͬ
*/
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		//hash��Ĳ�ѯЧ�����
		unordered_set<string> wordDict(wordList.begin(), wordList.end());
		//��ǵ����Ƿ��Ѿ����ʹ������ʹ��Ĳ��ٷ���
		unordered_set<string> visited; visited.insert(beginWord); //��ʼ������
		queue<string> q; q.push(beginWord);
		int res = 1;
		while (!q.empty()){
			int nextSize = q.size(); 
			//ÿһ����Ҫ�Ѷ�������һ����ӵ����е���ת��һ�� 
			//��̵�ת���϶�����Щ���ʵ��У� ������Щ�ʵ�ת��ֻ����һ��ת�� 
			//��Ϊ������һ��ת��������
			while (nextSize--){
				string curWord = q.front();
				q.pop();
				//����ת����ǰ���ʵ�ÿһ��λ��
				for (int i = 0; i < curWord.size(); i++){
					string newWord = curWord; 
					//ÿһ��λ����26����ĸ�ֱ��滻
					for (auto ch = 'a'; ch <= 'z'; ch++){
						newWord[i] = ch;
						//����б���û�д˵��ʻ����Ѿ����ʹ�(����ת���Ѿ��������������ٴα���)����
						if (!wordDict.count(newWord) || visited.count(newWord))
							continue;
						//ת���ɹ���������һ��ת���Ļ�����+1 if (newWord == endWord)
						return res + 1; 
						//��û��ת���ɹ������µĵ������
						visited.insert(newWord);
						q.push(newWord);
					}
				}
			}
			res++;
		}
		//ת�����ɹ�������0
		return 0;
	}
};
