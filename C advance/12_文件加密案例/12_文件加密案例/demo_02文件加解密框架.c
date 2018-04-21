/*
�ļ����ƣ��ӽ��ܿ��ʵ��
��    �ߣ�lqa
�༭ʱ�䣺20180127
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "des.h"

/*
�ļ�����
*/
int FileSymEnc(const char* pfile1, const char* pfile2)
{
	int ret = 0;
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	unsigned char plain[4096];
	int plainlen = 0;
	int tmplen = 0;
	unsigned char cryptbuf[4096] = { 0 };//cyrptbuf == &cryptbuf[0]
	int cryptlen = 0;

	/*
	fopen()��������pfile1ָ�����ļ���������һ���������ļ�������
	����������󣬷���NULL
	*/
	fp1 = fopen(pfile1, "rb");
	if ( fp1 == NULL )
	{
		goto End;
	}
	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
	{
		goto End;
	}

	//��������
	/*
	����feof()�ڵ���������ļ������ļ�βʱ����һ������ֵ
	*/
	while (!feof(fp1))
	{
		/*
		fread()��ȡ[4096]������(ÿ������Ĵ�СΪsize(��С)ָ�����ֽ���),���������滻��
		��buffer������ָ�������顣�������Ը�������������
		�����ķ���ֵ�Ƕ�ȡ����������
		*/
		plainlen = fread(plain, 1, 4096, fp1);
		if ( feof(fp1) )//�������ݺ��ж��Ƿ��ļ�����
		{
			break;//����ļ�����������
		}

		//���ܵ���4k������
		ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);//���ļ�����
		if ( ret != 0 )
		{
			printf("func DesEnc err:%d\n", ret);
			goto End;
		}
		//����ļ�����4k
		tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
		if ( tmplen != cryptlen)
		{
			ret = -3;
			printf("д���ļ�ʧ��,�����Ƿ��������");
			goto End;
		}
	}
	//����С��4k������
	ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);
	if ( ret != 0 )
	{
		printf("func DesEnc err:%d\n", ret);
		goto End;
	}

	/*
	fwrite()����������plain��дplainlen����СΪ1�Ķ���fp2�У�����ֵ����д�Ķ����������
	*/
	tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
	if ( cryptlen != tmplen )
	{
		ret = -3;
		printf("дС��4k�ļ�ʧ��,�����Ƿ��������");
		goto End;
	}

End:
	if ( fp1 == NULL )
	{
		fclose(fp1);
	}
	if ( fp2 == NULL )
	{
		fclose(fp2);
	}
	return 0;
}

int main_enc/*����*/()
{
	int ret = 0;
	const char* file1 = "f:/1.txt";
	const char* file2 = "f:/2.txt";

	ret = FileSymEnc(file1, file2);
	if ( ret != 0 )
	{
		printf("func FileSymEnc err\n");
		return ret;
	}
	//system("pause");
	return 0;
}

/*
�������ƣ��ļ�����
��    �ߣ�lqa
�༭ʱ�䣺20180201
*/
int FileSymDec(const char* pfile1, const char* pfile2)
{
	int ret = 0;
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	unsigned char plain[4096];
	int plainlen = 0;
	int tmplen = 0;
	unsigned char cryptbuf[4096] = { 0 };//cyrptbuf == &cryptbuf[0]
	int cryptlen = 0;

	/*
	fopen()��������pfile1ָ�����ļ���������һ���������ļ�������
	����������󣬷���NULL
	*/
	fp1 = fopen(pfile1, "rb");
	if (fp1 == NULL)
	{
		goto End;
	}
	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
	{
		goto End;
	}

	//��������
	/*
	����feof()�ڵ���������ļ������ļ�βʱ����һ������ֵ
	*/
	while ( !feof(fp1) )
	{
		/*
		fread()��ȡ[4096]������(ÿ������Ĵ�СΪsize(��С)ָ�����ֽ���),���������滻��
		��buffer������ָ�������顣�������Ը�������������
		�����ķ���ֵ�Ƕ�ȡ������������
		��ȡ���ģ��õ����ĵĳ���
		*/
		cryptlen = fread(cryptbuf, 1, 4096, fp1);
		if (feof(fp1))//�������ݺ��ж��Ƿ��ļ�����
		{
			break;//����ļ�����������
		}

		//���ܵ���4k������
		ret = DesDec_raw(cryptbuf, cryptlen, plain, &plainlen);//���ļ�����
		if (ret != 0)
		{
			printf("func DesDec_raw err:%d\n", ret);
			goto End;
		}
		//����ļ�����4k
		tmplen = fwrite(plain, 1, plainlen, fp2);
		if ( tmplen != plainlen )
		{
			ret = -3;
			printf("����д�ļ�ʧ��,�����Ƿ��������");
			goto End;
		}
	}
	//����С��4k������
	ret = DesDec(cryptbuf, cryptlen, plain, &plainlen);
	if ( ret != 0 )
	{
		printf("func DesDec() err:%d\n", ret);
		goto End;
	}

	/*
	fwrite()����������plain��дplainlen����СΪ1�Ķ���fp2�У�����ֵ����д�Ķ����������
	*/
	tmplen = fwrite(plain, 1, plainlen, fp2);
	if (plainlen != tmplen)
	{
		ret = -3;
		printf("����ʱ��дС��4k�ļ�ʧ��,�����Ƿ��������");
		goto End;
	}

End:
	if (fp1 == NULL)
	{
		fclose(fp1);
	}
	if (fp2 == NULL)
	{
		fclose(fp2);
	}
	return 0;
}

int main_dec()
{
	int ret = 0;
	const char* file1 = "f:/2.txt";
	const char* file2 = "f:/3.txt";

	ret = FileSymDec(file1, file2);
	if (ret != 0)
	{
		printf("func FileSymDnc err\n");
		return ret;
	}
}

int main()
{
	//main_enc();
	main_dec();

	system("pause");
	return 0;
}

/*
���Խ����func DesDec err:20
�밴���������. . .
*/
