#define _CRT_SECURE_NO_WARNINGS
//쳲���������
//��̬�滮 ״̬ : F(n)
//״̬���� : F(n) = F(n - 1) + F(n - 2) 
//��ʼֵ : F(1) = F(2) = 1 
//���ؽ�� : F(N)

//class Solution {
//public:
//	int Fibonacci(int n) {
//		if (n <= 0)
//			return 0;
//		if (n == 1 || n == 2)
//			return 1;
//		int fn, f1, f2;
//		f1 = f2 = 1;
//		for (int i = 3; i <= n; i++)
//		{
//			fn = f1 + f2;
//			f2 = f1;
//			f1 = fn;
//		}
//		return fn;
//	}
//};


//��̬��̨��
//״̬: ��״̬ : ����1����2����3����...��n��̨�׵������� f(n) : ��ʣn��̨�׵�������
//״̬���� : n��̨�ף���һ����n������ : ��1������2��������n�� ��1����ʣ��n - 1������ʣ��������f(n - 1) ��2����ʣ��n - 2������ʣ��������f(n - 2)
//	   f(n) = f(n - 1) + f(n - 2) + ... + f(n - n)
//	   f(n) = f(n - 1) + f(n - 2) + ... + f(0)
//	   f(n - 1) = f(n - 2) + ... + f(0)
//	   f(n) = 2 * f(n - 1)
//��ʼֵ :
//	   f(1) = 1
//	   f(2) = 2 * f(1) = 2 f(3) = 2 * f(2) = 4 f(4) = 2 * f(3) = 8
//��������һ���ȱ����� f(n) = 2 ^ (n - 1)
//   ���ؽ�� : f(N)



//class Solution {
//public:
//	int jumpFloorII(int number) {
//		if (number == 0)
//			return 0;
//		if (number == 1)
//			return 1;
//		return 2 * jumpFloorII(number - 1);
//	}
//};



//���󸲸�����
//״̬F[i]:��i��2*1��С�������ص�����һ��2*i�Ĵ���εķ�����
//F[i]:F[i - 1] + F[i - 2]
//����ֵ��F[n]

//class Solution {
//public:
//	int rectCover(int number) {
//		if (number <= 0)
//			return 0;
//		if (number == 1 || number == 2)
//			return number;
//		int fn, f1, f2;
//		f1 = 2; f2 = 1;
//		for (int i = 3; i <= number; i++)
//		{
//			fn = f1 + f2;
//			f2 = f1;
//			f1 = fn;
//		}
//		return fn;
//	}
//};

//������������к�
//����:��̬�滮 
//״̬ :
//��״̬ : ����Ϊ1��2��3��..., n��������͵����ֵ F(i) : ����Ϊi��������͵����ֵ�����ֶ��岻���γɵ��ƹ�ϵ������ F(i) : ��array[i]ΪĩβԪ�ص�������͵����ֵ
//״̬���� :
//F(i) = max(F(i - 1) + array[i]��array[i])
//F(i) = (F(i - 1) > 0) ? F(i - 1) + array[i] : array[i]
//��ʼֵ : F(0) = array[0] 
//���ؽ�� :maxsum : ����F(i)�е����ֵ

//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		if (array.empty())
//			return 0;
//		int value = array[0];
//		int maxvalue = array[0];
//		for (size_t i = 1; i < array.size(); i++)
//		{
//			value = max(value + array[i], array[i]);
//			maxvalue = max(value, maxvalue);
//		}
//		return maxvalue;
//	}
//};

//�ַ����и�word-break

