#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

//反转字符串I
string reverseString(string s) {
	size_t begin = 0;
	size_t end = s.size() - 1;
	if (s.empty() == 1)
		return s;

	while (begin < end)
	{
		swap(s[begin], s[end]);
		++begin;
		--end;
	}
	return s;
}

//反转字符串II
string reverseStr(string s, int k)
{
	int count = s.size() / k;
	for (size_t i = 0; i <= count; i++)
	{
		if (i % 2 == 0)
		{
			if (i*k + k < s.size())
				reverse(s.begin() + i*k, s.begin() + i*k + k);
			else
				reverse(s.begin() + i*k, s.end());
		}
	}
	return s;
}

int main()
{

	string s1("abcdefgh");
	cout << reverseStr(s1, 2) << endl;
	
	return 0;
}

//反转字符串III
string reverseString(string s) {
	size_t begin = 0;
	size_t end = s.size() - 1;
	if (s.empty() == 1)
		return s;

	while (begin < end)
	{
		swap(s[begin], s[end]);
		++begin;
		--end;
	}
	return s;
}
//找出字符串中第一个只出现一次的字符
int firstUniqChar(string s) {
	//定义一个数组统计每个字符出现的个数
	int countchar[26] = { 0 };
	size_t size = s.size();

	//遍历一遍字符串，统计每个字符出现的个数
	for (size_t i = 0; i < size; ++i)
	{
		countchar[s[i] - 'a']++;//在计数数组的对应位置计数
	}

	//再遍历一遍字符串，看哪个字符是第一次只出现一次的,返回下标。
	for (size_t i = 0; i < size; ++i)
	{
		if (countchar[s[i] - 'a'] == 1)
			return i;
	}

	return -1;

}

//验证回文串
bool IsNumber(char c)
{
	if (c >= '0' && c <= '9'
		|| c >= 'a' && c <= 'z'
		|| c >= 'A' && c <= 'Z')
		return true;
	return false;
}
bool isPalindrome(string s) {
	if (s.empty() != 0)
		return true;
	int begin = 0;
	int end = s.size() - 1;
	 char* p = (char*)s.c_str();
	while (begin<end)
	{
		//从前往后找，找符合条件的字符
		while (begin != end)
		{
			if (IsNumber(s[begin]))
				break;
			begin++;
		}
		//从后往前找，找符合条件的字符
		while (begin<end)
		{
			if (IsNumber(s[end]))
				break;
			end--;
		}
		if (begin<end)
		{
			if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
				return false;
			begin++;
			end--;
		}
	}
	return true;
}


//两个字符串相加
string addStrings(string num1, string num2) {
	int index1 = num1.size() - 1;
	int index2 = num2.size() - 1;
	int next = 0;
	string retstr;
	while (index1 >= 0 || index2 >= 0)
	{
		int val1 = 0;
		int val2 = 0;
		if (index1 >= 0)
		{
			//把每个数字从ASCII码值转换为普通数字
			val1 = num1[index1] - '0';
			--index1;
		}
		if (index2 >= 0)
		{
			val2 = num2[index2] - '0';
			--index2;
		}
		int addret = val1 + val2 + next;
		if (addret>9)
		{
			addret = addret % 10;
			next = 1;
		}
		else
			next = 0;
		//retstr=addret+'0';若这样写，retstr最后只是最后一个字符；
		retstr += (addret + '0');
	}

	if (next == 1)
		retstr += '1';
	reverse(retstr.begin(), retstr.end());
	return retstr;
}

//两个字符串相乘
string multiply(string num1, string num2) {
	string retstr = "0";
	if (num1 == "0" || num2 == "0")
		return retstr;
	int index1 = num1.size() - 1;

	int place1 = 0;
	while (index1 >= 0)
	{
		int val1 = num1[index1] - '0';
		string sum = "0";
		int place2 = 0;
		int index2 = num2.size() - 1;
		while (index2 >= 0)
		{
			int val2 = num2[index2] - '0';
			int num;
			num = val1*val2;
			string ch;
			int rem = num % 10;
			int next = num / 10;
			if (next != 0)
			{
				ch += (next + '0');
				ch += (rem + '0');
			}
			else
			if (rem != 0)
				ch += (rem + '0');
			int i = 0;
			if (next != 0 || rem != 0)
			{
				while (i<place2)
				{
					ch += '0';
					++i;
				}
			}
			 sum = addStrings(sum, ch);
			index2--;
			place2++;
		}
		int i = 0;
		while (i<place1)
		{
			sum += '0';
			++i;
		}
		retstr = addStrings(sum, retstr);
		index1--;
		place1++;
	}
	return retstr;
}


