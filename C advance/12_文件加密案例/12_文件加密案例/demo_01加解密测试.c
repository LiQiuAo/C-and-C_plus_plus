#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "des.h"

int main_01()
{
	int ret = 0;
	char* plain = "0123456789abcdef";
	int plainlen = strlen(plain);
	unsigned char cryptbuf[4096] = {0};//cyrptbuf == &cryptbuf[0]
	int cryptlen = 0;
	
	//用于解密后存放的明文空间
	char plain2[4096] = {0};
	int plainlen2;

	ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);//加密
	if ( ret != 0 )
	{
		printf("func DesEnc err:%d\n", ret);
		return ret;
	}

	ret = DesDec(cryptbuf, cryptlen, plain2, &plainlen2);//解密函数
	if ( ret != 0 )
	{
		printf("func DesDec err:%d\n", ret);
		return ret;
	}

	if ( plainlen != plainlen2 )
	{
		ret = -2;
		printf("明文长度与解密后的明文长度 不同\n");
		return ret;
	}

	if ( memcmp(plain2, plain, plainlen) == 0 )//比较两个内存块的大小
	{
		printf("明文长度和解密后的明文长度 相同(ok)\n");
	}
	else
	{
		printf("明文长度和解密后的明文长度 不同(err)\n");
	}

	system("pause");
	return ret;
}