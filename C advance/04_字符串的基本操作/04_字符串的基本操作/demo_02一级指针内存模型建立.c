/*
�ļ����ƣ�һ��ָ���ڴ�ģ�ͽ���
��    �ߣ�lqa
�༭ʱ�䣺20180115
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main4()
{
	char buf[20] = "aaaa";
	char buf2[] = "bbbb";
	char *p1 = "1111";
	char *p2 = malloc(100);

	strcpy(p2, "2222");
	printf("%s\n", p1);
	system("pause");
	return;
}