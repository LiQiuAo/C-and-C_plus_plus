/*
�ļ����ƣ���Ӹ�ֵ�ļ�������
��    �ߣ�LQA
��дʱ�䣺20180114
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int getFileLen(int *p)
{
	*p = 40;//p��ֵ��a�ĵ�ַ��*a����޸�a��ֵ
}

//returnֻ�ܷ���һ�����
int getFileLen2()
{
	int a = 100;
	return a;
}

int getFileLen3(int b)
{
	b = 100;
}


int main3()
{
	int a = 10;
	int *p = NULL;

	//�޸�a��ֵ
	a = 20;//ֱ���޸�
	p = &a;
	*p = 30;//p��a�õ�ַ

	printf("a:%d\n", a);

	getFileLen(&a);
	printf("getFileLen��:%d\n", a);
	
	getFileLen3(a);
	printf("getFileLen3��:%d\n", a);

	system("pause");
	return 0;
}

