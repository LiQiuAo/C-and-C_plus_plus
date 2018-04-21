/*
文件名称:结构体的高级话题-偏移量
作    者：lqa
编辑时间：20180125
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
一旦结构体定义下来，则结构体中的成员 内存布局 就定下来了
可以通过age地址去 求 大的结构体内存地址
*/
typedef struct AdvTeacher
{
	char name[64];
	int age;
	int p;
	char* pname2;
}AdvTeacher;

void main07()
{
	AdvTeacher t1;
	AdvTeacher *p = NULL;

	{
		int offsize = (int)&(p->age);
		printf("%d\n", offsize);//求得的是相对偏移量
	}


	system("pause");
}

/*
测试结果：
64
请按任意键继续. . .
*/

void main08()
{
	AdvTeacher t1;
	AdvTeacher *p = NULL;
	p = &t1;
	p = p + 100;

	{
		//int offsize1 = (int)&(p->age) - (int)p;
		int offsize1 = (int)&(p->age);//表示的是&(t1.age)
		int offsize2 = (int )&(((AdvTeacher*)0)->age); 
		printf("offsize1 = %d\n", offsize1);//求得的是相对偏移量
		printf("offsize2 = %d\n", offsize2);
	}

	system("pause");
}

/*
测试结果：
64
请按任意键继续. . .
*/