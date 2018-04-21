/*
文件名称：堆栈区的理解
作    者：LQA
时    间：2018年1月14日
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

/*  
堆
*/
char *getMem(int num)
{
	char *p1 = NULL;
	p1 = (char *)malloc(sizeof(char) * num);
	if ( p1 == NULL )
	{
		return NULL;
	}
	return p1;
}

/*
栈
注意：return不是把内存块64个字节给return出来，而是把内存块的首地址(内存的标号0xaa11),返回给tmp 
*/
char *getMem2()
{
	char buf[64];//临时变量 栈区存放
	strcpy(buf, "123456");
	return buf;
}


int main4()
{
	char *tmp = NULL;
	tmp = getMem(10);
	if ( tmp == NULL )
	{
		return;
	}
	strcpy(tmp, "111222");//向tmp做指向的内存空间中copy数据

	tmp = getMem2();
	printf("tmp = %d\n", tmp);
	system("pause");
	return 0;
}