/*
�ļ����ƣ�ָ���������������
��    �ߣ�lqa
�༭ʱ�䣺20180117
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
ָ��������������ú��������ڴ�
ָ�������룺�����ú��������ڴ�
���ļ��е����λ��ĳ���
*/
int getMem(char **myp1/*out*/, int *mylen1/*in*/, char **myp2/*out*/, int *mylen2/*in*/)
{
	/*
	ָ��ĵ�ַ��ȻҪ��һ������ָ������
	��ϵ�ڴ������ĸ��char **myp1 = &p1;
	*myp1 = p1;
	��p1ָ����ڴ�Ĵ洢�ռ�
	*/
	char *tmp1 = NULL;
	char *tmp2 = NULL;

	tmp1 = (char *)malloc(100);
	if ( tmp1 == NULL )
	{
		return -1;
	}
	strcpy(tmp1, "abcdefg");
	*mylen1 = strlen(tmp1);
	*myp1 = tmp1;//����޸�ʵ��p1��ֵ

	tmp2 = (char *)malloc(100);
	if (tmp2 == NULL)
	{
		return -2;
	}
	strcpy(tmp2, "abcdefghijk");
	*mylen2 = strlen(tmp2);
	*myp2 = tmp2;
	return 0;
}

/*
�ͷ��ڴ�ռ�
*/
int getMem_Free(char **myp1/*in*/)
{
	/*
	if ( myp1 == NULL )
	{
		return;
	}
	free(*myp1);//�ͷ���ָ�������ָ���ڴ�ռ䣬Ҫ��ʵ���޸ĳ�null
	*myp1 = NULL;
	return 0;
	*/
	char *tmp = NULL;
	if ( myp1 == NULL )
	{
		return -1;
	}
	tmp = *myp1;
	free(tmp);
	*myp1 = NULL;
	return 0;
}

int main01()
{
	char *p1 = NULL;
	int len1 = 0;

	char *p2 = NULL;
	int len2 = 0;

	int ret = 0;

	ret = getMem(&p1, &len1, &p2, &len2);

	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	getMem_Free(&p1);
	getMem_Free(&p2);

	system("pause");
	return 0;
}

int getMem_Free2(char *myp1)
{
	if ( myp1 == NULL )
	{
		return -1;
	}

	/*
	�ô�Ϊʲô����ֱ������д��myp1 = NULL�أ�
	��Ϊ���޸ĵ����βΣ���ʵ��û���κι�ϵ
	*/
	free(myp1);
	return 0;
}

int main02()
{
	char *p1 = NULL;
	int len1 = 0;

	char *p2 = NULL;
	int len2 = 0;

	int ret = 0;

	ret = getMem(&p1, &len1, &p2, &len2);
	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	/*
	�ͷ��ڴ�ĵڶ��ַ���
	*/
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

	/*�ͷ��ڴ�ĵ�һ�ַ���*/
	getMem_Free2(p1);
	getMem_Free2(p2);

	system("pause");
	return 0;
}