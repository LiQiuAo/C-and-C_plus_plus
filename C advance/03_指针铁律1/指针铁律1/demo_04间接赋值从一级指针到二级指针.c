/*
文件名称：间接赋值从一级指针到二级指针
作    者：LQA
编写时间：20180115
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
间接赋值 p2是p1的地址
*/
void getMem(char **p2)
{
	*p2 = 300;
}

int getMem2(char **myp1, int *mylen1, char **myp2, int *mylen2)
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

int main4()
{
	char *p1 = NULL;
	char **p2 = NULL;

	p1 = 0x11;
	p2 = 0x22;

	//直接修改p1的值
	p1 = 0x111;

	//间接修改p1的值
	p2 = &p1;
	*p2 = 200;

	printf("p1:%d\n", p1);
	
	getMem(&p1);
	printf("p1:%d\n", p1);

	system("pause");
	return 0;
}
/*
p1:200
p1:300
*/

int main5()
{
	int ret = 0;

	char *p1 = NULL;
	int len1 = 0;
	char *p2 = NULL;
	int len2 = 0;

	ret = getMem2(&p1, &len1, &p2, &len2);

	if ( ret != 0 )
	{
		printf("error:%d\n", ret);
		return ret;
	}

	printf("p1:%s \n", p1);
	printf("p1:%s \n", p2);

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
	system("pause");
	return ret;
}

/*
间接赋值成立的三个条件：
1)2个变量（通常一个实参，一个形参）
2)建立关系，实参取地址赋给形参指针
3)*p形参去间接修改实参的值
*/
int main6()
{
	/*
	1、2、3这3个条件写在一个函数中
	1、2写在一块 3单独写在另一个函数里面==》函数调用
	1   2、3写在一块==》C++中会用到
	*/

	char from[128];
	char to[128] = {0};
	char *p1 = from;
	char *p2 = to;

	strcpy(from, "1231231231");
	while ( *p1 != '\0' )
	{
		*p2 = *p1;
		p2++;
		p1++;
	}
	printf("to:%s\n", to);
	system("pause");
	return 0;
}