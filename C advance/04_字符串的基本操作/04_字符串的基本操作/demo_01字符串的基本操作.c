/*
�ļ����ƣ��ַ�����������
��    �ߣ�lqa
�༭ʱ�䣺20180115
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
1C�����е��ַ���������0��β���ַ���
2��C������û���ַ������ͣ�ͨ���ַ����飬��ģ���ַ���
3�ַ������ڴ���䣺���� ջ�� ȫ����
*/
//�ַ�����ĳ�ʼ��
int main1()
{
	//1ָ������
	char buf[100] = {'a', 'b', 'c', 'd'};
	/*
	char buf[2] = {'a', 'b', 'c', 'd'};//��ʼ���ĸ��������ڴ�ĸ������������
	char buf[100] = {'a', 'b', 'c', 'd'};�����buf[4]-buf[99]����0
	*/
	//��ָ������ C���������Զ������Ա ���Ԫ�ظ���
	//ע�⣺buf2[]��һ�����飬����һ����0Ϊ��β���ַ�����
	char buf2[] = { 'a', 'b', 'c', 'd' };

	printf("buf:%s\n", buf);
	printf("buf:%d\n", buf[90]);
	system("pause");
	return 0;
}

/*
���ַ�����ʼ���ַ�����
strlen()���Ȳ�����0
sizeof()�ڴ��Ĵ�С
*/
void main2()
{
	int size;
	//buf3��Ϊ�ַ�����Ӧ����5���ֽ�
	//��Ϊ�ַ���Ӧ����4���ֽ�
	char buf3[] = "abcd";
	int len = strlen(buf3);
	printf("buf3�ַ��ĳ��ȣ�%d\n", len);//buf3�ַ��ĳ��ȣ�4

	//buf3��Ϊ���飬������һ���������ͣ����ʹ̶���С�ڴ��ı���
	size = sizeof(buf3);
	printf("buf3�ַ��ĳ��ȣ�%d\n", size);//buf3�ַ��ĳ��ȣ�5
	system("pause");
	return;
}

/*
ͨ�������±��ָ��  
*/
int main3()
{
	int i;
	char *p = NULL;
	char buf4[128] = "abcdefg";

	for ( i = 0; i < strlen(buf4); i++ )
	{
		printf("%c ", buf4[i]);
	}

	p = buf4;
	for ( i = 0; i < strlen(buf4); i++ )
	{
		printf("%c ",*(p+i));
	}

	for ( i = 0; i < strlen(buf4); i++ )
	{
		printf("%c ", *(buf4 + i));
	}

	/*
	ע�⣺�ô�������Щд���������׸ı䣬��ϵ�ڴ�����
	���ı�󣬱����������ͷ��ڴ棬��Ϊbuf4��ָ����ڴ��׵�ַ�Ѿ��ı�
	*/
	{
		//buf4 = buf4 + 1;
		//buf4 = 0x11;
	}

	system("pause");
	return 0;
}
/*
[]�ı��ʣ���*p��һ���ģ�ֻ�����Ƿ��ϳ���Ա���Ķ�ϰ��
buf4��һ��ָ�룬ֻ���ĳ����� buf4��һ������ָ�룬 �ͷ�(����)�ڴ�ʱ������buf��ָ����ڴ�ռ䰲ȫ�ͷš�
*/