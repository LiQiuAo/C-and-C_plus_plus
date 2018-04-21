/*
文件名称：const修饰参数的示例
作    者：lqa
编辑时间：20180117
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
所指向的内存数据不能被修改，但是本身可以修改
*/
void getmem(const char *p)
{
	p = 1;
	//p[1] = '3';//指针所指向的内存空间是常量，不能被修改
	return;
}

/*
指针变量不能被修改，但是它所指向内存空间可以被修改
*/
void getmem2(char *const p)
{
	//p = 1;//指针变量是常量，不能被修改
	p[1] = '3';//指针所指向的内存空间是常量，不能被修改
	return;
}

/*
指针和它所指向的内存空间，均不能被修改
*/
void getmem3(const char *const p)
{
	//p = 1;
	//p[1] = '3';//指针所指向的内存空间是常量，不能被修改
	
	printf("%c ", p[1]);
	return;
}

int main01()
{
	char *p1 = NULL;
	const char *p2 = NULL;
	
	p2 = 1;
	system("pause");
	return 0;
} 

int main()
{
	/*
	结论：C语言中的const修饰的变量是假的，C语言中的const是一个冒牌货
	*/
	const int p = 10;
	//p = 100;

	{
		int *a = &p;
		*a = 100;
		printf("a:%d\n", p);
	}
	system("pause");
	return 0;
	/*
	a:100
    请按任意键继续. . .
	*/
}