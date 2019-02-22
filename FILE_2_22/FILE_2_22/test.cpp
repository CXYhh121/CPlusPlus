#define _CRT_SECURE_NO_WARNINGS

/* fopen example */
//#include <stdio.h>
//int main()
//{
//	FILE * pFile;
//	pFile = fopen("myfile.txt", "w");
//	if (pFile != NULL)
//	{
//		fputs("fopen example", pFile);
//		fclose(pFile);
//	}
//	return 0;
//}

///* fclose example */
//#include <stdio.h>
//int main()
//{
//	FILE * pFile;
//	pFile = fopen("myfile.txt", "wt");
//	fprintf(pFile, "fclose example");
//	int ret = fclose(pFile);
//	printf("%d\n", ret);
//	return 0;
//}


///* fputs example */
//#include <stdio.h>
//
//int main()
//{
//	FILE * pFile;
//	char sentence[256];
//
//	printf("Enter sentence to append: ");
//	fgets(sentence, 256, stdin);
//	pFile = fopen("mylog.txt", "a");
//	fputs(sentence, pFile);
//	fclose(pFile);
//	return 0;
//}

/* fseek example */
#include <stdio.h>

int main()
{
	FILE * pFile;
	pFile = fopen("example.txt", "wb");
	fputs("This is an apple.", pFile);
	fseek(pFile, 9, SEEK_SET);
	fputs(" sam", pFile);
	fclose(pFile);
	return 0;
}
