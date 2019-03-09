#define _CRT_SECURE_NO_WARNINGS

///*字符串反序*/
#include<stdio.h>

//int main()
//{
//	void revStr(char *);
//	char str[80];
//	printf("输入一个字符串: ");
//	gets(str);
//	revStr(str);
//	printf("转置后的字符串: %s\n", str);
//	return 0;
//}
//void revStr(char *str)
//{
//	int i, len;
//	char tmp;
//	for (len = 0; str[len]; len++);
//	for (i = 0; i<len / 2; i++)
//	{
//		tmp = str[len - i - 1];
//		str[len - i - 1] = str[i];
//		str[i] = tmp;
//	}
//}



//int main()
//{
//	int a[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 11, 12, 13, 14 }, { 15, 16, 17, 18 } };
//	int i = 0, j = 0, s = 0;
//	while (i++<4)
//	{
//		if (i == 2 || i == 4) continue;
//		j = 0;
//		do{ s += a[i][j]; j++; } while (j<4);
//	}
//	printf("%d\n", s);
//
//	return 0;
//}


//#include <stdio.h> 
//main()
//{
//	int a[3][4] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23 }, (*p)[4] = a, i, j, k = 0;
//	for (i = 0; i < 3; i++)
//	for (j = 0; j < 2; j++)
//		k = k + *(*(p + i) + j);
//	printf("%d", k);
//}


#include<stdio.h>

int main(){

	int x;
	float y;
	scanf("%3d%f", &x, &y);
	return 0;
}




