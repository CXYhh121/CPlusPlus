#define _CRT_SECURE_NO_WARNINGS

//搜索算法排列组合
//#include <vector>
//#include <iostream>
//using namespace std;
//void Dfs(int index, int n, vector<int>& boxs, vector<int>& book) 
//{
//	if (index == n + 1)
//	{
//		for (int i = 1; i <= n; i++)
//			cout << boxs[i] << " ";
//		cout << endl;
//		return; //向上回退 
//		for (int i = 1; i <= n; i++)
//		{
//			if (book[i] == 0) //第i号牌仍在手上
//			{
//				boxs[index] = i;
//				book[i] = 1; //现在第i号牌已经被用了 //处理下一个盒子
//				Dfs(index + 1, n, boxs, book); //从下一个盒子回退到当前盒子，取出当前盒子的牌， //尝试放入其它牌。
//				book[i] = 0;
//			}
//		}
//	}
//}
//int main() 
//{
//	int n;
//	vector<int> boxs;
//	vector<int> books;
//	cin >> n;
//	boxs.resize(n + 1, 0);
//	books.resize(n + 1, 0);
//	Dfs(1, n, boxs, books);
//	return 0;
//}





//搜索算法员工的重要性
/*
	边界: 下属为空
	每次先加第一个下属的重要性
	按照相同的操作再去加下属的第一个下属的重要性
*/
//class Solution {
//public:
//	void dfs(unordered_map<int, Employee*>& info, int& sum, int id)
//	{
//		//这里无需判断边界，for循环就是一个边界，下属为空，直接结束 sum += info[id]->importance;
//		for (const auto& subid : info[id]->subordinates)
//		{
//			dfs(info, sum, subid);
//		}
//	}
//	int getImportance(vector<Employee*> employees, int id) {
//		if (employees.empty())
//			return 0;
//		unordered_map<int, Employee*> info; //把员工信息用map存储，方便后面的使用 for(const auto& e : employees)
//		info[e->id] = e;
//		int sum = 0;
//		dfs(info, sum, id);
//		return sum;
//	}
//};