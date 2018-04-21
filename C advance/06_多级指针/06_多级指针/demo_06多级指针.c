/*
文件名称：多级指针
作    者：lqa
编辑时间：20180117
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char **getMem05(int num)
{
	char **p2 = NULL;
	p2 = (char **)malloc(sizeof(char *) * num);//相当于buf[num]

	//申请内存
	for (int i = 0; i < num; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * 100);//char buf[100]
		/*
		语法:
		#include <stdio.h>
		int sprintf( char *buffer, const char *format, ... );
		sprintf()函数和printf()类似, 只是把输出发送到buffer(缓冲区)中.返回值是写入的字符数量.
		*/
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	return p2;
}

int getMem06(char ***p3, int num)
{
	char **tmp = NULL;
	tmp = (char **)malloc(sizeof(char *) * num);//相当于buf[num]

	if ( p3 == NULL )//判断指针变量是否为NULL，注意不可用*P(*P表示的是指针所指向的那块内存空间，它是可以为NULL的)
	{
		return -1;
	}

	//申请内存
	for (int i = 0; i < num; i++)
	{
		tmp[i] = (char *)malloc(sizeof(char) * 100);//char buf[100]
		/*
		语法:
		#include <stdio.h>
		int sprintf( char *buffer, const char *format, ... );
		sprintf()函数和printf()类似, 只是把输出发送到buffer(缓冲区)中.返回值是写入的字符数量.
		*/
		sprintf(tmp[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	*p3 = tmp;
	return 0;
}

/*
释放内存空间
*/
void getMem06_Free(char ***p3, int num)
{
	char **tmp = NULL;
	if ( p3 == NULL )
	{
		return;
	}
	tmp = *p3;
	
	for ( int i = 0; i < num; i++ )
	{
		free(tmp[i]);
	}
	free(tmp);
	*p3 = NULL;//把实参赋值为null
}

int main10()
{
	char **p2 = NULL;
	char *tmp = NULL;
	int num = 5;
	//p2 = getMem05(num);
	getMem06(&p2, num);

	for ( int i = 0; i < num; i++ )
	{
		printf("%s \n", p2[i]);
	}
	getMem06_Free(&p2, num);
	system("pause");
	return 0;
}