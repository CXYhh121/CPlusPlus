#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/*
本题可以先找到所有的腐烂橘子，入队，用第一批带出新一批腐烂的橘子
每以匹橘子都会在一分钟之内腐烂,所以此题可以转化为求BFS执行的大循环的次数 
这里的step的更新需要有一个标记，只有新的腐烂的橘子加入，step才能自加
最后BFS执行完之后，说明所有可以被腐烂的都完成了，再去遍历grid,如何还有 值为1的，
说明没有办法完全腐烂，返回-1,如果没有，则返回step
*/

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) { 
		//用pair存放位置
		queue<pair<int, int>> q;
		int row = grid.size();
		int col = grid[0].size(); //已经腐烂的位置入队
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == 2)
					q.push(make_pair(i, j));
			}
		}
		//可以蔓延的方向
		static int nextP[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; int step = 0;
		while (!q.empty())
		{
			int n = q.size();
			int flag = 0; //用当前这一批已经腐烂的橘子带出下一批要腐烂的橘子 //故要遍历队列中的所有位置
			while (n--)
			{
				auto Curpos = q.front(); q.pop(); //当前位置向四个方向蔓延
				for (int i = 0; i < 4; ++i)
				{
					int nx = Curpos.first + nextP[i][0];
					int ny = Curpos.second + nextP[i][1]; //如果位置越界或者是空格，或者已经是腐烂的位置，则跳过 
					if (nx >= row || nx < 0 
						|| ny >= col || ny < 0
						|| grid[nx][ny] != 1)
						continue;
					//标记有新的被腐烂
					flag = 1;
					grid[nx][ny] = 2; q.push(make_pair(nx, ny));
				}
			}
			
			//如果有新的腐烂，才++ if(flag)
			++step;
		}
		//判断是否还有无法腐烂的
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
1.通过BFS, 首先用beginWord带出转换一个字母之后所有可能的结果 
2.每一步都要把队列中上一步添加的所有单词转换一遍，最短的转换肯定在这些单词当中， 
  所有这些词的转换只能算一 次转换，因为都是上一步转换出来的，
  这里对于每个单词的每个位置都可以用26个字母进行转换，所以一个单词一次转换 的可能有:单词的长度 * 26
3.把转换成功的新词入队，进行下一步的转换
4.最后整个转换的长度就和BFS执行的次数相同
*/
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		//hash表的查询效率最高
		unordered_set<string> wordDict(wordList.begin(), wordList.end());
		//标记单词是否已经访问过，访问过的不再访问
		unordered_set<string> visited; visited.insert(beginWord); //初始化队列
		queue<string> q; q.push(beginWord);
		int res = 1;
		while (!q.empty()){
			int nextSize = q.size(); 
			//每一步都要把队列中上一步添加的所有单词转换一遍 
			//最短的转换肯定在这些单词当中， 所有这些词的转换只能算一次转换 
			//因为都是上一步转换出来的
			while (nextSize--){
				string curWord = q.front();
				q.pop();
				//尝试转换当前单词的每一个位置
				for (int i = 0; i < curWord.size(); i++){
					string newWord = curWord; 
					//每一个位置用26个字母分别替换
					for (auto ch = 'a'; ch <= 'z'; ch++){
						newWord[i] = ch;
						//如果列表中没有此单词或者已经访问过(它的转换已经遍历过，无需再次遍历)，则
						if (!wordDict.count(newWord) || visited.count(newWord))
							continue;
						//转换成功，则在上一步转换的基础上+1 if (newWord == endWord)
						return res + 1; 
						//还没有转换成功，则新的单词入队
						visited.insert(newWord);
						q.push(newWord);
					}
				}
			}
			res++;
		}
		//转换不成功，返回0
		return 0;
	}
};
