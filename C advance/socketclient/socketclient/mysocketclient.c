#include "stdio.h"  
#include "stdlib.h"  
#include "string.h"  
#include "itcast_comm.h"  

/*
//��̬�� �ڲ����������ͣ������ò��Գ���Ҳ�����ϲ�Ӧ��֪����
����ʵҲ�����ݷ�װ
*/
typedef struct  _SCK_HANDLE
{
	char version;
	char ip[128];
	int port;
	unsigned char *p;
	int plen;
}SCK_HANDLE;//�궨��

int ret = 0;

//------------------��һ��api�ӿ�---Begin--------------------------------//  
//�ͻ��˳�ʼ��  
ITCAST_FUNC_EXPORT(int)
 cltSocketInit(void **handle /*out*/)
{
	//��������������������Ȼ���ٲ��Զ�̬����û�д����ɹ������ɹ���Ȼ���ټ������±�д��̬�⡣  
	printf("func cltSocketInit() begin....\n");

	int ret = 0;
	SCK_HANDLE *hdl = NULL;//��helָ����ڴ�ռ丳ֵΪNULL
	hdl = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));//��hdl�����ڴ�ռ�
	if ( hdl == NULL )//�ж�hdl�Ƿ�Ϊ��
	{
		ret = -1;
		printf("func cltSocketInit() err hdl == NULL:%d\n", ret);
		return ret;
	}

	/*
	����: ��������ch ��buffer ��ͷ��ʼ��count ���ַ���, 
	������bufferָ�롣 memset() ����Ӧ���ڽ�һ���ڴ��ʼ��Ϊĳ��ֵ��
	*/
	memset(hdl, 0, sizeof(SCK_HANDLE));//�䷵��ֵ��ָ�����ͣ�ע�Ⲣ����һ������ָ��

	strcpy(hdl->ip, "10.10.1.96");
	hdl->port = 80;
	*handle = hdl;

	printf("func cltSocketInit() end....\n");
	return 0; 
}
 
//�ͻ��˷�����  
ITCAST_FUNC_EXPORT(int)
cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/)
{
	int ret = 0;
	SCK_HANDLE *hdl = NULL;//��hdlָ����ڴ�ռ丳ֵΪNULL

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

	������from�и���count ���ַ���to�У�������toָ�롣 
	���to �� from �ص���������Ϊ��ȷ��.
	*/
	memcpy(hdl->p, buf, buflen);
	hdl->plen = buflen;
	return 0;
}

//�ͻ����ձ���  
ITCAST_FUNC_EXPORT(int)
cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/)
{
	int ret = 0;
	SCK_HANDLE *hdl = NULL;//��hdlָ����ڴ�ռ丳ֵΪNULL

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

//�ͻ����ͷ���Դ  
ITCAST_FUNC_EXPORT(int)
cltSocketDestory(void *handle/*in*/)
{
	int ret = 0;
	SCK_HANDLE *hdl = NULL;//��hdlָ����ڴ�ռ丳ֵΪNULL

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
//------------------��һ��api�ӿ�---End-----------------------------------//  



//------------------�ڶ���api�ӿ�---Begin--------------------------------//  
//�ͻ��˳�ʼ��  
ITCAST_FUNC_EXPORT(int)
cltSocketInit2(void **handle)
{
	return cltSocketInit(handle);
}

//�ͻ��˷�����  
ITCAST_FUNC_EXPORT(int)
cltSocketSend2(void *handle, unsigned char *buf, int buflen)
{
	return cltSocketSend(handle, buf, buflen);
}

//�ͻ����ձ���  
/*
�ͻ����ձ����õ�buf����ָ�룬����֮����ָ�ڶ�̬�������·����ڴ棬ʹ���߲��÷����ڴ�
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
	����: ��������ch ��buffer ��ͷ��ʼ��count ���ַ���,
	������bufferָ�롣 memset() ����Ӧ���ڽ�һ���ڴ��ʼ��Ϊĳ��ֵ��
	*/
	memcpy(tmp, hdl->p, hdl->plen);
	*buflen = hdl->plen;
	*buf = tmp;//��Ӹ�ֵ
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
		free(*buf);//�ͷ�һ��ָ����ָ����ڴ�ռ�
	}
	*buf = NULL;
	return 0;
}

//�ͻ����ͷ���Դ  
ITCAST_FUNC_EXPORT(int)
cltSocketDestory2(void **handle)
{
	SCK_HANDLE *tmp = NULL;
	 
	if ( handle == NULL )
	{
		return -1;
	}
	tmp = *handle;//*handle��ŵ���һ��ָ������ŵ��ڴ��ַ
	if ( tmp != NULL )
	{
		if ( tmp->p )
		{
			free(tmp->p);
			tmp->p = NULL;
		}
		free(tmp);
	}
	*handle = NULL;//*ʵ�εĵ�ַ ȥ��ӵ��޸�ʵ�ε�ֵ ���³�ʼ��ΪNULL

	return 0;
}
//------------------�ڶ���api�ӿ�---End--------------------------------//  