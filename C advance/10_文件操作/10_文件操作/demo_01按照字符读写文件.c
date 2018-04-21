/*
文件名称：按照字符读取文件
作    者：lqa
编辑日期：20180125
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main01_fputc()
{
	FILE* fp = NULL;
	char* filename = "F:/2.txt";//统一使用45度的书写方式，在Linux和Windows下通用
	char a[27] = "abcdefghijklmn";
	fp = fopen(filename, "r+");

	if (fp == NULL)//打开文件失败
	{
		printf("func fopen() err\n");
		return -1;
	}
	printf("打开成功\n");
	for (int i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);//按照字符读取文件
	}
	fclose(fp);
	return 0;
}

int main02_fgetc()
{
	FILE* fp = NULL;
	char* filename = "F:/2.txt";//统一使用45度的书写方式，在Linux和Windows下通用
	char a[27] = "abcdefghijklmn";

	/*
	#include <stdio.h>
	FILE *fopen( const char *fname, const char *mode );
	fopen()函数打开由fname(文件名)指定的文件, 并返回一个关联该文件的流.
	如果发生错误, fopen()返回NULL. mode(方式)是用于决定文件的用途(例如 用于输入,输出,等等)
	*/

	fp = fopen(filename, "r+");

	if (fp == NULL)//打开文件失败
	{
		printf("func fopen() err\n");
		return -1;
	}
	printf("打开成功\n");

	/*
	函数feof()在到达给出的文件流的文件尾时返回一个非零值
	*/
	while (!feof(fp))//判断文件是否接收
	{
		/*
		fgetc()函数返回来自stream(流)中的下一个字符,
		如果到达文件尾或者发生错误时返回EOF.
		*/
		char tempc = fgetc(fp);
		printf("%c", tempc);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
	return 0;
}

int main03()
{
	main01_fputc();
	main02_fgetc();

	system("pause");
	return 0;
}