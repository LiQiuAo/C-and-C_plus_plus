/*
文件名称：字符串的做函数参数
作    者：lqa
编辑时间：20180115
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main5()
{
	char a[] = "This is TRUE";
	char b[64];

	int i;
	for ( i = 0; *(a+i) != '\0'; i++ )
	{
		*(b + i) = *(a + i);
	}
	b[i] = '\0';

	printf("a:%s \n", a);
	printf("a:%s \n", b);

	system("pause");
	return 0;
}

/*
字符串函数
*/
void copy_str(char *from, char *to)
{
	for ( ; *from != '\0'; from++, to++ )
	{
		*to = *from;
	}
	*to = '\0';
}

/*
*操作和++操作
++操作优先级高，但是由于++是后缀
*/
void copy_str2(char *from, char *to)
{
	for (; *from != '\0'; )
	{
		*to++ = *from++;//先*to = *from,再from++，to++
	}
	*to = '\0';
}

/*
如何可以不用手工加上‘\0’
*/
void copy_str3(char *from, char *to)
{
	while ( (*to = *from) != '\0' )
	{
		from++;
		to++;
	}
}

/*
进一步优化
*/
void copy_str4(char *from, char *to)
{
	while ( (*to++ = *from++) != '\0' )
	{
		;
	}
}

/*
再进一步优化
*/
void copy_str5(char *from, char *to)
{
	while ((*to++ = *from++))
	{
		;
	}
}

/*
不要轻易改变形参的值，要引入一个辅助的指针变量，把形参给接过来
*/
int copy_str6(char *from, char *to)
{
	char *tmpfrom = from;
	char *tmpto = to;
	if ( from == NULL || to == NULL )
	{
		return -1;
	}

	while ( *tmpto++ = *tmpfrom++ )
	{
		;
	}
	printf("from:%s\n", from);
}

int main/*6*/()
{
	char *from = "abcdefg";
	char buf2[100];

	copy_str(from, buf2);
	printf("buf2:%s\n", buf2);

	copy_str2(from, buf2);
	printf("buf2:%s\n", buf2);

	copy_str3(from, buf2);
	printf("buf2:%s\n", buf2);

	copy_str4(from, buf2);
	printf("buf2:%s\n", buf2);

	copy_str5(from, buf2);
	printf("buf2:%s\n", buf2);

	copy_str6(from, buf2);
	printf("buf2:%s\n", buf2);
	{
		/*
		由于NULL是受保护的区域，因此不可进行写入
		*/
	//错误案例：
	//	char *to = NULL;
	//  copy_str5(from, to);
	}

	system("pause");
	return 0;
}