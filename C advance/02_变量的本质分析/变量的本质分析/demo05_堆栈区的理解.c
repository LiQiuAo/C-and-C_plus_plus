/*
�ļ����ƣ���ջ�������
��    �ߣ�LQA
ʱ    �䣺2018��1��14��
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

/*  
��
*/
char *getMem(int num)
{
	char *p1 = NULL;
	p1 = (char *)malloc(sizeof(char) * num);
	if ( p1 == NULL )
	{
		return NULL;
	}
	return p1;
}

/*
ջ
ע�⣺return���ǰ��ڴ��64���ֽڸ�return���������ǰ��ڴ����׵�ַ(�ڴ�ı��0xaa11),���ظ�tmp 
*/
char *getMem2()
{
	char buf[64];//��ʱ���� ջ�����
	strcpy(buf, "123456");
	return buf;
}


int main4()
{
	char *tmp = NULL;
	tmp = getMem(10);
	if ( tmp == NULL )
	{
		return;
	}
	strcpy(tmp, "111222");//��tmp��ָ����ڴ�ռ���copy����

	tmp = getMem2();
	printf("tmp = %d\n", tmp);
	system("pause");
	return 0;
}