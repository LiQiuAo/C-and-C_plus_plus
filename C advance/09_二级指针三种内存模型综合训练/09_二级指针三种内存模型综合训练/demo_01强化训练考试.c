/*
�ļ����ƣ�����ָ���ǿ��ѵ��
��    �ߣ�lqa
�༭ʱ�䣺20180125
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
����
*/
int Sort(char** myp1/*in*/, int num1, char(*myp2)[30], int num2, char*** myp3, int* num3)
{
	int ret = 0;
	int i = 0, j = 0;
	int tmplen = 0;
	char* tmp = NULL;
	char** p3 = NULL;
	p3 = malloc((num1 + num2) * sizeof(char*));//����װ��ָ�룬Ҫ��char*
	if (p3 == NULL)
	{
		return -1;
	}

	for ( i = 0; i < num1; i++)
	{
		tmplen = strlen(myp1[i]) + 1;
		p3[i] = (char*)malloc(sizeof(char) * tmplen);

		if (p3[i] == NULL)
		{
			return -2;
		}
		strcpy(p3[i], myp1[i]);
	}

	for ( j = 0; j < num2; j++, i++)
	{
		tmplen = strlen(myp2[j]) + 1;
		p3[i] = (char*)malloc(sizeof(char) * tmplen);//�ô��ľֲ�����i�Ѿ���Ϊ3

		if (p3[i] == NULL)
		{
			return -3;
		}
		strcpy(p3[i], myp2[j]);
	}

	tmplen = num1 + num2;
	//����
	for ( i = 0; i < tmplen; i++ )
	{
		for ( j = i+1; j < tmplen; j++ )
		{
			if ( strcmp(p3[i], p3[j]) > 0 )
			{
				tmp = p3[i];
				p3[i] = p3[j];
				p3[j] = tmp;
			}
		}
	}
	//��Ӹ�ֵ
	*num3 = tmplen;
	*myp3 = p3;

	return ret;
}

/*
�ͷ��ڴ�
*/
void sortFree01 (char** p, int len)
{
	int i = 0;
	if ( p == NULL )
	{
		return;
	}
	for ( i = 0; i < len; i++ )
	{
		free(p[i]);//p[i]�ȼ���*(p+i)
	}
	free(p);
}

/*
�ͷ��ڴ�
�Ѷ���ָ��ָ���ά�ڴ��ͷŵ���ͬʱ����޸���ʵ�ε�ֵ
*�ž���һ��Կ�״�һ����
*/
void sortFree02(char*** myp, int len)
{
	int i = 0;
	char** p = NULL;
	if ( myp == NULL )
	{
		return;
	}

	p = *myp;//��ԭ�ɶ���ָ��
	if ( p == NULL )
	{
		return;
	}

	for (i = 0; i < len; i++)
	{
		free(p[i]);//p[i]�ȼ���*(p+i)
	}
	free(p);
	*myp = NULL;//��Ӹ�ֵ��ָ����ڵ��������
}

int main()
{
	int ret = 0;
	char* p1[] = {"aaaaa", "ccccc", "bbbbb"};
	char buf2[10][30] = {"111111", "333333", "222222"};
	char** p3 = NULL;
	int len1, len2, len3;

	len1 = sizeof(p1) / sizeof(*p1);
	len2 = 3;

	ret = Sort(p1, len1, buf2, len2, &p3, &len3);
	if ( ret != 0 )
	{
		printf("func sort() err:%d\n", ret); 
	}
	for ( int i = 0; i < len3; i++ )
	{
		printf("%s\n", p3[i]);
	}
	system("pause");
	return 0;
}

/*
���Խ����
111111
222222
333333
aaaaa
bbbbb
ccccc
�밴���������. . .
*/