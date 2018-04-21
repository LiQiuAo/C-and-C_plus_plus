/*
文件名称：项目开发字符串模型
作    者：lqa
编辑时间：20180115
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
#include <string.h>
char *strstr( const char *str1, const char *str2 );
函数返回一个指针，它指向字符串str2 首次出现于字符串str1中的位置，
如果没有找到，返回NULL
*/

/*
do...while()模型
*/
int main7()
{
	int ncount = 0;
	//初始化
	char *p = "11abcd123121abcd12312abcd";

	do
	{
		p = strstr(p, "abcd");
		if ( p != NULL )
		{
			ncount++;
			p = p + strlen("abcd");//指针达到下次查找的条件
		}
		else
		{
			break;
		}
	} while ( *p != '\0' );

	printf("ncount:%d\n", ncount);
	system("pause");
	return 0;
	/*
	ncount:3
	请按任意键继续. .
	*/
}

/*
while模型
*/
int main8()
{
	int ncount = 0;
	char *p = "11abcd123121abcd12312abcd";
	while ( p = strstr(p, "abcd") )
	{
		ncount++;
		p = p + strlen("abcd");
		if ( *p == '\0' )
		{
			break;
		}
	}

	printf("ncount:%d\n", ncount);
	system("pause");
	return 0;
}

/*
char *p = "11abcd123121abcd12312abcd";
求字符串p中abcd出现的次数
1、自定义函数接口，完成上述需求
2、自定义业务函数和main函数必须分开
*/
int getCount(char *mystr, char *substr, int *count)
{
	int ret = 0;
	int tmpCount = 0;
	char *p = mystr;//不要轻易改变形参的值

	/*
	应该考虑到程序的健壮性
	*/
	if (mystr == NULL || substr == NULL || count == NULL)
	{
		ret = -1;
		printf("func getCount err:%d ( mystr == NULL || substr == NULL || count == NULL )\n", ret);
		return ret;
	}
	do
	{
		p = strstr(p, substr);
		if (p != NULL)
		{
			tmpCount++;
			p = p + strlen("abcd");//指针达到下次查找的条件
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*count = tmpCount;//间接赋值是指针存在的最大意义
	return ret;
}

int main9()
{
	int count = 0;
	int ret;
	char *p = "11abcd123121abcd12312abcd";
	char sub[] = "abcd";

	ret = getCount(p, sub, &count);
	if ( ret != 0 )
	{
		printf("getCount() err:%d", ret);
		return ret;
	}
	printf("count: %d\n", count);
	system("pause");
	return ret;
}