/*
文件名称：指针的输入和输出特性
作    者：lqa
编辑时间：20180117
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
指针做输出：被调用函数分配内存
指针做输入：主调用函数分配内存
求文件中的两段话的长度
*/
int getMem(char **myp1/*out*/, int *mylen1/*in*/, char **myp2/*out*/, int *mylen2/*in*/)
{
	/*
	指针的地址必然要用一个二级指针来接
	联系内存四区的概念：char **myp1 = &p1;
	*myp1 = p1;
	而p1指向的内存的存储空间
	*/
	char *tmp1 = NULL;
	char *tmp2 = NULL;

	tmp1 = (char *)malloc(100);
	if ( tmp1 == NULL )
	{
		return -1;
	}
	strcpy(tmp1, "abcdefg");
	*mylen1 = strlen(tmp1);
	*myp1 = tmp1;//间接修改实参p1的值

	tmp2 = (char *)malloc(100);
	if (tmp2 == NULL)
	{
		return -2;
	}
	strcpy(tmp2, "abcdefghijk");
	*mylen2 = strlen(tmp2);
	*myp2 = tmp2;
	return 0;
}

/*
释放内存空间
*/
int getMem_Free(char **myp1/*in*/)
{
	/*
	if ( myp1 == NULL )
	{
		return;
	}
	free(*myp1);//释放完指针变量所指的内存空间，要把实参修改成null
	*myp1 = NULL;
	return 0;
	*/
	char *tmp = NULL;
	if ( myp1 == NULL )
	{
		return -1;
	}
	tmp = *myp1;
	free(tmp);
	*myp1 = NULL;
	return 0;
}

int main01()
{
	char *p1 = NULL;
	int len1 = 0;

	char *p2 = NULL;
	int len2 = 0;

	int ret = 0;

	ret = getMem(&p1, &len1, &p2, &len2);

	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	getMem_Free(&p1);
	getMem_Free(&p2);

	system("pause");
	return 0;
}

int getMem_Free2(char *myp1)
{
	if ( myp1 == NULL )
	{
		return -1;
	}

	/*
	该处为什么不能直接这样写将myp1 = NULL呢？
	因为这修改的是形参，和实参没有任何关系
	*/
	free(myp1);
	return 0;
}

int main02()
{
	char *p1 = NULL;
	int len1 = 0;

	char *p2 = NULL;
	int len2 = 0;

	int ret = 0;

	ret = getMem(&p1, &len1, &p2, &len2);
	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	/*
	释放内存的第二种方法
	*/
	if ( p1 != NULL )
	{
		free(p1);
		p1 = NULL;
	}
	if ( p2 != NULL )
	{
		free(p2);
		p2 = NULL;
	}

	/*释放内存的第一种方法*/
	getMem_Free2(p1);
	getMem_Free2(p2);

	system("pause");
	return 0;
}