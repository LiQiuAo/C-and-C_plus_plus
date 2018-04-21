/*
文件名称:考试题1
作    者：LQA
编辑时间：20180116
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
==================================================================
题目：有一个字符串开头或结尾含有n个空格（”   abcdefgdddd    ”），
欲去掉前后空格，返回一个新字符串。
要求1：请自己定义一个接口（函数），并实现功能；70分
要求2：编写测试用例。30分
==================================================================
*/
int trimSpace(char *inbuf, char *outbuf)
{
	int ret = 0;
	if (inbuf == NULL || outbuf == NULL)
	{
		ret = -1;
		printf("func trimSpace() err %d:inbuf == NULL || outbuf == NULL\n", ret);
		return -1;
	}

	char *inbuftrim = inbuf;//不轻易改变形参的值
	char *outbuftrim = outbuf;
	while (*(inbuftrim) != '\0')
	{
		if (*(inbuftrim) == ' ')
		{
			inbuftrim++;
		}
		else
		{
			*(outbuftrim++) = *(inbuftrim++);
		}
	}
	*outbuftrim = '\0';
	outbuf = outbuftrim;
	return ret;
} 

int main12()
{
	char intbuf[] = "   abcdef   gdddd    ";
	char outbuf[128];
	trimSpace(intbuf, outbuf);
	printf("outbuf:%s\n", outbuf);

	/*
	测试用例
	*/
	{
		char inbuf = NULL;
		char outbuf = NULL;
		trimSpace(inbuf, outbuf);
	}

	system("pause");
	return 0;
}
/*
outbuf:abcdefgdddd
func trimSpace() err -1:inbuf == NULL || outbuf == NULL
*/