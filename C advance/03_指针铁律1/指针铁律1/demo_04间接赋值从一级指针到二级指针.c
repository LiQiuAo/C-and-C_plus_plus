/*
�ļ����ƣ���Ӹ�ֵ��һ��ָ�뵽����ָ��
��    �ߣ�LQA
��дʱ�䣺20180115
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
��Ӹ�ֵ p2��p1�ĵ�ַ
*/
void getMem(char **p2)
{
	*p2 = 300;
}

int getMem2(char **myp1, int *mylen1, char **myp2, int *mylen2)
{
	char *tmp1, *tmp2;

	tmp1 = (char *)malloc(100);
	strcpy(tmp1, "12222111");

	//��Ӹ�ֵ
	*mylen1 = strlen(tmp1);//һ��ָ��
	*myp1 = tmp1;//2��ָ��ļ�Ӹ�ֵ

	tmp2 = (char *)malloc(200);
	strcpy(tmp2, "34323232");

	*mylen2 = strlen(tmp2);//һ��ָ��
	*myp2 = tmp2;//2��ָ��ļ�Ӹ�ֵ
	return 0;
}

int main4()
{
	char *p1 = NULL;
	char **p2 = NULL;

	p1 = 0x11;
	p2 = 0x22;

	//ֱ���޸�p1��ֵ
	p1 = 0x111;

	//����޸�p1��ֵ
	p2 = &p1;
	*p2 = 200;

	printf("p1:%d\n", p1);
	
	getMem(&p1);
	printf("p1:%d\n", p1);

	system("pause");
	return 0;
}
/*
p1:200
p1:300
*/

int main5()
{
	int ret = 0;

	char *p1 = NULL;
	int len1 = 0;
	char *p2 = NULL;
	int len2 = 0;

	ret = getMem2(&p1, &len1, &p2, &len2);

	if ( ret != 0 )
	{
		printf("error:%d\n", ret);
		return ret;
	}

	printf("p1:%s \n", p1);
	printf("p1:%s \n", p2);

	if ( p1 != NULL )
	{
		free(p1);
		p1 = NULL;
	}
	if ( p2 != NULL )
	{
		free(p2);
		p2 = NULL;
	}
	system("pause");
	return ret;
}

/*
��Ӹ�ֵ����������������
1)2��������ͨ��һ��ʵ�Σ�һ���βΣ�
2)������ϵ��ʵ��ȡ��ַ�����β�ָ��
3)*p�β�ȥ����޸�ʵ�ε�ֵ
*/
int main6()
{
	/*
	1��2��3��3������д��һ��������
	1��2д��һ�� 3����д����һ����������==����������
	1   2��3д��һ��==��C++�л��õ�
	*/

	char from[128];
	char to[128] = {0};
	char *p1 = from;
	char *p2 = to;

	strcpy(from, "1231231231");
	while ( *p1 != '\0' )
	{
		*p2 = *p1;
		p2++;
		p1++;
	}
	printf("to:%s\n", to);
	system("pause");
	return 0;
}