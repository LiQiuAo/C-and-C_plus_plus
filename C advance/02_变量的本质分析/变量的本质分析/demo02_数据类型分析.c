/*
文件名称：数据类型的分析
作    者：LQA
时    间：2018年1月12日
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

/*
如何给数据类型起一个别名？
*/
struct Teacher
{
	char name[64];
	int age;
}Teacher;

/*
利用typedef来对数据类型取别名
*/
typedef struct Teacher2
{
	char name[64];
	int age;
}Teacher2;


void main2()
{
	/*
	要站在编译器的角度看问题；
	*/
	int a;//告诉c编译器分配四个字节的内存
	int b[10];//告诉c编译器分配40个自己内存

	printf("b:%d, b+1:%d, &b:%d, &b+1:%d \n", b, b+1, &b, &b+1);
	printf("sizeof(b):%d\n", sizeof(b));
	printf("sizeof(a):%d\n", sizeof(a));

	struct Teacher t1;
	Teacher2 t2;

	{
		//void c;//编译器不知道如何分配内存，不能这样使用
	}

	system("pause");
}
/*
b:15727484, b+1:15727488
&b:15727484, &b+1:15727524
sizeof(b):40
sizeof(a):4

b代表的数组首元素的地址
&b代表的是整个数组的地址
*/
