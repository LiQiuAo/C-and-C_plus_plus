/*
�ļ�����:������2
��    �ߣ�LQA
�༭ʱ�䣺20180116
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
=================================================================
��һ���ַ�����1a2b3d4z��:Ҫ��дһ������ʵ�����¹���,
����1����ż��λ�ַ���ѡ���������һ���ַ���1��valude��20�� 
����2��������λ�ַ���ѡ���������һ���ַ���2��valude 20  
����3�����ַ���1���ַ���2��ͨ���������������͸�main������ӡ�� 
����4���������ܲ���ͨ����
=================================================================
*/
int getStr1Str2(char *source/*in*/, char *buf1/*in*/, char *buf2/*in*/)
{
	int ret = 0;

	char *rece_source = source;
	char *rece_buf1 = buf1;
	char *rece_buf2 = buf2;

	if (source == NULL || buf1 == NULL ||buf2 == NULL)
	{
		ret = -1;
		printf("func getStr1Str2()err:%d source == NULL || buf1 == NULL ||buf2 == NULL\n", ret);
		return ret;
	}

	while ( *rece_source != '\0' )
	{
		//����ִ�У����ɷֱ�ȡ����ͬ����
		*(rece_buf1++) = *(rece_source++);
		*(rece_buf2++) = *(rece_source++);
	}
	*rece_buf1 = '\0';
	*rece_buf2 = '\0';
	return ret;
}

int main13()
{
	char source[] = "1a2b3d4z";
	char buf1[128];
	char buf2[128];

	getStr1Str2(source, buf1, buf2);
	printf("buf1:%s\n", buf1);
	printf("buf2:%s\n", buf2);

	/*
	��������
	*/
	{
		char source = NULL;
		char buf1 = NULL;
		char buf2 = NULL;
		getStr1Str2(source, buf1, buf2);
	}
	system("pause");
	return 0;
}
/*
���Խ����
buf1:1234
buf2:abdz
func getStr1Str2()err:-1 source == NULL || buf1 == NULL ||buf2 == NULL
*/