/*
�ļ����ƣ�����ָ��������ĵڶ����ڴ�ģ��
��    �ߣ�lqa
�༭ʱ�䣺20180117
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

	printf("����֮ǰ\n");
	//��ӡ
	for ( i = 0; i < num; i++ ) 
	{
		printf("%s\n", myArray[i]);
	}

	//����
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

	printf("����֮��\n");
	//��ӡ
	for (i = 0; i < num; i++)
	{
		printf("%s\n", myArray[i]);
	}

	system("pause");
	return;
}

/*
��ӡ
*/
void printMyArray02(char myArray[10][30], int num)
{
	int i;
	//��ӡ
	for (i = 0; i < num; i++)
	{
		/*
		����ı����ǣ�demo_03����ָ���������2���ڴ�ģ�͵�myArray + 1
		��demo_02����ָ���������1���ڴ�ģ�͵�myArray + 1��һ����
		ָ��Ĳ�����һ��������˵ָ����ָ����ڴ�ռ���������Ͳ�һ����
		�ô��Ĳ���ӦΪ30������myArray+1��������30����Ԫ
		*/
		printf("%s \n", myArray[i]);
		//printf("%s \n", *(myArray + i));
	}
}

/*
����
*/
void sortMyArray02(char myArray[10][30], int num)
{
	//����
	int i, j;
	char tmpBuf[30];
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				strcpy(tmpBuf, myArray[i]);//���������ڴ��
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
	������ֻ�����:��10�У�ÿ��30�С�
	Ϊʲô����ģ�
	��Ϊ��(Array+1)�й�,��������30����Ԫ
	*/
	char Array[10][30] = { "bbbbb", "aaa", "dddd", "cccccc" };
	{
		int len1 = sizeof(Array);
		int len2 = sizeof(Array);
		int size = len1 / len2;
		printf("len1:%d, len2:%d, size:%d \n", len1, len2, size);
	}

	printf("����֮ǰ\n");
	//��ӡ
	printMyArray02(Array, num);

	//����
	sortMyArray02(Array, num);
	
	printf("����֮��\n");
	//��ӡ
	printMyArray02(Array, num);

	system("pause");
	return 0;
}

/*
���Խ����
����֮ǰ
bbbbb
aaa
dddd
cccccc
����֮��
aaa
bbbbb
cccccc
dddd
�밴���������. . .
*/