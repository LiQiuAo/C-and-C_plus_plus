#pragma once
/*
1.���������
2.���������ܵ���������
3.���ִ���
*/

/*
�ӿ��������ӿ�Ҫ�����ģ��Ҫ����

*/


//д�ļ�
int WriteCfgItem(const char* filename/*in*/, const char* key/*in*/, const char* value/*in*/);

//�޸������ļ� ��һ��ǰ�᣺��������Ҫ֪��"mykey = keyvalue"�Ѿ�������
int ModifyCfgItem(const char* filename, const char* key, const char* value);

//�������ļ�
int GetCfgItem(const char* filename/*in*/, const char* key/*in*/, char* value/*in*/);

int GetCfgItem2(const char* filename/*in*/, const char* key/*in*/, char** value/*out*/);