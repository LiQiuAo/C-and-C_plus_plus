/*
文件名称：当释放指针后要注意的问题，避免也指针
作    者：LQA
编写时间：20180114
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
野指针产生的原因：
指针变量和它所指向的内存空间变量是两个不同的概念
释放了指针所指的内存空间，但是指针变量本身没有重置成null；
造成释放的时候，通过if(p1 != null)而报错

解决方法：1）定义指针的时候初始化为null 2）释放指针所指向的内存空间后，把指针重置为null
*/
int main2()
{
	char *p1 = NULL;
	p1 = (char *)malloc(100);
	if ( p1 == NULL )
	{
		return;
	}
	strcpy(p1, "12121212");
	printf("p1:%s \n", p1);

	if ( p1 != NULL )
	{
		free(p1);
		p1 = NULL;//在释放后务必要赋值为null，否则会产生野指针。导致释放不够彻底
	}

	if ( p1 != NULL )
	{
		free(p1);
	}
	system("pause");
	return 0;
}
