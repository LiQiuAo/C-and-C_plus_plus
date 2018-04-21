/*
文件名称：堆栈的理解
作    者：LQA
时    间：2018年1月14日
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
一般认为：栈开口向下
*/
int main5()
{
	int a;
	int b;
	printf("&a:%d, &b:%d\n", &a, &b);

	int *c;
	int *d;
	c = (int *)malloc(sizeof(int)*10);//分配10个int类型的内存空间
	d = (int *)malloc(sizeof(int)*10);
	printf("c:%d, d:%d\n", c, d);

	system("pause");
	return 0;
}
/*
测试结果可以发现：
栈：b的地址是小于a的地址，这说明了栈的开口方向是向下的
堆：d的地址是大于c的地址，这说明堆的开口方向是向上的
*/