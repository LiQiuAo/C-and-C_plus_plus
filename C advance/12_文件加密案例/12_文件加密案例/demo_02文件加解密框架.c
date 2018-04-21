/*
文件名称：加解密框架实现
作    者：lqa
编辑时间：20180127
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "des.h"

/*
文件加密
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
	fopen()函数打开由pfile1指定的文件，并返回一个关联该文件的流。
	如果发生错误，返回NULL
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

	//拷贝数据
	/*
	函数feof()在到达给出的文件流的文件尾时返回一个非零值
	*/
	while (!feof(fp1))
	{
		/*
		fread()读取[4096]个对象(每个对象的大小为size(大小)指定的字节数),并把他们替换到
		由buffer缓冲区指定的数组。数据来自给出的输入流。
		函数的返回值是读取的内容数量
		*/
		plainlen = fread(plain, 1, 4096, fp1);
		if ( feof(fp1) )//读完数据后判断是否文件结束
		{
			break;//如果文件结束，跳出
		}

		//加密等于4k的数据
		ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);//将文件加密
		if ( ret != 0 )
		{
			printf("func DesEnc err:%d\n", ret);
			goto End;
		}
		//如果文件大于4k
		tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
		if ( tmplen != cryptlen)
		{
			ret = -3;
			printf("写密文件失败,请检查是否磁盘已满");
			goto End;
		}
	}
	//加密小于4k的数据
	ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);
	if ( ret != 0 )
	{
		printf("func DesEnc err:%d\n", ret);
		goto End;
	}

	/*
	fwrite()函数从数组plain中写plainlen个大小为1的对象到fp2中，返回值是已写的对象的数量。
	*/
	tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
	if ( cryptlen != tmplen )
	{
		ret = -3;
		printf("写小于4k文件失败,请检查是否磁盘已满");
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

int main_enc/*加密*/()
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
函数名称：文件解密
作    者：lqa
编辑时间：20180201
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
	fopen()函数打开由pfile1指定的文件，并返回一个关联该文件的流。
	如果发生错误，返回NULL
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

	//拷贝数据
	/*
	函数feof()在到达给出的文件流的文件尾时返回一个非零值
	*/
	while ( !feof(fp1) )
	{
		/*
		fread()读取[4096]个对象(每个对象的大小为size(大小)指定的字节数),并把他们替换到
		由buffer缓冲区指定的数组。数据来自给出的输入流。
		函数的返回值是读取的内容数量。
		读取密文，得到密文的长度
		*/
		cryptlen = fread(cryptbuf, 1, 4096, fp1);
		if (feof(fp1))//读完数据后判断是否文件结束
		{
			break;//如果文件结束，跳出
		}

		//解密等于4k的数据
		ret = DesDec_raw(cryptbuf, cryptlen, plain, &plainlen);//将文件加密
		if (ret != 0)
		{
			printf("func DesDec_raw err:%d\n", ret);
			goto End;
		}
		//如果文件大于4k
		tmplen = fwrite(plain, 1, plainlen, fp2);
		if ( tmplen != plainlen )
		{
			ret = -3;
			printf("解密写文件失败,请检查是否磁盘已满");
			goto End;
		}
	}
	//解密小于4k的数据
	ret = DesDec(cryptbuf, cryptlen, plain, &plainlen);
	if ( ret != 0 )
	{
		printf("func DesDec() err:%d\n", ret);
		goto End;
	}

	/*
	fwrite()函数从数组plain中写plainlen个大小为1的对象到fp2中，返回值是已写的对象的数量。
	*/
	tmplen = fwrite(plain, 1, plainlen, fp2);
	if (plainlen != tmplen)
	{
		ret = -3;
		printf("解密时，写小于4k文件失败,请检查是否磁盘已满");
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
测试结果：func DesDec err:20
请按任意键继续. . .
*/
