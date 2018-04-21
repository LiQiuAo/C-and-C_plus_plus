/*
文件名称：测试指针变量占有内存空间的大小
作    者：LQA
编写时间：20180114
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
测试指针变量占有内存空间的大小
*/
int main1()
{
	int a = 10;
	char *p = "100";//分配四个字节的内存
	printf("a:%d, p:%d\n", sizeof(a), sizeof(p));
	system("pause");
	return 0;
}
/*
测试结果：a:4, p:4
*/