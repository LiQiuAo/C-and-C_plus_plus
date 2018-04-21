/*
文件名称：两个赋值指针变量挖字符串(利用二级指针中第三种内存模型来写)
作    者：lqa
编辑时间：20180118
*/

/*
======================================================================================================
有一个字符串符合以下特征（"abcdef", "acccd", "eeee", "aaaa", "e3eeeeee", "sssss"），要求写一个函数(接口)，
输出以下结果：
1）以逗号分割字符串，形成二维数组，并把结果传出
2）把二维数组行数运算结果也传出
strchar();
请定义一个接口(函数)
要求1：请正确表达功能的要求，定义出接口。30分
要求2：正确实现接口（函数）,并实现功能。40分
要求3：编写正确的测试用例。30分
======================================================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define END NULL

/*
接口函数
*/
char**  splitStr3(const char *str, char douStr, int *count)
{
	char *p = NULL;
	char *pTmp = NULL;
	int tmpCount = 0;
	char **myp = NULL;

	//1 p和pTmp初始化
	p = str;
	pTmp = str;

	do
	{
		//2检索符号条件的位置 p后移 形成差值 进而求得逗号的个数
		/*
		语法:
		#include <string.h>
		char *strchr( co  nst char *str, int ch );
		功能：函数返回一个指向str 中ch 首次出现的位置，当没有在str 中找ch到返回NULL。
		*/
		p = strchr(p, douStr);
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				tmpCount++;//计算有几个逗号

				//重新让p和pTmp达到下一次检索的条件
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');

	*count = tmpCount;

	//根据多少行，精确的分配内存
	myp = (char **)malloc((sizeof(char *) * tmpCount));//相当于char** array[4*tmpCount]
	if ( myp == NULL )
	{
		return NULL;
	}
	////////////////////////////////////////////////////////////////////////

	//1 p和pTmp初始化
	//之后再两头挖字符串
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
				myp[tmpCount] = (char *)malloc(sizeof(char) * len);//相当于char* array[len]
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
释放内存函数
*/
void FreeMem2(char **myp, int cout)
{
	int i = 0;
	if (myp == NULL)
	{
		return ;
	}
	for (i = 0; i < cout; i++)//释放内存
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
释放内存函数：或者使用三级指针
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
	for (i = 0; i < cout; i++)//释放内存
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
	*p = NULL;//把实参二级指针，修改成null
}


/*
接口函数
*/
int  splitStr4(const char *str, char douStr, char ***myp3, int *count)
{
	char *p = NULL;
	char *pTmp = NULL;
	int tmpCount = 0;
	char **myp = NULL;
	int ret = 0;
	//1 p和pTmp初始化
	p = str;
	pTmp = str;

	do
	{
		//2检索符号条件的位置 p后移 形成差值 进而求得逗号的个数
		/*
		语法:
		#include <string.h>
		char *strchr( co  nst char *str, int ch );
		功能：函数返回一个指向str 中ch 首次出现的位置，当没有在str 中找ch到返回NULL。
		*/
		p = strchr(p, douStr);
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				tmpCount++;//计算有几个逗号

			//重新让p和pTmp达到下一次检索的条件
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');

	*count = tmpCount;

	//根据多少行，精确的分配内存
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
		功能: 函数拷贝ch 到buffer 从头开始的count 个字符里, 并返回buffer指针。
		memset() 可以应用在将一段内存初始化为某个值。例如：
		memset( the_array, '\0', sizeof(the_array));
		这是将一个数组的所以分量设置成零的很便捷的方法。
	*/
	memset(myp, 0, tmpCount * sizeof(char*));
	////////////////////////////////////////////////////////////////////////

	//1 p和pTmp初始化
	//之后再两头挖字符串
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
	
	if ( ret != 0 )//说明失败
	{
		/*FreeMem2(myp, *count);
		myp = NULL;*/
		FreeMem3(&myp, *count);
	}
	else
	{
		*myp3 = myp;//成功
	}
	return ret;
}

int main13()
{
	int ret = 0, i = 0;
	char *str = "abcdef,acccd,"; //eeee, aaaa, e3eeeeee, sssss,字符数组
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
	释放内存
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
	释放内存
	*/
	for (i = 0; i < nCount; i++)
	{
		free(p[i]);
	}
	free(p);
	system("pause");
	return 0;
}