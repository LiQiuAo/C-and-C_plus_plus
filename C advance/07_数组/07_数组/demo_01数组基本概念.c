/*
�ļ����ƣ������������
��    �ߣ�lqa
�༭ʱ�䣺20180123
*/

#include <stdlib.h>
#include <stdio.h>

/*
���ͱ��ʣ��̶���С�ڴ��ı���
����ָ�룺��һ��ָ����ָ��һ������
*/
int main01()
{
	typedef int (ArrayType)[5];//����һ���������� ������������
	ArrayType myArray;//�൱��int myArray[5];

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
��������ָ������ķ���1��ͨ���������Ͷ�������ָ��
*/
int main02()
{
	/*ָ�����������ָ���ǲ�ͬ��
	ָ������ı��������飬������ÿ����Ա��һ��ָ�룬Array����[]��ϣ�
	��������Ķ��壬char*���ε�����������ݣ��������ÿ��Ԫ��.
	*/
	char* Array[] = {"1111", "2222", "3333"};//ָ������

	//����ָ�� ��һ��ָ����ָ��һ������
	typedef int (ArrayType)[5];//����һ���������� ������������
	ArrayType myArray;//�൱��int myArray[5];
	ArrayType* pArray;//����һ��ָ�������ָ��һ������

	{
		int myArray2[5];//�൱��һ��ָ��
		pArray = &myArray2;//�൱�ڶ���ָ��
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
��������ָ������ķ���2������һ������ָ������
*/
int main03()
{
	typedef int (*PArrayType)[5];//��������һ������ָ������
	PArrayType pArray;//���߱��������ҷ���һ��ָ�����

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
��������ָ������ķ���3��
ǰ���ַ���ͨ�����Ͷ������
*/
int main04()
{
	int (*pMyArray)[5];//ֱ�Ӷ���һ��ָ�������  ����ָ�����

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