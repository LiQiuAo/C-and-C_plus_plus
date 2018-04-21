/*
文件名称：内存四区中的栈区和全局区的理解
作    者：LQA
时    间：2018年1月12日
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

char *getStr1()
{
	char *p1 = "abcdefg2";//相对于将字符数组中a的首地址赋值给p1
	return p1;
}

char *getStr2()
{
	char *p2 = "abcdefg2";
	return p2;
}

int main()
{
	char *p1 = NULL;
	char *p2 = NULL;
	p1 = getStr1();
	p2 = getStr2();

	//打印p1 p2所指向内存空间的数据
	printf("p1:%s, p2:%s \n", p1, p2);

	//打印p1 p2的值
	printf("p1:%d, p2:%d \n", p1, p2);

	system("pause");
	return 0;
}
/*
测试结果：
p1:abcdefg2, p2:abcdefg2
p1:1665940, p2:1665940
*/