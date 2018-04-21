/*
文件名称：二级指针做输入的第二种内存模型
作    者：lqa
编辑时间：20180117
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main05()
{
	int i, j;
	int num = 4;
	//char myBuf[30];
	char tmpBuf[30];
	char myArray[10][30] = { "bbbbb","aaa", "dddd","cccccc" };

	printf("排序之前\n");
	//打印
	for ( i = 0; i < num; i++ ) 
	{
		printf("%s\n", myArray[i]);
	}

	//排序
	for (i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++ )
		{
			if ( strcmp(myArray[i], myArray[j]) > 0 )
			{
				strcpy(tmpBuf, myArray[i]);
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmpBuf);
			}
		}
	}

	printf("排序之后\n");
	//打印
	for (i = 0; i < num; i++)
	{
		printf("%s\n", myArray[i]);
	}

	system("pause");
	return;
}

/*
打印
*/
void printMyArray02(char myArray[10][30], int num)
{
	int i;
	//打印
	for (i = 0; i < num; i++)
	{
		/*
		问题的本质是：demo_03二级指针做输入第2中内存模型的myArray + 1
		与demo_02二级指针做输入第1中内存模型的myArray + 1不一样；
		指针的步长不一样，就是说指针所指向的内存空间的数据类型不一样。
		该处的步长应为30，就是myArray+1会往后跳30个单元
		*/
		printf("%s \n", myArray[i]);
		//printf("%s \n", *(myArray + i));
	}
}

/*
排序
*/
void sortMyArray02(char myArray[10][30], int num)
{
	//排序
	int i, j;
	char tmpBuf[30];
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				strcpy(tmpBuf, myArray[i]);//交换的是内存块
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmpBuf);
			}
		}
	}
}

int main06()
{
	int num = 4;

	/*
	编译器只会关心:有10行，每行30列。
	为什么会关心？
	因为和(Array+1)有关,会往后跳30个单元
	*/
	char Array[10][30] = { "bbbbb", "aaa", "dddd", "cccccc" };
	{
		int len1 = sizeof(Array);
		int len2 = sizeof(Array);
		int size = len1 / len2;
		printf("len1:%d, len2:%d, size:%d \n", len1, len2, size);
	}

	printf("排序之前\n");
	//打印
	printMyArray02(Array, num);

	//排序
	sortMyArray02(Array, num);
	
	printf("排序之后\n");
	//打印
	printMyArray02(Array, num);

	system("pause");
	return 0;
}

/*
测试结果：
排序之前
bbbbb
aaa
dddd
cccccc
排序之后
aaa
bbbbb
cccccc
dddd
请按任意键继续. . .
*/