#pragma once
/*
1.分清楚功能
2.分析出功能的输入和输出
3.兑现代码
*/

/*
接口设计理念：接口要求紧，模块要求松

*/


//写文件
int WriteCfgItem(const char* filename/*in*/, const char* key/*in*/, const char* value/*in*/);

//修改配置文件 有一个前提：调用者需要知道"mykey = keyvalue"已经存在了
int ModifyCfgItem(const char* filename, const char* key, const char* value);

//读配置文件
int GetCfgItem(const char* filename/*in*/, const char* key/*in*/, char* value/*in*/);

int GetCfgItem2(const char* filename/*in*/, const char* key/*in*/, char** value/*out*/);