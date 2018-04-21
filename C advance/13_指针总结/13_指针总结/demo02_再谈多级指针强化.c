/*
文件名称：多级指针的强化
作    者：lqa
编辑时间：20180203
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int getMem01(char*** p) 
{
	*p = 30;
}

int main01()
{
	char** p = NULL;
	char*** p2 = NULL;

	p2 = &p;
	getMem(p2);
	{
		*p2 = 10;//直接修改二级指针的值
	}

	return 0;
}

int getMem02(char******** p2)
{
	*p2 = 10;//直接修改二级指针的值
}

int main()
{
	char******* p = NULL;
	char******** p2 = NULL;

	p = 1;//直接修改
	p2 = &p;
	getMem02(p2);//间接修改,*是p的地址，所以间接的修改了p的值

	system("pause"); 
	return 0;
}