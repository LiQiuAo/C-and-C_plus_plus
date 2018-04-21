#include "stdio.h"  
#include "stdlib.h"  
#include "string.h"  
#include "itcast_comm.h"  

/*
//动态库 内部的数据类型，不想让测试程序（也就是上层应用知道）
这其实也是数据封装
*/
typedef struct  _SCK_HANDLE
{
	char version;
	char ip[128];
	int port;
	unsigned char *p;
	int plen;
}SCK_HANDLE;//宏定义

int ret = 0;

//------------------第一套api接口---Begin--------------------------------//  
//客户端初始化  
ITCAST_FUNC_EXPORT(int)
 cltSocketInit(void **handle /*out*/)
{
	//这里先随便输出个东西，然后再测试动态库有没有创建成功，若成功了然后再继续往下编写动态库。  
	printf("func cltSocketInit() begin....\n");

	int ret = 0;
	SCK_HANDLE *hdl = NULL;//将hel指针的内存空间赋值为NULL
	hdl = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));//给hdl分配内存空间
	if ( hdl == NULL )//判断hdl是否为空
	{
		ret = -1;
		printf("func cltSocketInit() err hdl == NULL:%d\n", ret);
		return ret;
	}

	/*
	功能: 函数拷贝ch 到buffer 从头开始的count 个字符里, 
	并返回buffer指针。 memset() 可以应用在将一段内存初始化为某个值。
	*/
	memset(hdl, 0, sizeof(SCK_HANDLE));//其返回值是指针类型，注意并不是一个函数指针

	strcpy(hdl->ip, "10.10.1.96");
	hdl->port = 80;
	*handle = hdl;

	printf("func cltSocketInit() end....\n");
	return 0; 
}
 
//客户端发报文  
ITCAST_FUNC_EXPORT(int)
cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/)
{
	int ret = 0;
	SCK_HANDLE *hdl = NULL;//将hdl指针的内存空间赋值为NULL

	if ( handle == NULL || buf == NULL || buflen == NULL )
	{
		ret = -1;
		printf("func cltSocketSend() handle == NULL || buf == NULL err:%d\n", ret);
		return ret;
	}

	hdl = (SCK_HANDLE *)handle;
	hdl->p = (unsigned char* )malloc(buflen * sizeof(unsigned char));

	if ( hdl->p == NULL )
	{
		ret = -1;
		printf("func cltSocketSend() err:%d\n", ret);
		return ret;
	}

	/*
	#include <string.h>
	void *memcpy( void *to, const void *from, size_t count );

	函数从from中复制count 个字符到to中，并返回to指针。 
	如果to 和 from 重叠，则函数行为不确定.
	*/
	memcpy(hdl->p, buf, buflen);
	hdl->plen = buflen;
	return 0;
}

//客户端收报文  
ITCAST_FUNC_EXPORT(int)
cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/)
{
	int ret = 0;
	SCK_HANDLE *hdl = NULL;//将hdl指针的内存空间赋值为NULL

	if (handle == NULL || buf == NULL || buflen == NULL)
	{
		ret = -1;
		printf("func cltSocketRev() handle == NULL || buf == NULL  || buflen == NULL err:%d\n", ret);
		return ret;
	}

	hdl = (SCK_HANDLE *)handle;
	memcpy(buf, hdl->p, hdl->plen);
	*buflen = hdl->plen;

	return ret;
}

//客户端释放资源  
ITCAST_FUNC_EXPORT(int)
cltSocketDestory(void *handle/*in*/)
{
	int ret = 0;
	SCK_HANDLE *hdl = NULL;//将hdl指针的内存空间赋值为NULL

	if ( handle == NULL )
	{
		ret = -1;
		printf("func cltSocketRev() handle == NULL || buf == NULL  || buflen == NULL err:%d\n", ret);
		return ret;
	}

	hdl = (SCK_HANDLE *)handle;

	if ( hdl->p )
	{
		free(hdl->p);
	}

	free(hdl);
	return ret; 
}
//------------------第一套api接口---End-----------------------------------//  



//------------------第二套api接口---Begin--------------------------------//  
//客户端初始化  
ITCAST_FUNC_EXPORT(int)
cltSocketInit2(void **handle)
{
	return cltSocketInit(handle);
}

//客户端发报文  
ITCAST_FUNC_EXPORT(int)
cltSocketSend2(void *handle, unsigned char *buf, int buflen)
{
	return cltSocketSend(handle, buf, buflen);
}

//客户端收报文  
/*
客户端收报文用到buf二级指针，言外之意是指在动态库中重新分配内存，使用者不用分配内存
*/
ITCAST_FUNC_EXPORT(int)
cltSocketRev2(void *handle, unsigned char **buf, int *buflen)
{
	int ret = 0;
	SCK_HANDLE *hdl = NULL;
	unsigned char *tmp = NULL;

	if ( handle == NULL || buf == NULL || buflen == NULL )
	{
		ret = -1;
		printf("func cltSocketRev2() handle == NULL || buf == NULL  || buflen == NULL err:%d\n", ret);
		return ret;
	}
	hdl = (SCK_HANDLE *)handle;
	tmp = (unsigned char *)malloc(hdl->plen);
	if ( tmp == NULL )
	{
		ret = -2;
		printf("tmp == NULL err: %d", ret);
		return ret;
	}

	/*
	功能: 函数拷贝ch 到buffer 从头开始的count 个字符里,
	并返回buffer指针。 memset() 可以应用在将一段内存初始化为某个值。
	*/
	memcpy(tmp, hdl->p, hdl->plen);
	*buflen = hdl->plen;
	*buf = tmp;//间接赋值
	return ret;
}

ITCAST_FUNC_EXPORT(int)
cltSocketRev2_Free(unsigned char **buf)
{
	if ( buf == NULL )
	{
		return -1;
	}
	if ( *buf != NULL )
	{
		free(*buf);//释放一级指针所指向的内存空间
	}
	*buf = NULL;
	return 0;
}

//客户端释放资源  
ITCAST_FUNC_EXPORT(int)
cltSocketDestory2(void **handle)
{
	SCK_HANDLE *tmp = NULL;
	 
	if ( handle == NULL )
	{
		return -1;
	}
	tmp = *handle;//*handle存放的是一级指针所存放的内存地址
	if ( tmp != NULL )
	{
		if ( tmp->p )
		{
			free(tmp->p);
			tmp->p = NULL;
		}
		free(tmp);
	}
	*handle = NULL;//*实参的地址 去间接的修改实参的值 重新初始化为NULL

	return 0;
}
//------------------第二套api接口---End--------------------------------//  