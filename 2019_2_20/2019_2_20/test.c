#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//int ADD(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 3;
//	int b = 4;
//	int c = ADD(a, b);
//	return 0;
//}


//int main(void)
//{
//	char num;
//	for (num = 0; num < 255;)
//		num += num;
//	printf("%d\n", num);
//	return 0;
//}



//void func(int *p)
//{
//	static int num = 4;
//	p = &num;
//	(*p)--;
//}
//int main()
//{
//	int i = 5;
//	int *p = &i;
//	func(p);
//	printf("%d", *p);
//	return 0;
//}


//int main()
//{
//	char s1[] = "12345", *s2 = "1234";
//	printf("%d\n", strlen(strcpy(s1, s2)));
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	FILE * fp;
//	int i, a[6] = { 1, 2, 3, 4, 5, 6 }, k;
//	fp = fopen("data.dat", "w+");
//	for (i = 0; i<6; i++)
//	{
//		fseek(fp, 0L, 0);
//		fprintf(fp, "%d\n", a[i]);
//		rewind(fp);
//		fscanf(fp, "%d", &k);
//	}
//	fclose(fp);
//	printf("%d\n", k);


int main()
{
	//3 = 2 = 1 = 0;
	//[3, 2, 1, 0];
	//(3, 2, 1, 0);
	3 / 2 / 1 / 0;

	return 0;
}