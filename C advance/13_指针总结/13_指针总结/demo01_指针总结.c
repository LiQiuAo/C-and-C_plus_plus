/*
文件名称：指针总结
作    者：lqa
编辑时间：20180203
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
	*buf = tmp;//间接赋值

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
		*len = 10;//第一次调用求长度
	}
	else
	{
		strncpy(tmp, "aaaaaaaaaaaaaaaaa", 10);
		*len = 10;
	}
	*buf = tmp;//间接赋值

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

	//第一次调用函数来求长度；根据长度分配内存
	ret = getContentLen02(filename, NULL, &len);
	if ( ret == 0 )
	{//释放资源
		return ret;
	}

	p = (char* )malloc(len);
	if ( p == NULL )
	{
		return;
	}

	//第二次调用
	getContentLen02(filename, p, &len);
	if ( p != NULL )
	{
		free(p);
		p = NULL;
	}
	  
	system("pause");
	return 0;
}