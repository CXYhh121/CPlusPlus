#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<inttypes.h>
#include <stdlib.h>
//void main()
//{
//	FILE *fp; int i = 20, j = 30, k, n;
//	fp = fopen("d1.dat","w"); 
//		fprintf(fp, "%d\n", i); fprintf(fp, "%d\n", j);
//	fclose(fp);
//	fp = fopen("d1.dat", "r");
//	fscanf(fp, "%d%d", &k, &n); printf("%d,%d\n", k, n);
//	fclose(fp);
//}


//Çó×Ö·û´®³¤¶È
//int fun(char *s)
//{
//	char *p = s;
//	while (*p++);
//	return p - s - 1;
//}
//int main()
//{
//	char s[] = "abcdef";
//	int ret = fun(s);
//	printf("%d\n", ret);
//	return 0;
//}

//int main()
//{
//	int k = -8567; 
//	printf("|%06d|\n", k);
//	return 0;
//}


//struct st_task
//{
//	uint16_t id;
//	uint32_t value;
//	uint64_t timestamp;
//};
//
//void fool()
//{
//	struct st_task task;
//	uint64_t a = 0x00010001;
//	memcpy(&task, &a, sizeof(uint64_t));
//	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
//}
//
//int main()
//{
//	fool();
//	return 0;
//}