/*
�ļ�����:��ͷ��ģ��
��    �ߣ�LQA
�༭ʱ�䣺20180116
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*
��ͷ��ģ�ͣ�
���磺*p = "   abcdef    ";
һ��ָ��ָ��һ��Ԫ�صĵ�ַ��һ��ָ��ָ�����һ��Ԫ�صĵ�ַ��Ȼ��ֱ�����ƶ��������໥�ƶ����ǿո�
Ԫ��ʱ��������÷ǿո��ַ�������
*/
int main15()
{
	int i = 0;
	char p[] = "    abcdef    ";
	int j = strlen(p) - 1;
	int ncount = 0;
	
	while ( isspace(p[i]) && p[i] != '\0' )
	{
		i++;
	}
	while ( isspace(p[j]) && p[j] )
	{
		j--;
	}
	ncount = j - i + 1;

	printf("ncount:%d\n", ncount);
	system("pause");
	return 0;
}
/*
���Խ����
ncount:6
�밴���������. . .
*/

/*
��ǿո���ַ�������
*/
int getCount16(char *str, int *pcount)
{
	char *p = str;
	int ncount = 0;
	int i, j = 0;

	if ( str == NULL || pcount == NULL )
	{
		return -1;
	}

	i = 0;
	j = strlen(p) - 1;
	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}
	while (isspace(p[j]) && p[j])
	{
		j--;
	}
	ncount = j - i + 1;
	*pcount = ncount;
	return 0;
}

int main16()
{
	char p[] = "    abcdef    ";
	int pcount = 0;
	getCount16(p, &pcount);
	printf("pcount:%d\n", pcount);

	system("pause");
	return 0;
}
/*
pcount:6
�밴���������. . .
*/