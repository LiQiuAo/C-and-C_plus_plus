/*
�ļ�����:��ά�����ڴ�洢����֤��
��    �ߣ�lqa
�༭ʱ�䣺20180124
*/

#include <stdlib.h>
#include <stdio.h>

/*
��ӡ
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

	//�Ѷ�ά���鵱��һά��������ӡ��֤�����Դ洢
	PrintArray((int*)a, 15); 
	
	system("pause");
	return 0;
}