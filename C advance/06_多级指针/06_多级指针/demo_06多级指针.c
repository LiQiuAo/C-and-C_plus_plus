/*
�ļ����ƣ��༶ָ��
��    �ߣ�lqa
�༭ʱ�䣺20180117
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char **getMem05(int num)
{
	char **p2 = NULL;
	p2 = (char **)malloc(sizeof(char *) * num);//�൱��buf[num]

	//�����ڴ�
	for (int i = 0; i < num; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * 100);//char buf[100]
		/*
		�﷨:
		#include <stdio.h>
		int sprintf( char *buffer, const char *format, ... );
		sprintf()������printf()����, ֻ�ǰ�������͵�buffer(������)��.����ֵ��д����ַ�����.
		*/
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	return p2;
}

int getMem06(char ***p3, int num)
{
	char **tmp = NULL;
	tmp = (char **)malloc(sizeof(char *) * num);//�൱��buf[num]

	if ( p3 == NULL )//�ж�ָ������Ƿ�ΪNULL��ע�ⲻ����*P(*P��ʾ����ָ����ָ����ǿ��ڴ�ռ䣬���ǿ���ΪNULL��)
	{
		return -1;
	}

	//�����ڴ�
	for (int i = 0; i < num; i++)
	{
		tmp[i] = (char *)malloc(sizeof(char) * 100);//char buf[100]
		/*
		�﷨:
		#include <stdio.h>
		int sprintf( char *buffer, const char *format, ... );
		sprintf()������printf()����, ֻ�ǰ�������͵�buffer(������)��.����ֵ��д����ַ�����.
		*/
		sprintf(tmp[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	*p3 = tmp;
	return 0;
}

/*
�ͷ��ڴ�ռ�
*/
void getMem06_Free(char ***p3, int num)
{
	char **tmp = NULL;
	if ( p3 == NULL )
	{
		return;
	}
	tmp = *p3;
	
	for ( int i = 0; i < num; i++ )
	{
		free(tmp[i]);
	}
	free(tmp);
	*p3 = NULL;//��ʵ�θ�ֵΪnull
}

int main10()
{
	char **p2 = NULL;
	char *tmp = NULL;
	int num = 5;
	//p2 = getMem05(num);
	getMem06(&p2, num);

	for ( int i = 0; i < num; i++ )
	{
		printf("%s \n", p2[i]);
	}
	getMem06_Free(&p2, num);
	system("pause");
	return 0;
}