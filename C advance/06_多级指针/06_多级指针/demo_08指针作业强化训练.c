/*
�ļ����ƣ�������ֵָ��������ַ���(���ö���ָ���е������ڴ�ģ����д)
��    �ߣ�lqa
�༭ʱ�䣺20180118
*/

/*
======================================================================================================
��һ���ַ�����������������"abcdef", "acccd", "eeee", "aaaa", "e3eeeeee", "sssss"����Ҫ��дһ������(�ӿ�)��
������½����
1���Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
2���Ѷ�ά��������������Ҳ����
strchar();
�붨��һ���ӿ�(����)
Ҫ��1������ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڡ�30��
Ҫ��2����ȷʵ�ֽӿڣ�������,��ʵ�ֹ��ܡ�40��
Ҫ��3����д��ȷ�Ĳ���������30��
======================================================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
�ӿں���
*/
int  splitStr2(const char *str, char douStr, char **myp/*in*/, int *count)
{
	char *p = NULL; 
	char *pTmp = NULL;
	int tmpCount = 0;

	//1 p��pTmp��ʼ��
	p = str;
	pTmp = str;

	do
	{
		//2��������������λ�� p���� �γɲ�ֵ �������ַ���
		/*
		�﷨:
		#include <string.h>
		char *strchr( co  nst char *str, int ch );
		���ܣ���������һ��ָ��str ��ch �״γ��ֵ�λ�ã���û����str ����ch������NULL��
		*/
		p = strchr(p, douStr);
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				strncpy(myp[tmpCount], pTmp, p - pTmp);
				myp[tmpCount][p - pTmp] = '\0';//�ѵ�һ�����ݱ��C����ַ���
				tmpCount++;

				//������p��pTmp�ﵽ��һ�μ���������
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');

	*count = tmpCount;
	return 0;
}

int main12()
{
	int ret = 0, i = 0;
	char *str = "abcdef,acccd,eeee,aaaa,e3eeeeee,sssss,";
	char douStr = ',';
	char **p = NULL;//char myArray[10][30];
	int nCount;

	p = (char *)malloc(sizeof(char *) * 10);//char* array[10]
	if ( p == NULL )
	{
		return NULL;
	}
	for ( i = 0; i < 10; i++ )
	{
		p[i] = (char *)malloc(sizeof(char) * 30);//char* array[30]
	}

	ret = splitStr2(str, douStr, p, &nCount);//p = &p[0], ����p[0]��char* ����

	if (ret != 0)
	{
		printf("func splitStr() err:%d\n", ret);
		return ret;
	}
	for (i = 0; i < nCount; i++)
	{
		printf("%s \n", p[i]);
	}

	/*
	�ͷ��ڴ�
	*/
	for ( i = 0; i < 10; i++ )
	{
		free(p[i]);
	}
	free(p);

	system("pause");
	return 0;
}