/*
文件名称：按照块的方式来读写文件
作    者：lqa
编辑日期：20180126
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Teacher
{
	char name[64];
	int age;
}Teacher;

/*
直接把内存数据写入到文件中
*/
void main_fwrite()
{
	int myN = 0;
	FILE* fp = NULL;
	char* fileName = "f:/3.data";
	Teacher tArray[3];

	for ( int i = 0; i < 3; i++ )
	{
		/*
		sprintf()函数和printf()类似, 只是把输出发送到buffer(缓冲区)中.返回值是写入的字符数量
		*/
		sprintf(tArray[i].name, "%d%d%d", i + 1, i + 1, i + 1);
		tArray[i].age = i + 31;
	}
	fp = fopen(fileName, "wb");
	if ( fp == NULL )
	{
		printf("建立文件失败\n");
		return;
	}

	for ( int i = 0; i < 3; i++ )
	{
		/*
		#include <stdio.h>
		int fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
		fwrite()函数从数组buffer(缓冲区)中, 写count个大小为size(大小)的对象到stream(流)指定的流. 返回值是已写的对象的数量.
		*/
		myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);
	}

	if ( fp != NULL )
	{
		fclose(fp);
	}
}

/*
读文件
*/
void main_fread()
{
	int myN = 0;
	FILE* fp = NULL;
	char* fileName = "f:/3.data";
	Teacher tArray[3];

	fp = fopen(fileName, "rb");
	if (fp == NULL)
	{
		printf("建立文件失败\n");
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		/*
		#include <stdio.h>
		int fread( void *buffer, size_t size, size_t num, FILE *stream );
		函数fread()读取[num]个对象(每个对象大小为size(大小)指定的字节数),
		并把它们替换到由buffer(缓冲区)指定的数组. 数据来自给出的输入流. 函数的返回值是读取的内容数量
		*/
		myN = fread(&tArray[i], sizeof(Teacher), 1, fp);

		/*
		#include <stdio.h>
		int fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
		fwrite()函数从数组buffer(缓冲区)中, 写count个大小为size(大小)的对象到stream(流)指定的流. 返回值是已写的对象的数量.
		*/
		//myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("name:%s, age:%d\n", tArray[i].name, tArray[i].age);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}
void main()
{
	//main_fwrite();
	main_fread();
	system("pause");
}