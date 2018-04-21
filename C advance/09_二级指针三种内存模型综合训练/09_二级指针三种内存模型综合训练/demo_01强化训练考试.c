/*
文件名称：二级指针的强化训练
作    者：lqa
编辑时间：20180125
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
排序
*/
int Sort(char** myp1/*in*/, int num1, char(*myp2)[30], int num2, char*** myp3, int* num3)
{
	int ret = 0;
	int i = 0, j = 0;
	int tmplen = 0;
	char* tmp = NULL;
	char** p3 = NULL;
	p3 = malloc((num1 + num2) * sizeof(char*));//里面装的指针，要用char*
	if (p3 == NULL)
	{
		return -1;
	}

	for ( i = 0; i < num1; i++)
	{
		tmplen = strlen(myp1[i]) + 1;
		p3[i] = (char*)malloc(sizeof(char) * tmplen);

		if (p3[i] == NULL)
		{
			return -2;
		}
		strcpy(p3[i], myp1[i]);
	}

	for ( j = 0; j < num2; j++, i++)
	{
		tmplen = strlen(myp2[j]) + 1;
		p3[i] = (char*)malloc(sizeof(char) * tmplen);//该处的局部变量i已经变为3

		if (p3[i] == NULL)
		{
			return -3;
		}
		strcpy(p3[i], myp2[j]);
	}

	tmplen = num1 + num2;
	//排序
	for ( i = 0; i < tmplen; i++ )
	{
		for ( j = i+1; j < tmplen; j++ )
		{
			if ( strcmp(p3[i], p3[j]) > 0 )
			{
				tmp = p3[i];
				p3[i] = p3[j];
				p3[j] = tmp;
			}
		}
	}
	//间接赋值
	*num3 = tmplen;
	*myp3 = p3;

	return ret;
}

/*
释放内存
*/
void sortFree01 (char** p, int len)
{
	int i = 0;
	if ( p == NULL )
	{
		return;
	}
	for ( i = 0; i < len; i++ )
	{
		free(p[i]);//p[i]等价于*(p+i)
	}
	free(p);
}

/*
释放内存
把二级指针指向二维内存释放掉，同时间接修改了实参的值
*号就像一把钥匙打开一扇门
*/
void sortFree02(char*** myp, int len)
{
	int i = 0;
	char** p = NULL;
	if ( myp == NULL )
	{
		return;
	}

	p = *myp;//还原成二级指针
	if ( p == NULL )
	{
		return;
	}

	for (i = 0; i < len; i++)
	{
		free(p[i]);//p[i]等价于*(p+i)
	}
	free(p);
	*myp = NULL;//间接赋值是指针存在的最大意义
}

int main()
{
	int ret = 0;
	char* p1[] = {"aaaaa", "ccccc", "bbbbb"};
	char buf2[10][30] = {"111111", "333333", "222222"};
	char** p3 = NULL;
	int len1, len2, len3;

	len1 = sizeof(p1) / sizeof(*p1);
	len2 = 3;

	ret = Sort(p1, len1, buf2, len2, &p3, &len3);
	if ( ret != 0 )
	{
		printf("func sort() err:%d\n", ret); 
	}
	for ( int i = 0; i < len3; i++ )
	{
		printf("%s\n", p3[i]);
	}
	system("pause");
	return 0;
}

/*
测试结果：
111111
222222
333333
aaaaa
bbbbb
ccccc
请按任意键继续. . .
*/