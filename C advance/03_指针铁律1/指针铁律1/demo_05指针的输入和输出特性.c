/*
�ļ����ƣ�ָ���������������-��ҵ�ﳣʹ�õ�
��    �ߣ�LQA
��дʱ�䣺20180115
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
ʲô��ָ������롢������ԣ�
ָ������룺��ָ������������������ڴ棬Ȼ�󴫸�����������ʹ�ã������ָ�������
ָ����������ָ�ڱ����ú����������ڴ棬�ڼ������һϵ�и��ӵĲ�����Ȼ�����������ú���ʹ�á�
*/
int getMem3(char **myp1/*out*/, int *mylen1/*out*/, char **myp2/*out*/, int *mylen2/*out*/)
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

int main()
{
	int ret = 0;

	char *p1 = NULL;
	int len1 = 0;
	char *p2 = NULL;
	int len2 = 0;

	ret = getMem3(&p1, &len1, &p2, &len2);

	if (ret != 0)
	{
		printf("error:%d\n", ret);
		return ret;
	}

	printf("p1:%s \n", p1);
	printf("p1:%s \n", p2);

	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
	system("pause");
	return ret;
}