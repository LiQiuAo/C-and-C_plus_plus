/*
�ļ����ƣ�����ָ���ڴ�ģ��
��    �ߣ�lqa
�༭ʱ�䣺20180117
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main09()
{
	int i = 0;

	//ָ������
	char *p1[] = {"123", "456", "789"};

	//��ά����
	char p2[3][4] = { "123", "456", "789" };

	//�ֹ���ά�ڴ�
	char **p3 = (char **)malloc(sizeof(char *) * 3);//char *buf[3]

	for ( i = 0; i < 3; i++ )
	{
		p3[i] = (char *)malloc(sizeof(char) * 10);//char buf[10]
		sprintf(p3[i], "%d%d%d", i, i, i);
	}

	return 0;
}