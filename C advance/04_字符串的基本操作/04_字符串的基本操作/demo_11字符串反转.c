/*
�ļ�����:�ַ�����ת
��    �ߣ�LQA
�༭ʱ�䣺20180116
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char g_buf[128];

int inverse(char *str1)
{
	int length = strlen(str1);
	char *p1 = str1;
	char *p2 = str1 + length - 1;

	if (str1 == NULL)
	{
		return -1;
	}

	while (p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
		p1++;
		p2--;
	}
	return 0;
}

int main17()
{
	char buf[] = "abcdefg";
	inverse(buf);
	printf("buf:%s\n", buf);
	system("pause");
	return 0;
}
/*
buf:gfedcba
�밴���������. . .
*/

/*
ͨ���ݹ鷽ʽ�������ӡ
�ݹ��ȫ�ֱ�����������Ľ������ȫ�ֱ�����
�ݹ�ͷ�ȫ�ֱ������ݹ�ָ��������������
*/
int inverse2(char *p)
{
	//�ݹ�������쳣����
	if (p == NULL)
	{
		return;
	}
	//�ݹ����������
	if (*p == '\0')
	{
		return;
	}
	//ע�⣺��ʱû��ִ�д�ӡ������ִ���˺������ã����ַ�����ÿһ����ַ��ջ
	inverse2(p + 1);
	printf("p:%c\n", *p);
	return 0;
}

int main18()
{
	char buf[] = "abcdefg";
	inverse2(buf);

	system("pause");
	return 0;
} 

/*
���Խ����
p:g
p:f
p:e
p:d
p:c
p:b
p:a
�밴���������. . .
*/

int inverse3(char *p)
{
	//�ݹ�������쳣����
	if (p == NULL)
	{
		return;
	}
	//�ݹ����������
	if (*p == '\0')
	{
		return;
	}
	//ע�⣺��ʱû��ִ�д�ӡ������ִ���˺������ã����ַ�����ÿһ����ַ��ջ
	inverse3(p + 1);
	//strcpy(g_buf, p);
	/*
  #include <string.h>
  char *strncpy( char *to, const char *from, size_t count );

  ���ܣ����ַ���from ������count���ַ����Ƶ��ַ���to�С�
  ����ַ���from �ĳ���С��count�����ಿ����'\0'������ش�����ɵ��ַ�����

	*/
	//strncpy(g_buf, p, 1);//�Ὣǰ����ַ������ǵ�
	strncat(g_buf, p, 1);
	return 0;
}

int main19()
{
	char buf[] = "abcdefg";
	/*
	#include <string.h>
	void *memset( void *buffer, int ch, size_t count );

	����: ��������ch ��buffer ��ͷ��ʼ��count���ַ���, ������bufferָ�롣
	memset() ����Ӧ���ڽ�һ���ڴ��ʼ��Ϊĳ��ֵ�����磺
	memset( the_array, '\0', sizeof(the_array) );
	���ǽ�һ����������Է������ó���ĺܱ�ݵķ���
	*/
	memset(g_buf, 0, sizeof(g_buf));
	inverse3(buf);
	printf("g_buf:%s\n", g_buf);
	system("pause");
	return 0;
}
/*
������:
g_buf:gfedcba
�밴���������. . .
*/


int inverse4(char *p, char *bufresult)
{
	//�ݹ�������쳣����
	if ( p == NULL || bufresult == NULL )
	{
		return;
	}
	//�ݹ����������
	if ( *p == '\0' )
	{
		return;
	}
	inverse4(p + 1, bufresult);
	strncat(bufresult, p, 1);
	return 0;
}

int main20()
{
	char buf[] = "abcdefg";

	char mybuf[1024] = { 0 };
	inverse4(buf, mybuf);
	printf("�ݹ�ͷǾֲ�������һ��g_buf:%s\n", mybuf);

	system("pause");
	return 0;
}
/*
�ݹ�ͷǾֲ�������һ��g_buf:gfedcba
*/