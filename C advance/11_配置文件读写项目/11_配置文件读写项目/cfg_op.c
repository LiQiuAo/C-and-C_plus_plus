
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 2048

/*��ȡ������*/
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
		memset(LineBuf,0, sizeof(LineBuf));//�Ƚ��ڴ�ռ����
		fgets(LineBuf, MAXLINE, fp);
		//printf("LineBufs:%s", LineBuf);

		pTmp = strchr(LineBuf, '=');
		if ( pTmp == NULL )//û��=��
		{
			continue;//Continue���ʱ����for��while��do-while��俪ʼ��һ��ѭ����ִ�С�
		}
		pTmp = strstr(LineBuf, pKey);
		if ( pTmp == NULL )//�ж��������ǲ�����key
		{
			continue;
		}
		pTmp = pTmp + strlen(pKey);
		pTmp = strchr(pTmp, '=');//pTmpָ��'='�״γ��ֵ�λ��
		if ( pTmp == NULL )
		{
			continue;
		}
		pTmp = pTmp + 1;//pTmpָ�����һЩ�е��ַ�
		//printf("pTmp:%s", pTmp);

		//���������ַ������пո�������Ҫȥ���ո�
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
					printf("������:%s û��������values \n", pKey);
					goto End;
				}
				break;
			}
		}
		//��ȡvalue������
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
		//��ֵ
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
д������
ʵ�����̣�ѭ����ȡÿһ�У����key�������Ƿ���ڣ��������޸Ķ�Ӧvalueֵ
�������ڣ����ļ�ĩβ ��� "key = value"
�ѵ㣺����޸��ļ����е�ֵ
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

	fseek(fp, 0L, SEEK_END);//���ļ�ָ���0λ�ÿ�ʼ,�ƶ����ļ�ĩβ
	length = ftell(fp);//��ȡ�ļ�����

	fseek(fp, 0L, SEEK_SET);
	if ( length > 1024*8 )
	{
		ret = -3;
		printf("�ļ�����1024*8,nonesupport");
		goto End;
	}
	while ( !feof(fp) )
	{
		//��ÿһ��
		memset(LineBuf, 0, sizeof(LineBuf));
		pTmp = fgets(LineBuf, MAXLINE, fp);
		if ( pTmp == NULL )
		{
			break;
		}
		//key�ؼ����Ƿ��ڱ���
		pTmp = strstr(LineBuf, pKey);
		if ( pTmp == NULL )//key�ؼ��ֲ��ڱ���,copy��filebuf��
		{
			strcat(filebuf, LineBuf);
			continue;
		}
		else//key�ؼ����ڱ�����,�滻�ɵ��У���copy��filebuf��
		{
			sprintf(LineBuf, "%s = %s\n", pKey, pValue);
			strcat(filebuf, LineBuf);
			iTag = 1;
		}
	}

	//���ؼ��� ������ ��׷��
	if ( iTag == 0 )
	{
		//������Ϣ(����)����stream(��)ָ�����ļ�
		fprintf(fp, "%s = %s\n", pKey, pValue);
	}
	else//��key�ؼ��� ���� �����´����ļ�
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
