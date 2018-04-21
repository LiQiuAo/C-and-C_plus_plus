/*
文件名称：指针的输入和输出特性-企业里常使用到
作    者：LQA
编写时间：20180115
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
什么是指针的输入、输出特性？
指针的输入：是指在主调函数中申请的内存，然后传给被调函数中使用，这叫做指针的输入
指针的输出：是指在被调用函数中申请内存，期间可能做一系列复杂的操作，然后再让主调用函数使用。
*/
int getMem3(char **myp1/*out*/, int *mylen1/*out*/, char **myp2/*out*/, int *mylen2/*out*/)
{
	char *tmp1, *tmp2;

	tmp1 = (char *)malloc(100);
	strcpy(tmp1, "12222111");

	//间接赋值
	*mylen1 = strlen(tmp1);//一级指针
	*myp1 = tmp1;//2级指针的间接赋值

	tmp2 = (char *)malloc(200);
	strcpy(tmp2, "34323232");

	*mylen2 = strlen(tmp2);//一级指针
	*myp2 = tmp2;//2级指针的间接赋值
	return 0;
}

int main()
{
	int ret = 0;

	char *p1 = NULL;
	int len1 = 0;
	char *p2 = NULL;
	int len2 = 0;

	ret = getMem3(&p1, &len1, &p2, &len2);

	if (ret != 0)
	{
		printf("error:%d\n", ret);
		return ret;
	}

	printf("p1:%s \n", p1);
	printf("p1:%s \n", p2);

	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
	system("pause");
	return ret;
}