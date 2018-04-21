#pragma once

#ifndef _CFG_OP_H_
#define _CFG_OP_H_

#ifdef _cplusplus
extern "C"{
#endif // _cplusplus


//获取配置项
int GetCfgItem(char* pFileName/*in*/, char* Key/*in*/, char* pValue/*in out*/, int* pValueLen/*out*/);

//写配置项
int WriteCfgItem(char* pFileName/*in*/, char* pItemName/*in*/, char* pItemValue/*in*/, int itemValueLen/*in*/);

#ifdef _cplusplus
}
#endif // _cplusplus

#endif // !_CFG_OP_H_
