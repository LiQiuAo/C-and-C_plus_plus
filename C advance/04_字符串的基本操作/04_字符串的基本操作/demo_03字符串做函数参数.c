/*
�ļ����ƣ��ַ���������������
��    �ߣ�lqa
�༭ʱ�䣺20180115
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main5()
{
	char a[] = "This is TRUE";
	char b[64];

	int i;
	for ( i = 0; *(a+i) != '\0'; i++ )
	{
		*(b + i) = *(a + i);
	}
	b[i] = '\0';

	printf("a:%s \n", a);
	printf("a:%s \n", b);

	system("pause");
	return 0;
}

/*
�ַ�������
*/
void copy_str(char *from, char *to)
{
	for ( ; *from != '\0'; from++, to++ )
	{
		*to = *from;
	}
	*to = '\0';
}

/*
*������++����
++�������ȼ��ߣ���������++�Ǻ�׺
*/
void copy_str2(char *from, char *to)
{
	for (; *from != '\0'; )
	{
		*to++ = *from++;//��*to = *from,��from++��to++
	}
	*to = '\0';
}

/*
��ο��Բ����ֹ����ϡ�\0��
*/
void copy_str3(char *from, char *to)
{
	while ( (*to = *from) != '\0' )
	{
		from++;
		to++;
	}
}

/*
��һ���Ż�
*/
void copy_str4(char *from, char *to)
{
	while ( (*to++ = *from++) != '\0' )
	{
		;
	}
}

/*
�ٽ�һ���Ż�
*/
void copy_str5(char *from, char *to)
{
	while ((*to++ = *from++))
	{
		;
	}
}

/*
��Ҫ���׸ı��βε�ֵ��Ҫ����һ��������ָ����������βθ��ӹ���
*/
int copy_str6(char *from, char *to)
{
	char *tmpfrom = from;
	char *tmpto = to;
	if ( from == NULL || to == NULL )
	{
		return -1;
	}

	while ( *tmpto++ = *tmpfrom++ )
	{
		;
	}
	printf("from:%s\n", from);
}

int main/*6*/()
{
	char *from = "abcdefg";
	char buf2[100];

	copy_str(from, buf2);
	printf("buf2:%s\n", buf2);

	copy_str2(from, buf2);
	printf("buf2:%s\n", buf2);

	copy_str3(from, buf2);
	printf("buf2:%s\n", buf2);

	copy_str4(from, buf2);
	printf("buf2:%s\n", buf2);

	copy_str5(from, buf2);
	printf("buf2:%s\n", buf2);

	copy_str6(from, buf2);
	printf("buf2:%s\n", buf2);
	{
		/*
		����NULL���ܱ�����������˲��ɽ���д��
		*/
	//��������
	//	char *to = NULL;
	//  copy_str5(from, to);
	}

	system("pause");
	return 0;
}