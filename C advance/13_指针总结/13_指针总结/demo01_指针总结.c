/*
�ļ����ƣ�ָ���ܽ�
��    �ߣ�lqa
�༭ʱ�䣺20180203
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getContentLen01(const char* filename, char** buf, int* len)
{
	int ret = 0;
	char* tmp = NULL;
	tmp = (char*)malloc(sizeof(char) * 100);
	if (tmp == NULL)
	{
		ret = -1;
		return ret;
	}
	strcpy(tmp, "aaaaabbbbb");
	*len = 10;
	*buf = tmp;//��Ӹ�ֵ

	return ret;
}

int getContentLen02(const char* filename, char* buf, int* len)
{
	int ret = 0;
	char* tmp = NULL;
	tmp = (char*)malloc(sizeof(char) * 100);
	if (tmp == NULL)
	{
		ret = -1;
		return ret;
	}
	if (buf == NULL)
	{
		*len = 10;//��һ�ε����󳤶�
	}
	else
	{
		strncpy(tmp, "aaaaaaaaaaaaaaaaa", 10);
		*len = 10;
	}
	*buf = tmp;//��Ӹ�ֵ

	return ret;
}

int main01()
{
	int ret = 0;
	const char* filename = "f:/1.txt";
	char* p = NULL;
	int len = 0;

	getContentLen01(filename, &p, &len);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	//��һ�ε��ú������󳤶ȣ����ݳ��ȷ����ڴ�
	ret = getContentLen02(filename, NULL, &len);
	if ( ret == 0 )
	{//�ͷ���Դ
		return ret;
	}

	p = (char* )malloc(len);
	if ( p == NULL )
	{
		return;
	}

	//�ڶ��ε���
	getContentLen02(filename, p, &len);
	if ( p != NULL )
	{
		free(p);
		p = NULL;
	}
	  
	system("pause");
	return 0;
}