/*
�ļ����ƣ��ڴ������е�ջ����ȫ���������
��    �ߣ�LQA
ʱ    �䣺2018��1��12��
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

char *getStr1()
{
	char *p1 = "abcdefg2";//����ڽ��ַ�������a���׵�ַ��ֵ��p1
	return p1;
}

char *getStr2()
{
	char *p2 = "abcdefg2";
	return p2;
}

int main()
{
	char *p1 = NULL;
	char *p2 = NULL;
	p1 = getStr1();
	p2 = getStr2();

	//��ӡp1 p2��ָ���ڴ�ռ������
	printf("p1:%s, p2:%s \n", p1, p2);

	//��ӡp1 p2��ֵ
	printf("p1:%d, p2:%d \n", p1, p2);

	system("pause");
	return 0;
}
/*
���Խ����
p1:abcdefg2, p2:abcdefg2
p1:1665940, p2:1665940
*/