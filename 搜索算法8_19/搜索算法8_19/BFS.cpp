#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//广度优先搜索的模型
/*Bfs() {
	1. 建立起始步骤，队列初始化
		2. 遍历队列中的每一种可能，whlie(队列不为空) {
			通过队头元素带出下一步的所有可能，并且依次入队
			{
				判断当前情况是否达成目标:按照目标要求处理逻辑
			}
			继续遍历队列中的剩余情况
		}
}*/

//迷宫问题
//最关键的步骤用当前位置带出新的位置，新的位置可以存放在一个vector或者队列中。
//位置需要 用坐标表示，这里封装出一个node

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
////用队列实现迷宫问题
//bool BFS(vector<vector<int>> graph, int startx, int starty, int destx, int desty)
//{
//	int row = graph.size();
//	int col = graph[0].size();
//
//	//定义一个队列存储当前节点
//	queue<node> nq;
//
//	//定义一个二维数组标记该位置有没有被走过
//	vector<vector<int>> book(row, vector<int>(col, 0));
//	//将当前位置插入队列中，并标记该位置已经走过
//	nq.push(node(startx, starty));
//	book[startx][starty] = 1;
//
//	//表示能向上下左右四个方向走
//	int nextpos[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
//	//表中是否能够走出迷宫
//	bool flag = false;
//	while (!nq.empty())
//	{
//		for (int k = 0; k < 4; ++k)
//		{
//			int p = nq.front()._x + nextpos[k][0];
//			int q = nq.front()._y + nextpos[k][1];
//			//若是该位置不符合条件继续搜索其他位置
//			if (p >= row || p < 0 || q >= col || q < 0)
//				continue;
//			//如果该位置没有障碍，且该位置没有被走过就可以走，保存该位置
//			if (graph[p][q] == 0 && book[p][q] == 0)
//			{
//				nq.push(node(p, q));
//				//标志该位置已经走过
//				book[p][q] = 1;
//			}
//			//如果该位置为目标位置，就可以走出循环
//			if (p == destx && q == desty)
//			{
//				flag = true;
//				break;
//			}
//		}
//
//		//若flag为true，说明走到了目标位置
//		if (flag)
//			break;
//		//否则只要队列不为空，用队列中的位置继续走
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
//	cout << "请输入迷宫的大小: 行，列:" << endl; 
//	cin >> m >> n;
//	graph.resize(m);
//	for (size_t i = 0; i < m; ++i)
//	{
//		graph[i].resize(n);
//	}
//	cout << "请输入迷宫的元素" << endl; 
//	for (size_t i = 0; i < m; ++i)
//	{
//		for (size_t j = 0; j < n; ++j)
//		{
//			cin >> graph[i][j];
//		}
//	}
//	while (1)
//	{
//		cout << "请输入迷宫入口和出口" << endl; 
//		cin >> sx >> sy >> ex >> ey;
//		cout << "是否可以走出迷宫: " << BFS(graph, sx, sy, ex, ey) << endl;
//	}
//	return 0;
//}


//广度优先搜索解决员工的重要性
//class Solution {
//public:
//	int getImportance(vector<Employee*> employees, int id) {
//		int res = 0;
//		queue<int> q;
//		//初始化队列
//		q.push(id); //把员工信息保存在map中，方便查询
//		unordered_map<int, Employee*> m; 
//		for (auto e : employees)
//		m[e->id] = e; //遍历队列
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

//广度优先搜索解决N叉树的层序遍历
//class Solution {
//public:
//	vector<vector<int>> levelOrder(Node* root) {
//		vector<vector<int>> treeVec;
//		queue<Node*> q;
//		if (root == NULL)
//			return treeVec;
//		//根结点入队
//		q.push(root);
//		while (!q.empty())
//		{
//			//队列中的元素属于同一层节点
//			int sz = q.size();
//			vector<int> rowNode;
//			while (sz--)
//			{
//				Node* curNode = q.front();
//				q.pop();
//				//保存当前节点
//				rowNode.push_back(curNode->val);
//				//让当前节点的孩子入队
//				for (auto& child : curNode->children)
//					q.push(child);
//			}
//			//走到这rowNode中保存的就是一层的节点，将一层节点放入treeVec中
//			treeVec.push_back(rowNode);
//		}
//		return treeVec;
//	}
//};