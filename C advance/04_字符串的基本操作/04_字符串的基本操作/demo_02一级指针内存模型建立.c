/*
文件名称：一级指针内存模型建立
作    者：lqa
编辑时间：20180115
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main4()
{
	char buf[20] = "aaaa";
	char buf2[] = "bbbb";
	char *p1 = "1111";
	char *p2 = malloc(100);

	strcpy(p2, "2222");
	printf("%s\n", p1);
	system("pause");
	return;
}