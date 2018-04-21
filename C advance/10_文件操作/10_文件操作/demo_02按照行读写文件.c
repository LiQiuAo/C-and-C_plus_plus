/*
文件名称：按照行读写文件
作    者：lqa
编辑日期：20180125
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main11_fputc()
{
	FILE* fp = NULL;
	char* filename = "F:/22.txt";//统一使用45度的书写方式，在Linux和Windows下通用
	char a[27] = "abcdefghijklmn";
	//fp = fopen(filename, "r+");//以读/写方式打开一个已存在的文件
	fp = fopen(filename, "w+");//以读/写方式建立一个新的文本文件

	if (fp == NULL)//打开文件失败
	{
		printf("func fopen() err\n");
		return -1;
	}
	printf("打开成功\n");
	
	/*
	#include <stdio.h>
	int fputs( const char *str, FILE *stream );
	fputs()函数把str(字符串)指向的字符写到给出的输出流. 
	成功时返回非负值, 失败时返回EOF
	*/
	fputs(a, fp);

	fclose(fp);
	return 0;
}

int main12_fgetcs()
{
	FILE* fp = NULL;
	char* filename = "F:/22.txt";//统一使用45度的书写方式，在Linux和Windows下通用
	char buf[1024];
	fp = fopen(filename, "r+");

	if ( fp == NULL )//打开文件失败
	{
		printf("func fopen() err\n");
		return -1;
	}
	printf("打开成功\n");

	while ( !feof(fp) )//判断文件是否接收
	{
		/*
		1、C函数库 会 一行一行的拷贝数据 到buf所指的内存空间中 并且会变成C风格的字符串
		2、把\n也copy到我们的buf中
		3、内存打包（把内存首地址 + 内存的长度）
		*/
		char* p = fgets(buf, 1024, fp);
		if ( p == NULL )
		{
			goto END;
		}
		printf("%s", buf);
	}
	END:
	if (fp != NULL)
	{
		fclose(fp);
	}
	return 0;
}

int main13()
{
	//main11_fputc();
	main12_fgetcs();

	system("pause");
	return 0;
}
