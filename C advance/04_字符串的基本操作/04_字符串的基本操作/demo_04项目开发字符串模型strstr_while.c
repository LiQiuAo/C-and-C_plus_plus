/*
�ļ����ƣ���Ŀ�����ַ���ģ��
��    �ߣ�lqa
�༭ʱ�䣺20180115
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
#include <string.h>
char *strstr( const char *str1, const char *str2 );
��������һ��ָ�룬��ָ���ַ���str2 �״γ������ַ���str1�е�λ�ã�
���û���ҵ�������NULL
*/

/*
do...while()ģ��
*/
int main7()
{
	int ncount = 0;
	//��ʼ��
	char *p = "11abcd123121abcd12312abcd";

	do
	{
		p = strstr(p, "abcd");
		if ( p != NULL )
		{
			ncount++;
			p = p + strlen("abcd");//ָ��ﵽ�´β��ҵ�����
		}
		else
		{
			break;
		}
	} while ( *p != '\0' );

	printf("ncount:%d\n", ncount);
	system("pause");
	return 0;
	/*
	ncount:3
	�밴���������. .
	*/
}

/*
whileģ��
*/
int main8()
{
	int ncount = 0;
	char *p = "11abcd123121abcd12312abcd";
	while ( p = strstr(p, "abcd") )
	{
		ncount++;
		p = p + strlen("abcd");
		if ( *p == '\0' )
		{
			break;
		}
	}

	printf("ncount:%d\n", ncount);
	system("pause");
	return 0;
}

/*
char *p = "11abcd123121abcd12312abcd";
���ַ���p��abcd���ֵĴ���
1���Զ��庯���ӿڣ������������
2���Զ���ҵ������main��������ֿ�
*/
int getCount(char *mystr, char *substr, int *count)
{
	int ret = 0;
	int tmpCount = 0;
	char *p = mystr;//��Ҫ���׸ı��βε�ֵ

	/*
	Ӧ�ÿ��ǵ�����Ľ�׳��
	*/
	if (mystr == NULL || substr == NULL || count == NULL)
	{
		ret = -1;
		printf("func getCount err:%d ( mystr == NULL || substr == NULL || count == NULL )\n", ret);
		return ret;
	}
	do
	{
		p = strstr(p, substr);
		if (p != NULL)
		{
			tmpCount++;
			p = p + strlen("abcd");//ָ��ﵽ�´β��ҵ�����
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	*count = tmpCount;//��Ӹ�ֵ��ָ����ڵ��������
	return ret;
}

int main9()
{
	int count = 0;
	int ret;
	char *p = "11abcd123121abcd12312abcd";
	char sub[] = "abcd";

	ret = getCount(p, sub, &count);
	if ( ret != 0 )
	{
		printf("getCount() err:%d", ret);
		return ret;
	}
	printf("count: %d\n", count);
	system("pause");
	return ret;
}