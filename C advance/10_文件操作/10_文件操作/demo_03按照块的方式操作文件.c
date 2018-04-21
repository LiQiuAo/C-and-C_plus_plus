/*
�ļ����ƣ����տ�ķ�ʽ����д�ļ�
��    �ߣ�lqa
�༭���ڣ�20180126
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
ֱ�Ӱ��ڴ�����д�뵽�ļ���
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
		sprintf()������printf()����, ֻ�ǰ�������͵�buffer(������)��.����ֵ��д����ַ�����
		*/
		sprintf(tArray[i].name, "%d%d%d", i + 1, i + 1, i + 1);
		tArray[i].age = i + 31;
	}
	fp = fopen(fileName, "wb");
	if ( fp == NULL )
	{
		printf("�����ļ�ʧ��\n");
		return;
	}

	for ( int i = 0; i < 3; i++ )
	{
		/*
		#include <stdio.h>
		int fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
		fwrite()����������buffer(������)��, дcount����СΪsize(��С)�Ķ���stream(��)ָ������. ����ֵ����д�Ķ��������.
		*/
		myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);
	}

	if ( fp != NULL )
	{
		fclose(fp);
	}
}

/*
���ļ�
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
		printf("�����ļ�ʧ��\n");
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		/*
		#include <stdio.h>
		int fread( void *buffer, size_t size, size_t num, FILE *stream );
		����fread()��ȡ[num]������(ÿ�������СΪsize(��С)ָ�����ֽ���),
		���������滻����buffer(������)ָ��������. �������Ը�����������. �����ķ���ֵ�Ƕ�ȡ����������
		*/
		myN = fread(&tArray[i], sizeof(Teacher), 1, fp);

		/*
		#include <stdio.h>
		int fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
		fwrite()����������buffer(������)��, дcount����СΪsize(��С)�Ķ���stream(��)ָ������. ����ֵ����д�Ķ��������.
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