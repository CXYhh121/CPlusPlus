#define _CRT_SECURE_NO_WARNINGS


//回溯法计算最优装载问题
#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;
int n;                    //物品个数
int c1, c2;               //轮船载重
int w[MAX];             //物品重量
int x[MAX];            //物品选择
int cw = 0;           //当前装载量
int bestw = 0;       //最优装载

//子函数，求解如何使第一艘船装载量达到最大
void backpack(int t){
	if (t > n){
		if (cw > bestw){
			bestw = cw;
			return;
		}
	}
	else{
		for(int j = 0; j <= 1; j++){     //枚举物体t所有可能的路径，
			x[t] = j;
			if (cw + w[t]*x[t] <= c1){     //约束为当前集装箱的重量不能超过c1剩余重量
				cw += w[t]*x[t];
				backpack(t + 1);
				cw -= w[t]*x[t];
			}
		}
	}
}
int main(){
	cin >> c1 >> c2 >> n;    //轮船c1,c2最大载重量以及集装箱数量
	while (n){
		int sum = 0;    //集装箱总重量
		for (int i = 1; i <= n; i++){//循环计算集装箱的总重量
			cin >> w[i];
			sum += w[i];
		}
		backpack(1);//调用子函数计算第一艘船的最大装载量
		if (sum - bestw <= c2){     //集装箱剩余重量与c2轮船载重量比较
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
		bestw = 0;                //bestw复位0
		cin >> c1 >> c2 >> n;
	}
	return 0;
}


//n皇后问题
//#include "stdafx.h"
//#include<iostream>
//using namespace std;
//class Queen {
//	friend int nQueen(int);
//private:
//	bool Place(int k);
//	void Backtrack(int t);
//	int n,     //皇后个数
//		*x;    //当前解
//	long sum;  //当前已找到的可行方案数
//};
//bool Queen::Place(int k) {
//	for (int j = 1; j < k; j++)
//	if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
//		return false;
//	return true;
//}
//void Queen::Backtrack(int t) {
//	if (t > n) {
//		for (int i = 1; i <= n; i++)
//			cout << x[i] << " ";
//		cout << endl;
//		sum++;
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			x[t] = i;
//			if (Place(t)) Backtrack(t + 1);
//		}
//	}
//}
//int nQueen(int n) {
//	Queen X;
//	//初始化X
//	X.n = n;
//	X.sum = 0;
//	int* p = new int[n + 1];
//	for (int i = 0; i <= n; i++)
//		p[i] = 0;
//	X.x = p;
//	X.Backtrack(1);
//	delete[] p;
//	return X.sum;
//}
//int main() {
//	int n, set;
//	cout << "请输入皇后个数："; cin >> n;
//	cout << "可行方案所有解：" << endl;
//	set = nQueen(n);
//	cout << "可行方案数：" << set << endl;
//}