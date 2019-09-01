#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

//���ʽ���
/*
1.ͨ��BFS, ������beginWord����ת��һ����ĸ֮�����п��ܵĽ�� 2.ÿһ����Ҫ�Ѷ�������һ����ӵ����е���ת��һ�飬��̵�ת���϶�����Щ���ʵ��У� ������Щ�ʵ�ת��ֻ����һ ��ת������Ϊ������һ��ת�������ģ��������ÿ�����ʵ�ÿ��λ�ö�������26����ĸ����ת��������һ������һ��ת�� �Ŀ�����:���ʵĳ��� * 26
3.��ת���ɹ����´���ӣ�������һ����ת��
4.�������ת���ĳ��Ⱦͺ�BFSִ�еĴ�����ͬ
*/
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) { //hash��Ĳ�ѯЧ�����
		unordered_set<string> wordDict(wordList.begin(), wordList.end()); //��ǵ����Ƿ��Ѿ����ʹ������ʹ��Ĳ��ٷ���
		unordered_set<string> visited; visited.insert(beginWord); //��ʼ������
		queue<string> q; 
		q.push(beginWord);
		int res = 1;
		while (!q.empty()){
				int nextSize = q.size(); //ÿһ����Ҫ�Ѷ�������һ����ӵ����е���ת��һ�� //��̵�ת���϶�����Щ���ʵ��У� ������Щ�ʵ�ת��ֻ����һ��ת�� //��Ϊ������һ��ת��������
			while (nextSize--){
				string curWord = q.front();
				q.pop();
				//����ת����ǰ���ʵ�ÿһ��λ��
				for (int i = 0; i < curWord.size(); i++){
					string newWord = curWord; //ÿһ��λ����26����ĸ�ֱ��滻
					for (auto ch = 'a'; ch <= 'z'; ch++){
						newWord[i] = ch; //����б���û�д˵��ʻ����Ѿ����ʹ�(����ת���Ѿ��������������ٴα���)����
						if (!wordDict.count(newWord) || visited.count(newWord))
							continue;
						//ת���ɹ���������һ��ת���Ļ�����+1 if (newWord == endWord)
						return res + 1; //��û��ת���ɹ������µĵ������
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


//��ת����
/*
������Ȳ��ʺϽ���⣬�ݹ����̫�󣬻ᵼ��ջ���
���������Ϊ4λ���룬ÿλ�������ͨ������һ�ν��иı䣬ע����������Ļػ��Լ������ķ��� 
��������:��ǰ����� �ػ�:�����ǰ��9��0ʱ����ǰ����󲦶���Ҫ�����С��󣬶����Ǽ򵥵��Լ��Լ�
*/
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		// ��ϣ��Ĳ��Ҹ���
		unordered_set<string> deadendsSet(deadends.begin(), deadends.end()); 
		//���"0000"�������ַ����У�����Զ���ﲻ��
		if (deadendsSet.find("0000") != deadendsSet.end())
			return -1; //��ʼ������
		queue<string> que;
		que.push("0000");
		//�ӱ�ǣ��Ѿ����������ַ�������Ҫ�ٴ����� 
		unordered_set<string> book; 
		book.insert("0000");

		int step = 0;
		while (!que.empty()) {
			int n = que.size(); 
			//����һ��ת��֮����ַ�������Ҫ������֤��ת�� 
			//����ֻ����һ��ת���������ڲ��������ת���Ĳ����Ͳ���ͬ 
			//ͬһ���Ԫ�ض��Ǿ���һ��ת���õ���
			for (int i = 0; i < n; i++) {
				string curStr = que.front();
				que.pop();
				if (curStr == target) 
					return step;
				//��λ��������ÿ��λ��ÿ�ζ�����תһ��
				for (int j = 0; j < 4; j++) {
					string newStr1 = curStr, newStr2 = curStr; //��ǰλ�ÿ�����ǰ�������һλ
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