/*
�ļ����ƣ����ͷ�ָ���Ҫע������⣬����Ҳָ��
��    �ߣ�LQA
��дʱ�䣺20180114
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
Ұָ�������ԭ��
ָ�����������ָ����ڴ�ռ������������ͬ�ĸ���
�ͷ���ָ����ָ���ڴ�ռ䣬����ָ���������û�����ó�null��
����ͷŵ�ʱ��ͨ��if(p1 != null)������

���������1������ָ���ʱ���ʼ��Ϊnull 2���ͷ�ָ����ָ����ڴ�ռ�󣬰�ָ������Ϊnull
*/
int main2()
{
	char *p1 = NULL;
	p1 = (char *)malloc(100);
	if ( p1 == NULL )
	{
		return;
	}
	strcpy(p1, "12121212");
	printf("p1:%s \n", p1);

	if ( p1 != NULL )
	{
		free(p1);
		p1 = NULL;//���ͷź����Ҫ��ֵΪnull����������Ұָ�롣�����ͷŲ�������
	}

	if ( p1 != NULL )
	{
		free(p1);
	}
	system("pause");
	return 0;
}
