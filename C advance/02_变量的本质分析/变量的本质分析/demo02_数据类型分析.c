/*
�ļ����ƣ��������͵ķ���
��    �ߣ�LQA
ʱ    �䣺2018��1��12��
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

/*
��θ�����������һ��������
*/
struct Teacher
{
	char name[64];
	int age;
}Teacher;

/*
����typedef������������ȡ����
*/
typedef struct Teacher2
{
	char name[64];
	int age;
}Teacher2;


void main2()
{
	/*
	Ҫվ�ڱ������ĽǶȿ����⣻
	*/
	int a;//����c�����������ĸ��ֽڵ��ڴ�
	int b[10];//����c����������40���Լ��ڴ�

	printf("b:%d, b+1:%d, &b:%d, &b+1:%d \n", b, b+1, &b, &b+1);
	printf("sizeof(b):%d\n", sizeof(b));
	printf("sizeof(a):%d\n", sizeof(a));

	struct Teacher t1;
	Teacher2 t2;

	{
		//void c;//��������֪����η����ڴ棬��������ʹ��
	}

	system("pause");
}
/*
b:15727484, b+1:15727488
&b:15727484, &b+1:15727524
sizeof(b):40
sizeof(a):4

b�����������Ԫ�صĵ�ַ
&b���������������ĵ�ַ
*/
