#define _CRT_SECURE_NO_WARNINGS

//�����㷨�������
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
//		return; //���ϻ��� 
//		for (int i = 1; i <= n; i++)
//		{
//			if (book[i] == 0) //��i������������
//			{
//				boxs[index] = i;
//				book[i] = 1; //���ڵ�i�����Ѿ������� //������һ������
//				Dfs(index + 1, n, boxs, book); //����һ�����ӻ��˵���ǰ���ӣ�ȡ����ǰ���ӵ��ƣ� //���Է��������ơ�
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





//�����㷨Ա������Ҫ��
/*
	�߽�: ����Ϊ��
	ÿ���ȼӵ�һ����������Ҫ��
	������ͬ�Ĳ�����ȥ�������ĵ�һ����������Ҫ��
*/
//class Solution {
//public:
//	void dfs(unordered_map<int, Employee*>& info, int& sum, int id)
//	{
//		//���������жϱ߽磬forѭ������һ���߽磬����Ϊ�գ�ֱ�ӽ��� sum += info[id]->importance;
//		for (const auto& subid : info[id]->subordinates)
//		{
//			dfs(info, sum, subid);
//		}
//	}
//	int getImportance(vector<Employee*> employees, int id) {
//		if (employees.empty())
//			return 0;
//		unordered_map<int, Employee*> info; //��Ա����Ϣ��map�洢����������ʹ�� for(const auto& e : employees)
//		info[e->id] = e;
//		int sum = 0;
//		dfs(info, sum, id);
//		return sum;
//	}
//};