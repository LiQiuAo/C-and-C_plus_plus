/*
文件名称：字符串基本操作
作    者：lqa
编辑时间：20180115
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
1C语言中的字符串，是以0结尾的字符串
2在C语言中没有字符串类型，通过字符数组，来模拟字符串
3字符串的内存分配：堆上 栈上 全局区
*/
//字符数组的初始化
int main1()
{
	//1指定长度
	char buf[100] = {'a', 'b', 'c', 'd'};
	/*
	char buf[2] = {'a', 'b', 'c', 'd'};//初始化的个数大于内存的个数，编译错误
	char buf[100] = {'a', 'b', 'c', 'd'};后面的buf[4]-buf[99]都是0
	*/
	//不指定长度 C编译器会自动帮程序员 求得元素个数
	//注意：buf2[]是一个数组，不是一个以0为结尾的字符串。
	char buf2[] = { 'a', 'b', 'c', 'd' };

	printf("buf:%s\n", buf);
	printf("buf:%d\n", buf[90]);
	system("pause");
	return 0;
}

/*
用字符串初始化字符数组
strlen()长度不包括0
sizeof()内存块的大小
*/
void main2()
{
	int size;
	//buf3作为字符数组应该是5个字节
	//作为字符串应该是4个字节
	char buf3[] = "abcd";
	int len = strlen(buf3);
	printf("buf3字符的长度：%d\n", len);//buf3字符的长度：4

	//buf3作为数组，数组是一种数据类型，本质固定大小内存块的别名
	size = sizeof(buf3);
	printf("buf3字符的长度：%d\n", size);//buf3字符的长度：5
	system("pause");
	return;
}

/*
通过数组下标和指针  
*/
int main3()
{
	int i;
	char *p = NULL;
	char buf4[128] = "abcdefg";

	for ( i = 0; i < strlen(buf4); i++ )
	{
		printf("%c ", buf4[i]);
	}

	p = buf4;
	for ( i = 0; i < strlen(buf4); i++ )
	{
		printf("%c ",*(p+i));
	}

	for ( i = 0; i < strlen(buf4); i++ )
	{
		printf("%c ", *(buf4 + i));
	}

	/*
	注意：该处不能这些写，不能轻易改变，联系内存四区
	若改变后，编译器不能释放内存，因为buf4所指向的内存首地址已经改变
	*/
	{
		//buf4 = buf4 + 1;
		//buf4 = 0x11;
	}

	system("pause");
	return 0;
}
/*
[]的本质：和*p是一样的，只不过是符合程序员的阅读习惯
buf4是一个指针，只读的常量， buf4是一个常量指针， 释放(析构)内存时，保持buf所指向的内存空间安全释放。
*/