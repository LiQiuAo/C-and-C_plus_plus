
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 2048

/*获取配置项*/
int GetCfgItem(char* pFileName/*in*/, char* pKey/*in*/, char* pValue/*in out*/, int* pValueLen/*out*/)
{
	int ret = 0;
	FILE* fp = NULL;
	char* pTmp = NULL;
	char* pBegin = NULL;
	char* pEnd = NULL;

	char LineBuf[MAXLINE];

	fp = fopen(pFileName, "r");
	if ( fp == NULL ) 
	{
		ret = -1;
		return ret;
	}
	while ( !feof(fp) )
	{
		memset(LineBuf,0, sizeof(LineBuf));//先将内存空间清空
		fgets(LineBuf, MAXLINE, fp);
		//printf("LineBufs:%s", LineBuf);

		pTmp = strchr(LineBuf, '=');
		if ( pTmp == NULL )//没有=号
		{
			continue;//Continue语句时用于for、while、do-while语句开始下一次循环的执行。
		}
		pTmp = strstr(LineBuf, pKey);
		if ( pTmp == NULL )//判断所在行是不是有key
		{
			continue;
		}
		pTmp = pTmp + strlen(pKey);
		pTmp = strchr(pTmp, '=');//pTmp指向'='首次出现的位置
		if ( pTmp == NULL )
		{
			continue;
		}
		pTmp = pTmp + 1;//pTmp指向后面一些列的字符
		//printf("pTmp:%s", pTmp);

		//由于其后的字符可能有空格，所以需要去掉空格
		while ( 1 )
		{
			if ( *pTmp == ' ' )
			{
				pTmp++;
			}
			else
			{
				pBegin = pTmp;
				if ( *pBegin == '\n' )
				{
					printf("配置项:%s 没有配置项values \n", pKey);
					goto End;
				}
				break;
			}
		}
		//获取value结束点
		while ( 1 )
		{
			if ( (*pTmp == ' ') || (*pTmp == '\n') )
			{
				break;
			}
			else
			{
				pTmp++;
			}
		}
		pEnd = pTmp;
		//赋值
		*pValueLen = pEnd - pBegin;
		memcpy(pValue, pBegin, pEnd - pBegin);
	}
End:
	if ( fp == NULL )
	{
		fclose(fp);
	}
	return 0;
}

/*
写配置项
实现流程：循环读取每一行，检查key配置项是否存在，若存在修改对应value值
若不存在，在文件末尾 添加 "key = value"
难点：如何修改文件流中的值
*/
int WriteCfgItem(char* pFileName/*in*/, char* pKey/*in*/, char* pValue/*in*/, int pValueLen/*in*/)
{
	int ret = 0, iTag = 0, length = 0;
	FILE* fp = NULL;
	char LineBuf[MAXLINE];
	char* pTmp = NULL;
	char* pBegin = NULL;
	char* pEnd = NULL;
	char filebuf[1024*8] = {0};

	if ( pFileName == NULL || pKey == NULL || pValueLen == NULL )
	{
		ret = -1;
		printf("WriteCfgItem() err,param err \n");
		goto End;
	}

	fp = fopen(pFileName, "r+");
	if ( fp == NULL )
	{
		ret = -2;
		printf("fopen() err.\n");
	}

	if ( fp == NULL )
	{
		fp = fopen(pFileName, "w+t");
		if ( fp == NULL )
		{
			ret = -3;
			printf("fopen().err\n");
			goto End;
		}
	}

	fseek(fp, 0L, SEEK_END);//把文件指针从0位置开始,移动到文件末尾
	length = ftell(fp);//获取文件长度

	fseek(fp, 0L, SEEK_SET);
	if ( length > 1024*8 )
	{
		ret = -3;
		printf("文件超过1024*8,nonesupport");
		goto End;
	}
	while ( !feof(fp) )
	{
		//读每一行
		memset(LineBuf, 0, sizeof(LineBuf));
		pTmp = fgets(LineBuf, MAXLINE, fp);
		if ( pTmp == NULL )
		{
			break;
		}
		//key关键字是否在本行
		pTmp = strstr(LineBuf, pKey);
		if ( pTmp == NULL )//key关键字不在本行,copy到filebuf中
		{
			strcat(filebuf, LineBuf);
			continue;
		}
		else//key关键字在本行中,替换旧的行，再copy到filebuf中
		{
			sprintf(LineBuf, "%s = %s\n", pKey, pValue);
			strcat(filebuf, LineBuf);
			iTag = 1;
		}
	}

	//若关键字 不存在 则追加
	if ( iTag == 0 )
	{
		//发送信息(参数)到由stream(流)指定的文件
		fprintf(fp, "%s = %s\n", pKey, pValue);
	}
	else//若key关键字 存在 则重新创建文件
	{
		if ( fp != NULL )
		{
			fclose(fp);
			fp = NULL;
		}
		fp = fopen(pFileName, "w+t");
		if ( fp == NULL )
		{
			ret = -4;
			printf("fopen() err.\n");
			goto End;
		}
		fputs(filebuf, fp);
	}
End:
	if ( fp != NULL )
	{
		fclose(fp);
	}
	return ret;
}
