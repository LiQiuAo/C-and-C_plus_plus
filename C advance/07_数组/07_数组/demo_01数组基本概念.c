/*
文件名称：数组基本概念
作    者：lqa
编辑时间：20180123
*/

#include <stdlib.h>
#include <stdio.h>

/*
类型本质：固定大小内存块的别名
数组指针：用一个指针来指向一个数组
*/
int main01()
{
	typedef int (ArrayType)[5];//定义一个数据类型 数组数据类型
	ArrayType myArray;//相当于int myArray[5];

	for ( int i = 0; i < 5; i++ )
	{
		myArray[i] = i+1;
	}
	for ( int i = 0; i < 5; i++ )
	{
		printf("%d ", myArray[i]);
	}
	system("pause");
	return 0;
}

/*
定义数组指针变量的方法1：通过数组类型定义数组指针
*/
int main02()
{
	/*指针数组和数组指针是不同的
	指针数组的本质是数组，数组中每个成员是一个指针，Array先与[]结合，
	构成数组的定义，char*修饰的是数组的内容，即数组的每个元素.
	*/
	char* Array[] = {"1111", "2222", "3333"};//指针数组

	//数组指针 用一个指针来指向一个数组
	typedef int (ArrayType)[5];//定义一个数据类型 数组数据类型
	ArrayType myArray;//相当于int myArray[5];
	ArrayType* pArray;//定义一个指针变量，指向一个数组

	{
		int myArray2[5];//相当于一级指针
		pArray = &myArray2;//相当于二级指针
		int i;

		for ( i = 0; i < 5; i++ )
		{
			(*pArray)[i] = i + 1;
		}
	
		for ( i = 0; i < 5; i++ )
		{
			printf("%d ", (*pArray)[i]);
		}
	}
	system("pause");
	return 0;
}

/*
定义数组指针变量的方法2：声明一个数组指针类型
*/
int main03()
{
	typedef int (*PArrayType)[5];//定义声明一个数组指针类型
	PArrayType pArray;//告诉编译器给我分配一个指针变量

	int c[5];
	int i;
	pArray = &c;

	for (i = 0; i < 5; i++)
	{
		(*pArray)[i] = i + 1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d ", (*pArray)[i]);
	}

	system("pause");
	return 0;
}

/*
定义数组指针变量的方法3：
前两种方法通过类型定义变量
*/
int main04()
{
	int (*pMyArray)[5];//直接定义一个指向数组的  数组指针变量

	int c[5];
	int i;
	pMyArray = &c;

	for (i = 0; i < 5; i++)
	{
		(*pMyArray)[i] = i + 1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d ", (*pMyArray)[i]);
	}

	system("pause");
	return 0;
}