/*
�ļ����ƣ���ջ�����
��    �ߣ�LQA
ʱ    �䣺2018��1��14��
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
һ����Ϊ��ջ��������
*/
int main5()
{
	int a;
	int b;
	printf("&a:%d, &b:%d\n", &a, &b);

	int *c;
	int *d;
	c = (int *)malloc(sizeof(int)*10);//����10��int���͵��ڴ�ռ�
	d = (int *)malloc(sizeof(int)*10);
	printf("c:%d, d:%d\n", c, d);

	system("pause");
	return 0;
}
/*
���Խ�����Է��֣�
ջ��b�ĵ�ַ��С��a�ĵ�ַ����˵����ջ�Ŀ��ڷ��������µ�
�ѣ�d�ĵ�ַ�Ǵ���c�ĵ�ַ����˵���ѵĿ��ڷ��������ϵ�
*/