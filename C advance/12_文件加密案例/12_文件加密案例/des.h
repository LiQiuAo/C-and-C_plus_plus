/*
�ļ����ƣ�des�㷨ͷ�ļ�
��    �ߣ�lqa
�༭ʱ�䣺20180127
*/

#pragma once
#ifndef _OPENDESS_H_
#define _OPENDESS_H_


#ifdef _cplusplus
extern "C" {
#endif // 

	//�û�ʹ�õ� ���ܺ���
	int DesEnc(unsigned char* pInData/*in����*/, int nInDataLen/*in����*/, unsigned char* pOutData/*out����*/, int* pOutDataLen/*out����*/);

	//�û�ʹ�õ� ���ܺ���
	int DesDec(unsigned char* pInData/*in*/, int nInDataLen/*in*/, unsigned char* pOutData/*out*/, int* pOutDataLen/*out*/);

#ifdef _cplusplus
}
#endif // _cplusplus

#endif _OPENDESS_H_
