/*
文件名称:字符串反转
作    者：LQA
编辑时间：20180116
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char g_buf[128];

int inverse(char *str1)
{
	int length = strlen(str1);
	char *p1 = str1;
	char *p2 = str1 + length - 1;

	if (str1 == NULL)
	{
		return -1;
	}

	while (p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
		p1++;
		p2--;
	}
	return 0;
}

int main17()
{
	char buf[] = "abcdefg";
	inverse(buf);
	printf("buf:%s\n", buf);
	system("pause");
	return 0;
}
/*
buf:gfedcba
请按任意键继续. . .
*/

/*
通过递归方式，逆向打印
递归和全局变量（把逆序的结果存入全局变量）
递归和非全局变量（递归指针做函数参数）
*/
int inverse2(char *p)
{
	//递归结束的异常条件
	if (p == NULL)
	{
		return;
	}
	//递归结束的条件
	if (*p == '\0')
	{
		return;
	}
	//注意：此时没有执行打印，而是执行了函数调用，让字符串的每一个地址入栈
	inverse2(p + 1);
	printf("p:%c\n", *p);
	return 0;
}

int main18()
{
	char buf[] = "abcdefg";
	inverse2(buf);

	system("pause");
	return 0;
} 

/*
测试结果：
p:g
p:f
p:e
p:d
p:c
p:b
p:a
请按任意键继续. . .
*/

int inverse3(char *p)
{
	//递归结束的异常条件
	if (p == NULL)
	{
		return;
	}
	//递归结束的条件
	if (*p == '\0')
	{
		return;
	}
	//注意：此时没有执行打印，而是执行了函数调用，让字符串的每一个地址入栈
	inverse3(p + 1);
	//strcpy(g_buf, p);
	/*
  #include <string.h>
  char *strncpy( char *to, const char *from, size_t count );

  功能：将字符串from 中至多count个字符复制到字符串to中。
  如果字符串from 的长度小于count，其余部分用'\0'填补。返回处理完成的字符串。

	*/
	//strncpy(g_buf, p, 1);//会将前面的字符给覆盖掉
	strncat(g_buf, p, 1);
	return 0;
}

int main19()
{
	char buf[] = "abcdefg";
	/*
	#include <string.h>
	void *memset( void *buffer, int ch, size_t count );

	功能: 函数拷贝ch 到buffer 从头开始的count个字符里, 并返回buffer指针。
	memset() 可以应用在将一段内存初始化为某个值。例如：
	memset( the_array, '\0', sizeof(the_array) );
	这是将一个数组的所以分量设置成零的很便捷的方法
	*/
	memset(g_buf, 0, sizeof(g_buf));
	inverse3(buf);
	printf("g_buf:%s\n", g_buf);
	system("pause");
	return 0;
}
/*
运算结果:
g_buf:gfedcba
请按任意键继续. . .
*/


int inverse4(char *p, char *bufresult)
{
	//递归结束的异常条件
	if ( p == NULL || bufresult == NULL )
	{
		return;
	}
	//递归结束的条件
	if ( *p == '\0' )
	{
		return;
	}
	inverse4(p + 1, bufresult);
	strncat(bufresult, p, 1);
	return 0;
}

int main20()
{
	char buf[] = "abcdefg";

	char mybuf[1024] = { 0 };
	inverse4(buf, mybuf);
	printf("递归和非局部变量在一起：g_buf:%s\n", mybuf);

	system("pause");
	return 0;
}
/*
递归和非局部变量在一起：g_buf:gfedcba
*/