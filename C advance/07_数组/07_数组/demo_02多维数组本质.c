/*
文件名称:多维数组名的本质
作    者：lqa
编辑时间：20180124
*/

#include <stdlib.h>
#include <stdio.h>

/*
打印
*/
void printArray01(int a[3][5])
{
	int i, j;
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
}

/*
打印
*/
void printArray02(int a[][5])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
}


/*
打印
*/
void printArray03(int (*b)[5])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", b[i][j]);
		}
	}
}

/*
多维数组名的本质：数组指针，步长是一维的长度
*/
int main05()
{
	//定义一个指向数组的指针变量
	int(*pArray)[5];//告诉编译器 分配 4个字节的内存（32bit平台下）/若在64bit平台下，将分配8个字节
	int a[3][5];
	int tmp = 1;
	  
	pArray = a;
	printf("\n");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			pArray[i][j] = tmp++;
		}
	}

	printArray01(a);
	printArray02(a);
	printArray03(a);

	system("pause");
	return 0;
}  

