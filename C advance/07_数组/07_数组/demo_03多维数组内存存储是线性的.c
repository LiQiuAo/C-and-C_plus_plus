/*
文件名称:多维数组内存存储线性证明
作    者：lqa
编辑时间：20180124
*/

#include <stdlib.h>
#include <stdio.h>

/*
打印
*/
void PrintArray(int* array, int size)
{
	int i;
	for ( i = 0; i < size; i++ )
	{
		printf("%d ", array[i]);
	}
}

void main06()
{
	int a[3][5];
	int i, j;
	int tmp = 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			a[i][j] = tmp++;
		}
	}

	//把二维数组当成一维数组来打印，证明线性存储
	PrintArray((int*)a, 15); 
	
	system("pause");
	return 0;
}