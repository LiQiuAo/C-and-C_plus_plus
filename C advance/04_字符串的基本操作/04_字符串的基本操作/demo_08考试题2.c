/*
文件名称:考试题2
作    者：LQA
编辑时间：20180116
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
=================================================================
有一个字符串”1a2b3d4z”:要求写一个函数实现如下功能,
功能1：把偶数位字符挑选出来，组成一个字符串1。valude；20分 
功能2：把奇数位字符挑选出来，组成一个字符串2，valude 20  
功能3：把字符串1和字符串2，通过函数参数，传送给main，并打印。 
功能4：主函数能测试通过。
=================================================================
*/
int getStr1Str2(char *source/*in*/, char *buf1/*in*/, char *buf2/*in*/)
{
	int ret = 0;

	char *rece_source = source;
	char *rece_buf1 = buf1;
	char *rece_buf2 = buf2;

	if (source == NULL || buf1 == NULL ||buf2 == NULL)
	{
		ret = -1;
		printf("func getStr1Str2()err:%d source == NULL || buf1 == NULL ||buf2 == NULL\n", ret);
		return ret;
	}

	while ( *rece_source != '\0' )
	{
		//交替执行，即可分别取出不同数字
		*(rece_buf1++) = *(rece_source++);
		*(rece_buf2++) = *(rece_source++);
	}
	*rece_buf1 = '\0';
	*rece_buf2 = '\0';
	return ret;
}

int main13()
{
	char source[] = "1a2b3d4z";
	char buf1[128];
	char buf2[128];

	getStr1Str2(source, buf1, buf2);
	printf("buf1:%s\n", buf1);
	printf("buf2:%s\n", buf2);

	/*
	测试用例
	*/
	{
		char source = NULL;
		char buf1 = NULL;
		char buf2 = NULL;
		getStr1Str2(source, buf1, buf2);
	}
	system("pause");
	return 0;
}
/*
测试结果：
buf1:1234
buf2:abdz
func getStr1Str2()err:-1 source == NULL || buf1 == NULL ||buf2 == NULL
*/