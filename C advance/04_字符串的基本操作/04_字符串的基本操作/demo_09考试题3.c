/*
文件名称:考试题3
作    者：LQA
编辑时间：20180116
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
去除空格
*/
int trimSpace2(char *inbuf, char *outbuf)
{
	int ret = 0;
	if (inbuf == NULL || outbuf == NULL)
	{
		ret = -1;
		printf("func trimSpace() err %d:inbuf == NULL || outbuf == NULL\n", ret);
		return ret;
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

/*
==============================================================
键值对（”key = value”）字符串，在开发中经常使用;
要求1：请自己定义一个接口，实现根据key获取 value;
要求2：编写测试用例。30分
要求3：键值对中间可能有n多空格，请去除空格30分  
注意：键值对字符串格式可能如下:
"key1 = value1"
"key2 =    value2     "
"key3  = value3"
"key4       = value4"
"key5  =   "
"key6  ="
"key7  =    "
==============================================================
*/
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int *valuebuflen)
{
	/*
	思路：
	1.查找key是不是在母串中
	2.看有没有=号
	3.在等号后面，去除空格
	*/
	//1
	int ret = 0;
	char *p = NULL;
	p = keyvaluebuf;//初始化辅助辅助指针变量

	if (keyvaluebuf == NULL || keybuf == NULL || valuebuflen == NULL )
	{
		return -1;
	}

	/*
	 #include <string.h>
	 char *strstr( const char *str1, const char *str2 );
     功能：函数返回一个指针，它指向字符串str2 首次出现于字符串str1中的位置，如果没有找到，返回NULL。
	*/
	p = strstr(p, keybuf);
	if ( p == NULL )
	{
		return -1;
	}
	p = p + strlen(keybuf);//让辅助指针变量，重新达到下一次检索的条件

	//2
	p = strstr(p, "=");
	if ( p == NULL )
	{
		return -1;
	}
	p = p + strlen("=");//让辅助指针变量，重新达到下一次检索的条件

	//3
	ret = trimSpace2(p, valuebuf);
	if ( ret != 0 )
	{
		printf("func trimSpace() err:%d\n", ret);
	}
	return ret;
}

int main()
{
	int ret = 0;
	int buflen = 0;
	int buf[1024] = {0};

	char *keyandvalue = "key2=    value2    ";
	char *key = "key2";

	ret = getKeyByValue(keyandvalue, key, buf, &buflen);

	if ( ret != 0 )
	{
		printf("func getKeyByValue() err:%d\n", ret);
		return ret;
	}
	printf("buf:%s\n", buf);
	system("pause");
	return 0;
}
/*
buf:value2
请按任意键继续. . .
*/