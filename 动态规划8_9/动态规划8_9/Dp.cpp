#define _CRT_SECURE_NO_WARNINGS

//��̬�滮�ַ����ָ�
//״̬ :
//��״̬ : ǰ1��2��3��..., n���ַ��ܷ���ݴʵ��еĴʱ��ɹ��ִ�
//F(i) : ǰi���ַ��ܷ���ݴʵ��еĴʱ��ɹ��ִ� 
//״̬���� :
//F(i) : true{j <i && F(j) && substr[j + 1, i]���ڴʵ����ҵ�} OR false ��jС��i�У�ֻҪ���ҵ�һ��F(j)Ϊtrue�����Ҵ�j + 1��i֮����ַ����ڴʵ� ���ҵ�����F(i)Ϊtrue
//��ʼֵ : ���ڳ�ʼֵ�޷�ȷ���ģ���������һ��������ʵ������Ŀ�״̬����Ϊ״̬����ʼ ��״̬��ֵ��Ҫ��֤״̬���ƿ�����ȷ��˳���Ľ��У�����ȡʲôֵ����ͨ���� �����ӽ�����֤
//F(0) = true
//���ؽ�� : F(n)

//class Solution {
//public:
//	bool wordBreak(string s, unordered_set<string> &dict) {
//		if (s.empty())
//			return false;
//		if (dict.empty())
//			return false;
//		int len = s.size();
//		vector<bool> v(len + 1, false);
//		v[0] = true;
//		for (int i = 1; i <= len; i++)
//		{
//			for (int j = i - 1; j >= 0; j--)
//			{
//				if (v[j] && dict.find(s.substr(j, i - j)) != dict.end())
//				{
//					v[i] = true;
//					break;
//				}
//			}
//		}
//		return v[len];
//	}
//};


//��̬�滮���Ǿ���
/*����:��̬�滮 ״̬ :
��״̬ : ��(0, 0)��(1, 0), (1, 1), (2, 0), ...(n, n)�����·����
F(i, j) : ��(0, 0)��(i, j)�����·���� ״̬���� :
F(i, j) = min(F(i - 1, j - 1), F(i - 1, j)) + triangle[i][j]
��ʼֵ :
	F(0, 0) = triangle[0][0]
���ؽ�� :
	min(F(n - 1, i))
*/
//class Solution {
//public:
//	int minimumTotal(vector<vector<int> > &triangle) {
//		if (triangle.empty())
//			return 0;
//		vector<vector<int>> Fv(triangle);
//		int row = triangle.size();
//		for (int i = 1; i < row; ++i)
//		{
//			for (int j = 0; j <= i; ++j)
//			{
//				if (j == 0)
//					Fv[i][j] = Fv[i - 1][j];
//				else if (j == i)
//					Fv[i][j] = Fv[i - 1][j - 1];
//				else
//					Fv[i][j] = min(Fv[i - 1][j - 1], Fv[i - 1][j]);
//
//				Fv[i][j] += triangle[i][j];
//			}
//		}
//		int result = Fv[row - 1][0];
//		// min(F(n-1, i))
//		for (int i = 1; i < row; i++){
//			result = min(Fv[row - 1][i], result);
//		}
//		return result;
//	}
//};


//��̬�滮·������
/*����:��̬�滮 ״̬ :
��״̬ : ��(0, 0)����(1, 0), (1, 1), (2, 1), ...(m - 1, n - 1)��·����
F(i, j) : ��(0, 0)����F(i, j)��·���� ״̬���� :
F(i, j) = F(i - 1, j) + F(i, j - 1)
��ʼ�� : ������� : ��0�к͵�0�� F(0, i) = 1
		F(i, 0) = 1
���ؽ�� :
		F(m - 1, n - 1)
*/

//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        if(m < 1 || n < 1)
//            return 0;
//        vector<vector<int>> Fv(m,vector<int>(n,1));
//        
//        for(int i = 1;i < m;i++)
//        {
//            for(int j = 1;j < n;j++)
//            {
//                Fv[i][j] = Fv[i - 1][j] + Fv[i][j - 1];
//            }
//        }
//        return Fv[m - 1][n - 1];
//    }
//};

