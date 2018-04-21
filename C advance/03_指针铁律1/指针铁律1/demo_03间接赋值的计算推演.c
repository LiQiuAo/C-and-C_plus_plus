/*
文件名称：间接赋值的计算推演
作    者：LQA
编写时间：20180114
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int getFileLen(int *p)
{
	*p = 40;//p的值是a的地址，*a间接修改a的值
}

//return只能返回一个结果
int getFileLen2()
{
	int a = 100;
	return a;
}

int getFileLen3(int b)
{
	b = 100;
}


int main3()
{
	int a = 10;
	int *p = NULL;

	//修改a的值
	a = 20;//直接修改
	p = &a;
	*p = 30;//p是a得地址

	printf("a:%d\n", a);

	getFileLen(&a);
	printf("getFileLen后:%d\n", a);
	
	getFileLen3(a);
	printf("getFileLen3后:%d\n", a);

	system("pause");
	return 0;
}

