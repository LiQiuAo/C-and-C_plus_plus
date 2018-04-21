#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cfg_op.h"
#define CFGNAME "f:/cfg.ini"

void menu()
{
	printf("============================\n");
	printf("1����д�����ļ�\n");
	printf("2���Զ������ļ�\n");
	printf("0�˳�");
	printf("============================\n");
}

//��ȡ������
int TGetCfg()
{
	int ret = 0;
	int vlen = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };

	printf("\n�����key:");
	scanf("%s", name);

	ret = GetCfgItem(CFGNAME, name, value, &vlen);
	if (ret != 0)
	{
		printf("func GetCfgItem err:%d\n", ret);
		return ret;
	}
	printf("value:%s\n", value);
	return ret;
}

//д������
int TWriteCfg()
{
	int ret = 0;
	char name[1024] = {0};
	char value[1024] = {0};

	printf("\n�����key:");
	scanf("%s", name);

	printf("\n�����value:");
	scanf("%s", value);

	ret = WriteCfgItem(CFGNAME, name, value, strlen(value));
	if ( ret != 0 )
	{
		printf("func WriteCfgItem err:%d\n", ret);
		return ret;
	}
	printf("���������:%s = %s\n", name, value);
	return ret;
}

void main()
{
	int choice;
	for ( ; ; )
	{
		//��ʾ�˵�
		menu();
		scanf("%d", &choice);
		switch ( choice )
		{
		case 1:
			TWriteCfg();
			break;
		case 2:
			TGetCfg();
			break;
		case 0:
			exit(0);
		default:
			exit(0);
		}
	}
	system("pause");
}