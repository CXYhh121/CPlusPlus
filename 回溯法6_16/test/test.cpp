#define _CRT_SECURE_NO_WARNINGS


//���ݷ���������װ������
#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;
int n;                    //��Ʒ����
int c1, c2;               //�ִ�����
int w[MAX];             //��Ʒ����
int x[MAX];            //��Ʒѡ��
int cw = 0;           //��ǰװ����
int bestw = 0;       //����װ��

//�Ӻ�����������ʹ��һ�Ҵ�װ�����ﵽ���
void backpack(int t){
	if (t > n){
		if (cw > bestw){
			bestw = cw;
			return;
		}
	}
	else{
		for(int j = 0; j <= 1; j++){     //ö������t���п��ܵ�·����
			x[t] = j;
			if (cw + w[t]*x[t] <= c1){     //Լ��Ϊ��ǰ��װ����������ܳ���c1ʣ������
				cw += w[t]*x[t];
				backpack(t + 1);
				cw -= w[t]*x[t];
			}
		}
	}
}
int main(){
	cin >> c1 >> c2 >> n;    //�ִ�c1,c2����������Լ���װ������
	while (n){
		int sum = 0;    //��װ��������
		for (int i = 1; i <= n; i++){//ѭ�����㼯װ���������
			cin >> w[i];
			sum += w[i];
		}
		backpack(1);//�����Ӻ��������һ�Ҵ������װ����
		if (sum - bestw <= c2){     //��װ��ʣ��������c2�ִ��������Ƚ�
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
		bestw = 0;                //bestw��λ0
		cin >> c1 >> c2 >> n;
	}
	return 0;
}


//n�ʺ�����
//#include "stdafx.h"
//#include<iostream>
//using namespace std;
//class Queen {
//	friend int nQueen(int);
//private:
//	bool Place(int k);
//	void Backtrack(int t);
//	int n,     //�ʺ����
//		*x;    //��ǰ��
//	long sum;  //��ǰ���ҵ��Ŀ��з�����
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
//	//��ʼ��X
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
//	cout << "������ʺ������"; cin >> n;
//	cout << "���з������н⣺" << endl;
//	set = nQueen(n);
//	cout << "���з�������" << set << endl;
//}