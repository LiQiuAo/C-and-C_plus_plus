/*
�ļ����ƣ���̬����Դ
��    �ߣ�lqa
�༭ʱ�䣺20180208
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "socketclientdll.h"

int main01()
{
	void* handle = NULL;
	int ret = 0; 
	char buf[128];/*in ��ʾ����ָ��������*/
	int buflen = 3;/*in*/
	strcpy(buf, "abcdefgh");
	char outbuf[128];/*in*/
	int outbuflen = 3;/*in*/

	//	//�ͻ��˳�ʼ��  
	//�ú������ö�̬���ӿ⣬����һ��дһ��ȥ�޸����ӿ��еĴ���
	ret = cltSocketInit(&handle);
	if ( ret != 0 )
	{ 
		printf("func cltSocketInit() err:%d\n", ret);
		return ret;
	}

	//�ͻ��˷�����  
	ret = cltSocketSend(handle/*in*/, buf/*in*/, buflen/*in*/);
	if (ret != 0)
	{
		printf("func cltSocketSend() err:%d\n", ret);
		return ret;
	}

	//�ͻ����ձ���  
	ret = cltSocketRev(handle/*in*/, outbuf/*in*/, &outbuflen/*int*/);
	if (ret != 0)
	{
		printf("func cltSocketRev() err:%d\n", ret);
		return ret;
	}

	//�ͻ����ͷ���Դ
	ret = cltSocketDestory(handle);
	if ( ret != 0 )
	{
		printf("func cltSocketDestory() err:%d\n", ret);
		return ret;
	}
	system("pause");
	return ret;
}

int main()
{
	void* handle = NULL;
	int ret = 0;
	char buf[128];/*in ��ʾ����ָ��������*/
	int buflen = 3;/*in*/
	strcpy(buf, "abcdefgh");

	/*
	���ڱ����ú��������ڴ棬����Ӧ����ָ��
	char outbuf[128];
	int outbuflen = 3;
	*/

	char *pout = NULL;
	int poutlen = 0;

	strcpy(buf, "abcdefg");

	//�ͻ��˳�ʼ��  
	ret = cltSocketInit2(&handle);

	//�ͻ��˷�����  
	ret = cltSocketSend2(handle, buf, buflen);

	//�ͻ��˽��ձ���
	ret = cltSocketRev2(handle, &pout, &poutlen);

	cltSocketRev2_Free(&pout);//����Ұָ�� ��outbuf��ָ����ڴ��ͷţ�ͬʱ��outbuf������ֵΪNULL

	ret = cltSocketRev2_Free(&pout);

	//�ͻ����ͷ���Դ  
	ret = cltSocketDestory2(&pout);

	return ret;
}