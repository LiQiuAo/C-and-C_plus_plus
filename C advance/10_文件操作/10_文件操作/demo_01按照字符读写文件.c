/*
�ļ����ƣ������ַ���ȡ�ļ�
��    �ߣ�lqa
�༭���ڣ�20180125
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main01_fputc()
{
	FILE* fp = NULL;
	char* filename = "F:/2.txt";//ͳһʹ��45�ȵ���д��ʽ����Linux��Windows��ͨ��
	char a[27] = "abcdefghijklmn";
	fp = fopen(filename, "r+");

	if (fp == NULL)//���ļ�ʧ��
	{
		printf("func fopen() err\n");
		return -1;
	}
	printf("�򿪳ɹ�\n");
	for (int i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);//�����ַ���ȡ�ļ�
	}
	fclose(fp);
	return 0;
}

int main02_fgetc()
{
	FILE* fp = NULL;
	char* filename = "F:/2.txt";//ͳһʹ��45�ȵ���д��ʽ����Linux��Windows��ͨ��
	char a[27] = "abcdefghijklmn";

	/*
	#include <stdio.h>
	FILE *fopen( const char *fname, const char *mode );
	fopen()��������fname(�ļ���)ָ�����ļ�, ������һ���������ļ�����.
	�����������, fopen()����NULL. mode(��ʽ)�����ھ����ļ�����;(���� ��������,���,�ȵ�)
	*/

	fp = fopen(filename, "r+");

	if (fp == NULL)//���ļ�ʧ��
	{
		printf("func fopen() err\n");
		return -1;
	}
	printf("�򿪳ɹ�\n");

	/*
	����feof()�ڵ���������ļ������ļ�βʱ����һ������ֵ
	*/
	while (!feof(fp))//�ж��ļ��Ƿ����
	{
		/*
		fgetc()������������stream(��)�е���һ���ַ�,
		��������ļ�β���߷�������ʱ����EOF.
		*/
		char tempc = fgetc(fp);
		printf("%c", tempc);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
	return 0;
}

int main03()
{
	main01_fputc();
	main02_fgetc();

	system("pause");
	return 0;
}