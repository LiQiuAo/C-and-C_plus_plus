/*
�ļ�����:��ά�������ı���
��    �ߣ�lqa
�༭ʱ�䣺20180124
*/

#include <stdlib.h>
#include <stdio.h>

/*
��ӡ
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
��ӡ
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
��ӡ
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
��ά�������ı��ʣ�����ָ�룬������һά�ĳ���
*/
int main05()
{
	//����һ��ָ�������ָ�����
	int(*pArray)[5];//���߱����� ���� 4���ֽڵ��ڴ棨32bitƽ̨�£�/����64bitƽ̨�£�������8���ֽ�
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

