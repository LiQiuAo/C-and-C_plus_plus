/*
下面定义了一套socket客户端发送报文接受报文的api接口
请写出这套接口api的调用方法
*/

#ifndef _INC_Demo01_H  
#define _INC_Demo01_H  

/*
extern "C"的主要作用就是为了能够正确实现C++代码调用其他C语言代码。
加上extern "C"后，会指示编译器这部分代码按C语言的进行编译，而不是C++的。
*/
#ifdef  __cplusplus  
extern "C" {
#endif  

	//------------------第一套api接口---Begin--------------------------------//  
	//客户端初始化获取handle上下  
	int cltSocketInit(void **handle /*out*/);

	//客户端发报文  
	int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/);

	//客户端收报文  
	int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/);

	//客户端释放资源  
	int cltSocketDestory(void *handle/*in*/);
	//------------------第一套api接口---End-----------------------------------//  


	//------------------第二套api接口---Begin--------------------------------//  
	//客户端初始化  
	int cltSocketInit2(void **handle);

	//客户端发报文  
	int cltSocketSend2(void *handle, unsigned char *buf, int buflen);

	//客户端收报文  
	/*
	客户端收报文用到buf二级指针，言外之意是指在动态库中重新分配内存，使用者不用分配内存
	*/
	int cltSocketRev2(void *handle, unsigned char **buf, int *buflen);
	int cltSocketRev2_Free(unsigned char **buf);

	//客户端释放资源  
	int cltSocketDestory2(void **handle);
	//------------------第二套api接口---End--------------------------------//  

#ifdef  __cplusplus  
}
#endif  

#endif  /* _INC_Demo01_H */  