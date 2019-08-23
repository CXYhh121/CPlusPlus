#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	int T;
//	while (cin >> T)
//	{
//		while (T--)
//		{
//			int N;
//			while (cin >> N)
//			{
//				cin >> N;
//				vector<int> Vec(N);
//				vector<int> dp(N);
//				for (int i = 0; i < N; i++)
//					cin >> Vec[i];
//				dp[0] = Vec[0];
//				for (int i = 0; i < N; ++i)
//				{
//					dp[i] = 1;
//					for (int j = i - 1; j >= 0; j--)
//					{
//						if (Vec[i] > Vec[j])
//							dp[i] = max(dp[i], dp[j] + 1);
//					}
//				}
//				cout << dp.size() << endl;
//			}
//		}
//	}
//	return 0;
//}


////最长不连续单调递增子序列A
//#include<iostream>
//#include<vector>
//
//using namespace std;
//int maxLen(vector<int>& Vec, int n)
//{
//	vector<int> vlen(n, 1);
//	int maxLen = 1;
//	for (int i = 1; i < n; ++i)
//	{
//		for (int j = 0; j < i; ++j)
//		{
//			if (Vec[i] > Vec[j] && vlen[j] + 1 > vlen[i])
//				vlen[i] = vlen[j] + 1;
//		}
//		if (maxLen < vlen[i])
//			maxLen = vlen[i];
//	}
//	return maxLen;
//}
//int main()
//{
//	int T;
//	while (cin >> T)
//	{
//		while (T--)
//		{
//			int n;
//			cin >> n;
//			vector<int> Vec(n);
//			for (int i = 0; i < n; ++i)
//				cin >> Vec[i];
//			cout << maxLen(Vec, n) << endl;
//		}
//	}
//	return 0;
//}


//最长不连续单调递增子序列B
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve(vector<int>& Vec, vector<int>& vlen, int n)
{
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (Vec[i] > Vec[j])
				vlen[i] = max(vlen[i], vlen[j] + 1);
		}
	}
}
int main()
{
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			int n;
			cin >> n;
			vector<int> Vec(n);
			vector<int> vlen(n, 1);
			for (int i = 0; i < n; ++i)
				cin >> Vec[i];
			solve(Vec, vlen, n);
			for (int i = 0; i < vlen.size(); ++i)
				cout << vlen[i] << " ";
			cout << endl;
		}
	}
	return 0;
}


//背包问题
//#include <iostream>
//#include <string.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int test;
//	cin >> test;
//	while (test--)
//	{
//		int dp[25][25][25];
//		int n, t, m, a[25];
//		cin >> n >> t >> m;
//		for (int i = 1; i <= n; i++)
//			cin >> a[i];
//		memset(dp, 0, sizeof(dp));
//		for (int i = 1; i <= m; ++i) // 前i个背包
//		{
//			for (int j = 1; j <= n; ++j) // 前j件物品
//			{
//				for (int k = 0; k <= t; ++k) // 容量为k
//				{
//					if (k - a[j] >= 0) // 放入
//						dp[i][j][k] = max(max(dp[i][j - 1][k], dp[i][j - 1][k - a[j]] + 1), dp[i - 1][j][t]);
//					// 放入当前背包
//					else // 丢弃
//						dp[i][j][k] = max(dp[i][j - 1][k], dp[i - 1][j][t]);
//					//cout<<i <<" 个背包. "<<j<<" 件物品. "<<k<<" 容量  "<<dp[i][j][k]<<endl;
//				}
//			}
//		}
//		cout << dp[m][n][t] << endl;
//	}
//	return 0;
//}
