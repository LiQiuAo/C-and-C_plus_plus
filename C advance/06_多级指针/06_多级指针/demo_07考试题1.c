/*
文件名称：两个赋值指针变量挖字符串（用于训练指针的高效模型）
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

/*
接口函数
*/
int  splitStr(const char *str, char douStr, char buf[10][30], int *count)
{
	char *p = NULL;
	char *pTmp = NULL;
	int tmpCount = 0;
	
	//1 p和pTmp初始化
	p = str;
	pTmp = str;

	do
	{
	//2检索符号条件的位置 p后移 形成差值 进而挖字符串
		/*
		语法:
		#include <string.h>
		char *strchr( co  nst char *str, int ch );
		功能：函数返回一个指向str 中ch 首次出现的位置，当没有在str 中找ch到返回NULL。
		*/
		p = strchr(p, douStr);
		if ( p != NULL )
		{
			//指针运算：同类型指针相减，得到的结果是步长数，而不是字节数
			if ( p - pTmp > 0 )	
			{
				/*
				#include <string.h>
				char *strncpy( char *to, const char *from, size_t count );
				功能：将字符串from 中至多count个字符复制到字符串to中。如果字符串from 的长度小于count，
				其余部分用'\0'填补。返回处理完成的字符串。
				*/
				printf("p - ptmp = %d\n", p-pTmp);
				strncpy(buf[tmpCount], pTmp, p-pTmp);
				buf[tmpCount][p-pTmp] = '\0';//把第一行数据变成C风格字符串
				tmpCount++;

				//重新让p和pTmp达到下一次检索的条件
				pTmp = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while ( *p != '\0' );
	
	*count = tmpCount;
	return 0;
}

int main11()
{
	int ret = 0, i = 0;
	char *str = "abcdef,acccd,eeee,aaaa,e3eeeeee,sssss,";//指针数组，所有的数据成员都有指针所指向
	char douStr = ',';
	char myArray[10][30];
	int nCount;

	ret = splitStr(str, douStr, myArray, &nCount); 
	if ( ret != 0 )
	{
		printf("func splitStr() err:%d\n", ret);
		return ret;
	}
	for ( i = 0; i < nCount; i++ )
	{
		printf("%s \n", myArray[i]);
	}

	system("pause");
	return 0;
}