/*
�ļ����ƣ��༶ָ���ǿ��
��    �ߣ�lqa
�༭ʱ�䣺20180203
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int getMem01(char*** p) 
{
	*p = 30;
}

int main01()
{
	char** p = NULL;
	char*** p2 = NULL;

	p2 = &p;
	getMem(p2);
	{
		*p2 = 10;//ֱ���޸Ķ���ָ���ֵ
	}

	return 0;
}

int getMem02(char******** p2)
{
	*p2 = 10;//ֱ���޸Ķ���ָ���ֵ
}

int main()
{
	char******* p = NULL;
	char******** p2 = NULL;

	p = 1;//ֱ���޸�
	p2 = &p;
	getMem02(p2);//����޸�,*��p�ĵ�ַ�����Լ�ӵ��޸���p��ֵ

	system("pause"); 
	return 0;
}