/*
�ļ����ƣ�const���β�����ʾ��
��    �ߣ�lqa
�༭ʱ�䣺20180117
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
��ָ����ڴ����ݲ��ܱ��޸ģ����Ǳ�������޸�
*/
void getmem(const char *p)
{
	p = 1;
	//p[1] = '3';//ָ����ָ����ڴ�ռ��ǳ��������ܱ��޸�
	return;
}

/*
ָ��������ܱ��޸ģ���������ָ���ڴ�ռ���Ա��޸�
*/
void getmem2(char *const p)
{
	//p = 1;//ָ������ǳ��������ܱ��޸�
	p[1] = '3';//ָ����ָ����ڴ�ռ��ǳ��������ܱ��޸�
	return;
}

/*
ָ�������ָ����ڴ�ռ䣬�����ܱ��޸�
*/
void getmem3(const char *const p)
{
	//p = 1;
	//p[1] = '3';//ָ����ָ����ڴ�ռ��ǳ��������ܱ��޸�
	
	printf("%c ", p[1]);
	return;
}

int main01()
{
	char *p1 = NULL;
	const char *p2 = NULL;
	
	p2 = 1;
	system("pause");
	return 0;
} 

int main()
{
	/*
	���ۣ�C�����е�const���εı����Ǽٵģ�C�����е�const��һ��ð�ƻ�
	*/
	const int p = 10;
	//p = 100;

	{
		int *a = &p;
		*a = 100;
		printf("a:%d\n", p);
	}
	system("pause");
	return 0;
	/*
	a:100
    �밴���������. . .
	*/
}