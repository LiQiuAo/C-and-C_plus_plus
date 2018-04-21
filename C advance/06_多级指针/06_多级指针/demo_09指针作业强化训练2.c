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
#define END NULL

/*
�ӿں���
*/
char**  splitStr3(const char *str, char douStr, int *count)
{
	char *p = NULL;
	char *pTmp = NULL;
	int tmpCount = 0;
	char **myp = NULL;

	//1 p��pTmp��ʼ��
	p = str;
	pTmp = str;

	do
	{
		//2��������������λ�� p���� �γɲ�ֵ ������ö��ŵĸ���
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
				tmpCount++;//�����м�������

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

	//���ݶ����У���ȷ�ķ����ڴ�
	myp = (char **)malloc((sizeof(char *) * tmpCount));//�൱��char** array[4*tmpCount]
	if ( myp == NULL )
	{
		return NULL;
	}
	////////////////////////////////////////////////////////////////////////

	//1 p��pTmp��ʼ��
	//֮������ͷ���ַ���
	p = str;
	pTmp = str;
	tmpCount = 0;
	do
	{
		p = strchr(p, douStr);
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				int len = p - pTmp + 1;
				myp[tmpCount] = (char *)malloc(sizeof(char) * len);//�൱��char* array[len]
				if ( myp[tmpCount] == NULL )
				{
					return NULL;
				}
				strncpy(myp[tmpCount], pTmp, p - pTmp);
				myp[tmpCount][p-pTmp] = '\0';
				tmpCount++;
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while ( *p != '\0' );
	return myp;
}

/*
�ͷ��ڴ溯��
*/
void FreeMem2(char **myp, int cout)
{
	int i = 0;
	if (myp == NULL)
	{
		return ;
	}
	for (i = 0; i < cout; i++)//�ͷ��ڴ�
	{
		if (myp[i] != NULL)
		{
			free(myp[i]);
		}
	}
	if (myp != NULL)
	{
		free(myp);
	}
}

/*
�ͷ��ڴ溯��������ʹ������ָ��
*/
void FreeMem3(char ***p, int cout)
{
	int i = 0;
	char** myp = NULL;
	if ( p == NULL)
	{
		return;
	}
	char** myp = *p;
	for (i = 0; i < cout; i++)//�ͷ��ڴ�
	{
		if (myp[i] != NULL)
		{
			free(myp[i]);
		}
	}
	if (myp != NULL)
	{
		free(myp);
	}
	*p = NULL;//��ʵ�ζ���ָ�룬�޸ĳ�null
}


/*
�ӿں���
*/
int  splitStr4(const char *str, char douStr, char ***myp3, int *count)
{
	char *p = NULL;
	char *pTmp = NULL;
	int tmpCount = 0;
	char **myp = NULL;
	int ret = 0;
	//1 p��pTmp��ʼ��
	p = str;
	pTmp = str;

	do
	{
		//2��������������λ�� p���� �γɲ�ֵ ������ö��ŵĸ���
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
				tmpCount++;//�����м�������

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

	//���ݶ����У���ȷ�ķ����ڴ�
	myp = (char **)malloc((sizeof(char *) * tmpCount));
	if (myp == NULL)
	{
		ret = -1;
		printf("func splitStr4() err:%d (sizeof(char *) * tmpCount))", ret);
		return ret;
	}
	/*
		#include <string.h>
		void *memset( void *buffer, int ch, size_t count );
		����: ��������ch ��buffer ��ͷ��ʼ��count ���ַ���, ������bufferָ�롣
		memset() ����Ӧ���ڽ�һ���ڴ��ʼ��Ϊĳ��ֵ�����磺
		memset( the_array, '\0', sizeof(the_array));
		���ǽ�һ����������Է������ó���ĺܱ�ݵķ�����
	*/
	memset(myp, 0, tmpCount * sizeof(char*));
	////////////////////////////////////////////////////////////////////////

	//1 p��pTmp��ʼ��
	//֮������ͷ���ַ���
	p = str;
	pTmp = str;
	tmpCount = 0;
	do
	{
		p = strchr(p, douStr);
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				int len = p - pTmp + 1;
				myp[tmpCount] = (char *)malloc(sizeof(char) * len);
				if (myp[tmpCount] == NULL)
				{
					ret = -1;
					printf("func splitStr4() err:%d (sizeof(char) * len)", ret);
					return ret;
				}
				strncpy(myp[tmpCount], pTmp, p - pTmp);
				myp[tmpCount][p - pTmp] = '\0';
				tmpCount++;
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');
	
	if ( ret != 0 )//˵��ʧ��
	{
		/*FreeMem2(myp, *count);
		myp = NULL;*/
		FreeMem3(&myp, *count);
	}
	else
	{
		*myp3 = myp;//�ɹ�
	}
	return ret;
}

int main13()
{
	int ret = 0, i = 0;
	char *str = "abcdef,acccd,"; //eeee, aaaa, e3eeeeee, sssss,�ַ�����
	char douStr = ',';
	char **p = NULL;//char myArray[10][30];
	int nCount;

	p = splitStr3(str, douStr, &nCount);
	if ( p == NULL )
	{
		ret = -1;
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
	for (i = 0; i < nCount; i++)
	{
		free(p[i]);
	}
	free(p);
	system("pause");
	return 0;
}

int main14()
{
	int ret = 0, i = 0;
	char *str = "abcdef,acccd,"; //eeee, aaaa, e3eeeeee, sssss,
	char douStr = ',';
	char **p = NULL;//char myArray[10][30];
	int nCount;

	ret = splitStr4(str, douStr, &p, &nCount);
	if ( ret != 0 )
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
	for (i = 0; i < nCount; i++)
	{
		free(p[i]);
	}
	free(p);
	system("pause");
	return 0;
}