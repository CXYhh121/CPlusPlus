#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//�������������ģ��
/*Bfs() {
	1. ������ʼ���裬���г�ʼ��
		2. ���������е�ÿһ�ֿ��ܣ�whlie(���в�Ϊ��) {
			ͨ����ͷԪ�ش�����һ�������п��ܣ������������
			{
				�жϵ�ǰ����Ƿ���Ŀ��:����Ŀ��Ҫ�����߼�
			}
			�������������е�ʣ�����
		}
}*/

//�Թ�����
//��ؼ��Ĳ����õ�ǰλ�ô����µ�λ�ã��µ�λ�ÿ��Դ����һ��vector���߶����С�
//λ����Ҫ �������ʾ�������װ��һ��node

//struct node{
//	int _x;
//	int _y;
//	node(int x, int y)
//	{
//		_x = x;
//		_y = y;
//	}
//};
//
////�ö���ʵ���Թ�����
//bool BFS(vector<vector<int>> graph, int startx, int starty, int destx, int desty)
//{
//	int row = graph.size();
//	int col = graph[0].size();
//
//	//����һ�����д洢��ǰ�ڵ�
//	queue<node> nq;
//
//	//����һ����ά�����Ǹ�λ����û�б��߹�
//	vector<vector<int>> book(row, vector<int>(col, 0));
//	//����ǰλ�ò�������У�����Ǹ�λ���Ѿ��߹�
//	nq.push(node(startx, starty));
//	book[startx][starty] = 1;
//
//	//��ʾ�������������ĸ�������
//	int nextpos[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
//	//�����Ƿ��ܹ��߳��Թ�
//	bool flag = false;
//	while (!nq.empty())
//	{
//		for (int k = 0; k < 4; ++k)
//		{
//			int p = nq.front()._x + nextpos[k][0];
//			int q = nq.front()._y + nextpos[k][1];
//			//���Ǹ�λ�ò���������������������λ��
//			if (p >= row || p < 0 || q >= col || q < 0)
//				continue;
//			//�����λ��û���ϰ����Ҹ�λ��û�б��߹��Ϳ����ߣ������λ��
//			if (graph[p][q] == 0 && book[p][q] == 0)
//			{
//				nq.push(node(p, q));
//				//��־��λ���Ѿ��߹�
//				book[p][q] = 1;
//			}
//			//�����λ��ΪĿ��λ�ã��Ϳ����߳�ѭ��
//			if (p == destx && q == desty)
//			{
//				flag = true;
//				break;
//			}
//		}
//
//		//��flagΪtrue��˵���ߵ���Ŀ��λ��
//		if (flag)
//			break;
//		//����ֻҪ���в�Ϊ�գ��ö����е�λ�ü�����
//		nq.pop();
//	}
//	return flag;
//}
//
//int main()
//{
//	int sx, sy, ex, ey;
//	vector<vector<int>> graph;
//	int m, n;
//	cout << "�������Թ��Ĵ�С: �У���:" << endl; 
//	cin >> m >> n;
//	graph.resize(m);
//	for (size_t i = 0; i < m; ++i)
//	{
//		graph[i].resize(n);
//	}
//	cout << "�������Թ���Ԫ��" << endl; 
//	for (size_t i = 0; i < m; ++i)
//	{
//		for (size_t j = 0; j < n; ++j)
//		{
//			cin >> graph[i][j];
//		}
//	}
//	while (1)
//	{
//		cout << "�������Թ���ںͳ���" << endl; 
//		cin >> sx >> sy >> ex >> ey;
//		cout << "�Ƿ�����߳��Թ�: " << BFS(graph, sx, sy, ex, ey) << endl;
//	}
//	return 0;
//}


//��������������Ա������Ҫ��
//class Solution {
//public:
//	int getImportance(vector<Employee*> employees, int id) {
//		int res = 0;
//		queue<int> q;
//		//��ʼ������
//		q.push(id); //��Ա����Ϣ������map�У������ѯ
//		unordered_map<int, Employee*> m; 
//		for (auto e : employees)
//		m[e->id] = e; //��������
//		while (!q.empty()) {
//			int t = q.front();
//			q.pop();
//			res += m[t]->importance;
//			for (int num : m[t]->subordinates) {
//				q.push(num);
//			}
//		}
//		return res;
//	}
//};

//��������������N�����Ĳ������
//class Solution {
//public:
//	vector<vector<int>> levelOrder(Node* root) {
//		vector<vector<int>> treeVec;
//		queue<Node*> q;
//		if (root == NULL)
//			return treeVec;
//		//��������
//		q.push(root);
//		while (!q.empty())
//		{
//			//�����е�Ԫ������ͬһ��ڵ�
//			int sz = q.size();
//			vector<int> rowNode;
//			while (sz--)
//			{
//				Node* curNode = q.front();
//				q.pop();
//				//���浱ǰ�ڵ�
//				rowNode.push_back(curNode->val);
//				//�õ�ǰ�ڵ�ĺ������
//				for (auto& child : curNode->children)
//					q.push(child);
//			}
//			//�ߵ���rowNode�б���ľ���һ��Ľڵ㣬��һ��ڵ����treeVec��
//			treeVec.push_back(rowNode);
//		}
//		return treeVec;
//	}
//};