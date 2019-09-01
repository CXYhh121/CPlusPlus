#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

//单词接龙
/*
1.通过BFS, 首先用beginWord带出转换一个字母之后所有可能的结果 2.每一步都要把队列中上一步添加的所有单词转换一遍，最短的转换肯定在这些单词当中， 所有这些词的转换只能算一 次转换，因为都是上一步转换出来的，这里对于每个单词的每个位置都可以用26个字母进行转换，所以一个单词一次转换 的可能有:单词的长度 * 26
3.把转换成功的新词入队，进行下一步的转换
4.最后整个转换的长度就和BFS执行的次数相同
*/
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) { //hash表的查询效率最高
		unordered_set<string> wordDict(wordList.begin(), wordList.end()); //标记单词是否已经访问过，访问过的不再访问
		unordered_set<string> visited; visited.insert(beginWord); //初始化队列
		queue<string> q; 
		q.push(beginWord);
		int res = 1;
		while (!q.empty()){
				int nextSize = q.size(); //每一步都要把队列中上一步添加的所有单词转换一遍 //最短的转换肯定在这些单词当中， 所有这些词的转换只能算一次转换 //因为都是上一步转换出来的
			while (nextSize--){
				string curWord = q.front();
				q.pop();
				//尝试转换当前单词的每一个位置
				for (int i = 0; i < curWord.size(); i++){
					string newWord = curWord; //每一个位置用26个字母分别替换
					for (auto ch = 'a'; ch <= 'z'; ch++){
						newWord[i] = ch; //如果列表中没有此单词或者已经访问过(它的转换已经遍历过，无需再次遍历)，则
						if (!wordDict.count(newWord) || visited.count(newWord))
							continue;
						//转换成功，则在上一步转换的基础上+1 if (newWord == endWord)
						return res + 1; //还没有转换成功，则新的单词入队
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


//打开转盘锁
/*
深度优先不适合解此题，递归深度太大，会导致栈溢出
本题的密码为4位密码，每位密码可以通过拨动一次进行改变，注意这里的数的回环以及拨动的方向 
拨动方向:向前，向后 回环:如果当前是9，0时，向前，向后拨动需要变成最小最大，而不是简单的自加自减
*/
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		// 哈希表的查找更快
		unordered_set<string> deadendsSet(deadends.begin(), deadends.end()); 
		//如果"0000"在死亡字符串中，则永远到达不了
		if (deadendsSet.find("0000") != deadendsSet.end())
			return -1; //初始化队列
		queue<string> que;
		que.push("0000");
		//加标记，已经搜索过的字符串不需要再次搜索 
		unordered_set<string> book; 
		book.insert("0000");

		int step = 0;
		while (!que.empty()) {
			int n = que.size(); 
			//从上一步转换之后的字符串都需要进行验证和转换 
			//并且只算做一次转换，类似于层序遍历，转换的步数和层相同 
			//同一层的元素都是经过一步转换得到的
			for (int i = 0; i < n; i++) {
				string curStr = que.front();
				que.pop();
				if (curStr == target) 
					return step;
				//四位密码锁，每个位置每次都可以转一次
				for (int j = 0; j < 4; j++) {
					string newStr1 = curStr, newStr2 = curStr; //当前位置可以向前或者向后拨一位
					newStr1[j] = newStr1[j] == '9' ? '0' : newStr1[j] + 1;
					newStr2[j] = newStr2[j] == '0' ? '9' : newStr2[j] - 1;
					if (deadendsSet.find(newStr1) == deadendsSet.end()
						&& book.find(newStr1) == book.end()) {
						que.push(newStr1);
						book.insert(newStr1);
					}
					if (deadendsSet.find(newStr2) == deadendsSet.end()
						&& book.find(newStr2) == book.end()) {
						que.push(newStr2);
						book.insert(newStr2);
					}
				}
			}
			step++;
		}
		return -1; 
	}
};