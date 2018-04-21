/*
文件名称：二级指针做输入的第一种内存模型
作    者：lqa
编辑时间：20180117
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main03()
{
	int i, j;
	int num = 0;
	char *tmp = NULL;
	//数组中的每一个元素是指针，也就是指针数组
	char *myArray[] = {"aaa", "bbbbb", "cccccc", "dddd"};

	num = sizeof(myArray) / sizeof(myArray[0]);
	
	printf("排序之前\n");
	//打印
	for ( i = 0; i < num; i++ )
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}

	//排序
	for ( i = 0; i < num; i++ )
	{
		for ( j = i+1; j < num; j++ )
		{
			if ( strcmp(myArray[i],myArray[j]) > 0 )
			{
				tmp = myArray[i];//注意：交换的是数组元素，也可以称交换的是指针的值
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}

	printf("排序之后\n");
	//打印
	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}

	system("pause");
	return 0;
}

/*
打印
*/
void printMyArray(char **myArray, int num)
{
	int i;
	//打印
	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}
}

/*
排序
*/
void sortMyArray(char **myArray, int num)
{
	int i, j;
	char *tmp = NULL;
	//排序
	for (i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				tmp = myArray[i];//注意：交换的是数组元素，也可以称交换的是指针的值
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

int main04()
{
	int num = 0;
	//数组中的每一个元素是指针，也就是指针数组
	char *Array[] = {"bbbbb","aaa", "dddd","cccccc" };

	num = sizeof(Array) / sizeof(Array[0]);
	printf("排序之前\n");
	printMyArray(Array, num);
	
	sortMyArray(Array, num);

	printf("排序之后\n");
	//打印
	printMyArray(Array, num);

	system("pause");
	return 0;
}