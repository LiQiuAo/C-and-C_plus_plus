/*
�ļ����ƣ�����ָ��������ĵ�һ���ڴ�ģ��
��    �ߣ�lqa
�༭ʱ�䣺20180117
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main03()
{
	int i, j;
	int num = 0;
	char *tmp = NULL;
	//�����е�ÿһ��Ԫ����ָ�룬Ҳ����ָ������
	char *myArray[] = {"aaa", "bbbbb", "cccccc", "dddd"};

	num = sizeof(myArray) / sizeof(myArray[0]);
	
	printf("����֮ǰ\n");
	//��ӡ
	for ( i = 0; i < num; i++ )
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}

	//����
	for ( i = 0; i < num; i++ )
	{
		for ( j = i+1; j < num; j++ )
		{
			if ( strcmp(myArray[i],myArray[j]) > 0 )
			{
				tmp = myArray[i];//ע�⣺������������Ԫ�أ�Ҳ���Գƽ�������ָ���ֵ
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}

	printf("����֮��\n");
	//��ӡ
	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}

	system("pause");
	return 0;
}

/*
��ӡ
*/
void printMyArray(char **myArray, int num)
{
	int i;
	//��ӡ
	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}
}

/*
����
*/
void sortMyArray(char **myArray, int num)
{
	int i, j;
	char *tmp = NULL;
	//����
	for (i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				tmp = myArray[i];//ע�⣺������������Ԫ�أ�Ҳ���Գƽ�������ָ���ֵ
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

int main04()
{
	int num = 0;
	//�����е�ÿһ��Ԫ����ָ�룬Ҳ����ָ������
	char *Array[] = {"bbbbb","aaa", "dddd","cccccc" };

	num = sizeof(Array) / sizeof(Array[0]);
	printf("����֮ǰ\n");
	printMyArray(Array, num);
	
	sortMyArray(Array, num);

	printf("����֮��\n");
	//��ӡ
	printMyArray(Array, num);

	system("pause");
	return 0;
}