/*
文件名称：des算法头文件
作    者：lqa
编辑时间：20180127
*/

#pragma once
#ifndef _OPENDESS_H_
#define _OPENDESS_H_


#ifdef _cplusplus
extern "C" {
#endif // 

	//用户使用的 加密函数
	int DesEnc(unsigned char* pInData/*in明文*/, int nInDataLen/*in明文*/, unsigned char* pOutData/*out密文*/, int* pOutDataLen/*out密文*/);

	//用户使用的 解密函数
	int DesDec(unsigned char* pInData/*in*/, int nInDataLen/*in*/, unsigned char* pOutData/*out*/, int* pOutDataLen/*out*/);

#ifdef _cplusplus
}
#endif // _cplusplus

#endif _OPENDESS_H_
