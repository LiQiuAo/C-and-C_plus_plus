#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
���ڴ���ַ������ַ������ṩ��һ��strlen������ȡ���ȣ�
��ô�����������͵�������λ�ȡ���ǵĳ����أ�
����һ�ַ�����ʹ ��sizeof(array) / sizeof(array[0]),
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