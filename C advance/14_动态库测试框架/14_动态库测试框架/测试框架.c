/*
文件名称：动态库测试搭建
作    者：lqa
编辑时间：20180208
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "socketclientdll.h"

int main01()
{
	void* handle = NULL;
	int ret = 0; 
	char buf[128];/*in 表示函数指针做输入*/
	int buflen = 3;/*in*/
	strcpy(buf, "abcdefgh");
	char outbuf[128];/*in*/
	int outbuflen = 3;/*in*/

	//	//客户端初始化  
	//该函数利用动态链接库，可以一边写一边去修改链接库中的代码
	ret = cltSocketInit(&handle);
	if ( ret != 0 )
	{ 
		printf("func cltSocketInit() err:%d\n", ret);
		return ret;
	}

	//客户端发报文  
	ret = cltSocketSend(handle/*in*/, buf/*in*/, buflen/*in*/);
	if (ret != 0)
	{
		printf("func cltSocketSend() err:%d\n", ret);
		return ret;
	}

	//客户端收报文  
	ret = cltSocketRev(handle/*in*/, outbuf/*in*/, &outbuflen/*int*/);
	if (ret != 0)
	{
		printf("func cltSocketRev() err:%d\n", ret);
		return ret;
	}

	//客户端释放资源
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
	char buf[128];/*in 表示函数指针做输入*/
	int buflen = 3;/*in*/
	strcpy(buf, "abcdefgh");

	/*
	由于被调用函数分配内存，所以应定义指针
	char outbuf[128];
	int outbuflen = 3;
	*/

	char *pout = NULL;
	int poutlen = 0;

	strcpy(buf, "abcdefg");

	//客户端初始化  
	ret = cltSocketInit2(&handle);

	//客户端发报文  
	ret = cltSocketSend2(handle, buf, buflen);

	//客户端接收报文
	ret = cltSocketRev2(handle, &pout, &poutlen);

	cltSocketRev2_Free(&pout);//避免野指针 把outbuf所指向的内存释放，同时把outbuf变量赋值为NULL

	ret = cltSocketRev2_Free(&pout);

	//客户端释放资源  
	ret = cltSocketDestory2(&pout);

	return ret;
}