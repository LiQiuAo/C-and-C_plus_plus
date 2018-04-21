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
	
	//���ڽ��ܺ��ŵ����Ŀռ�
	char plain2[4096] = {0};
	int plainlen2;

	ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);//����
	if ( ret != 0 )
	{
		printf("func DesEnc err:%d\n", ret);
		return ret;
	}

	ret = DesDec(cryptbuf, cryptlen, plain2, &plainlen2);//���ܺ���
	if ( ret != 0 )
	{
		printf("func DesDec err:%d\n", ret);
		return ret;
	}

	if ( plainlen != plainlen2 )
	{
		ret = -2;
		printf("���ĳ�������ܺ�����ĳ��� ��ͬ\n");
		return ret;
	}

	if ( memcmp(plain2, plain, plainlen) == 0 )//�Ƚ������ڴ��Ĵ�С
	{
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� ��ͬ(ok)\n");
	}
	else
	{
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� ��ͬ(err)\n");
	}

	system("pause");
	return ret;
}