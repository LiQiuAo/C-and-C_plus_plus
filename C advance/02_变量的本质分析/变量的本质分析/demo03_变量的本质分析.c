/*
文件名称：数据类型的分析
作    者：LQA
时    间：2018年1月13日
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main1()
{
	/*
	直接赋值
	*/
    int a; 
	printf("&a:%d \n", &a);
	a = 10;
	printf("&a:%d \n", &a);

	/*
	间接赋值
	由于a是局部变量，局部变量的地址对应的是栈区内存。
	当调用的函数结束后，这个局部变量的内存占用被释放，也就是出栈。
	这块内存之后可能会被申请走，用于存放其他的数据，
	然后可能会继续释放，然后再存放其他数据。
	*/
	*((int *)&a) = 200;
	
	printf("a:%d \n", a);
	system("pause");
	return 0;
}
/*  
&a:4128124
&a:4128124
a:200
请按任意键继续. . .
*/
