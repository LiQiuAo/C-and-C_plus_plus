#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cfg_op.h"
#define CFGNAME "f:/cfg.ini"

void menu()
{
	printf("============================\n");
	printf("1测试写配置文件\n");
	printf("2测试读配置文件\n");
	printf("0退出");
	printf("============================\n");
}

//获取配置项
int TGetCfg()
{
	int ret = 0;
	int vlen = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };

	printf("\n请键入key:");
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

//写配置项
int TWriteCfg()
{
	int ret = 0;
	char name[1024] = {0};
	char value[1024] = {0};

	printf("\n请键入key:");
	scanf("%s", name);

	printf("\n请键入value:");
	scanf("%s", value);

	ret = WriteCfgItem(CFGNAME, name, value, strlen(value));
	if ( ret != 0 )
	{
		printf("func WriteCfgItem err:%d\n", ret);
		return ret;
	}
	printf("你的输入是:%s = %s\n", name, value);
	return ret;
}

void main()
{
	int choice;
	for ( ; ; )
	{
		//显示菜单
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