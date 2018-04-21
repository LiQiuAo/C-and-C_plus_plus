#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
对于存放字符串的字符数组提供了一个strlen函数获取长度，
那么对于其他类型的数组如何获取他们的长度呢？
其中一种方法是使 用sizeof(array) / sizeof(array[0]),
*/
void show(char *a, int len)
{
	int i;
	for( i = 0; i < len; i++ )
	{
		printf("a[%d] = %d\n", i, *(a+i));
	}
} 

int main10()
{
	char a[] = { '1', '2', '3' };
	show(a, sizeof(a)/sizeof(a[0]));

	system("pause");
	return 0;
}