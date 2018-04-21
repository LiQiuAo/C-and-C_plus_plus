/*
文件名称:两头堵模型
作    者：LQA
编辑时间：20180116
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*
两头堵模型：
例如：*p = "   abcdef    ";
一个指针指向一个元素的地址，一个指针指向最后一个元素的地址，然后分别向后移动，两者相互移动到非空格
元素时，即可求得非空格字符串长度
*/
int main15()
{
	int i = 0;
	char p[] = "    abcdef    ";
	int j = strlen(p) - 1;
	int ncount = 0;
	
	while ( isspace(p[i]) && p[i] != '\0' )
	{
		i++;
	}
	while ( isspace(p[j]) && p[j] )
	{
		j--;
	}
	ncount = j - i + 1;

	printf("ncount:%d\n", ncount);
	system("pause");
	return 0;
}
/*
测试结果：
ncount:6
请按任意键继续. . .
*/

/*
求非空格的字符串长度
*/
int getCount16(char *str, int *pcount)
{
	char *p = str;
	int ncount = 0;
	int i, j = 0;

	if ( str == NULL || pcount == NULL )
	{
		return -1;
	}

	i = 0;
	j = strlen(p) - 1;
	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}
	while (isspace(p[j]) && p[j])
	{
		j--;
	}
	ncount = j - i + 1;
	*pcount = ncount;
	return 0;
}

int main16()
{
	char p[] = "    abcdef    ";
	int pcount = 0;
	getCount16(p, &pcount);
	printf("pcount:%d\n", pcount);

	system("pause");
	return 0;
}
/*
pcount:6
请按任意键继续. . .
*/