/*
�ļ����ƣ������ж�д�ļ�
��    �ߣ�lqa
�༭���ڣ�20180125
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main11_fputc()
{
	FILE* fp = NULL;
	char* filename = "F:/22.txt";//ͳһʹ��45�ȵ���д��ʽ����Linux��Windows��ͨ��
	char a[27] = "abcdefghijklmn";
	//fp = fopen(filename, "r+");//�Զ�/д��ʽ��һ���Ѵ��ڵ��ļ�
	fp = fopen(filename, "w+");//�Զ�/д��ʽ����һ���µ��ı��ļ�

	if (fp == NULL)//���ļ�ʧ��
	{
		printf("func fopen() err\n");
		return -1;
	}
	printf("�򿪳ɹ�\n");
	
	/*
	#include <stdio.h>
	int fputs( const char *str, FILE *stream );
	fputs()������str(�ַ���)ָ����ַ�д�������������. 
	�ɹ�ʱ���طǸ�ֵ, ʧ��ʱ����EOF
	*/
	fputs(a, fp);

	fclose(fp);
	return 0;
}

int main12_fgetcs()
{
	FILE* fp = NULL;
	char* filename = "F:/22.txt";//ͳһʹ��45�ȵ���д��ʽ����Linux��Windows��ͨ��
	char buf[1024];
	fp = fopen(filename, "r+");

	if ( fp == NULL )//���ļ�ʧ��
	{
		printf("func fopen() err\n");
		return -1;
	}
	printf("�򿪳ɹ�\n");

	while ( !feof(fp) )//�ж��ļ��Ƿ����
	{
		/*
		1��C������ �� һ��һ�еĿ������� ��buf��ָ���ڴ�ռ��� ���һ���C�����ַ���
		2����\nҲcopy�����ǵ�buf��
		3���ڴ��������ڴ��׵�ַ + �ڴ�ĳ��ȣ�
		*/
		char* p = fgets(buf, 1024, fp);
		if ( p == NULL )
		{
			goto END;
		}
		printf("%s", buf);
	}
	END:
	if (fp != NULL)
	{
		fclose(fp);
	}
	return 0;
}

int main13()
{
	//main11_fputc();
	main12_fgetcs();

	system("pause");
	return 0;
}
