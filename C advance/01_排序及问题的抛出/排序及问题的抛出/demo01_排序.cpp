#include <stdio.h>
#include <stdlib.h>

//void printArray(int a[], int len)
void printArray(int *a, int len)
{
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);
	}
}
//void sortArray(int a[], int len)
void sortArray(int *a, int len)
{
	/*
	���ۣ���סһ������i���䣬������һ������j���б仯����һ�����ν���
	*/
	int i = 0, j = 0, tem = 0;
	for (i = 0; i < len; ++i)//���ѭ������i=0ʱ��j��1....N���б仯
	{
		for (j = i + 1; j < len; ++j)//�ڲ�ѭ����a[i] ��a[j]���бȽ�
		{
			if (a[i] > a[j])
			{
				tem = a[i];
				a[i] = a[j];
				a[j] = tem;
			}
		}
	}
}
/*�����������������˻����⣬�˻�Ϊһ��ָ��
1.���ۣ���������ڴ��׵�ַ���������Ч���ȴ��������ú���
2.ʵ�ε�a���βε�a���������ͱ��ʲ�һ��
  �β��е����飬���������������ָ�봦��
3.�β�д�ں����ϣ���д�ں�������һ���ģ�ֻ����ӵ�ж�������ԡ�
*/
int main(void)
{
	int a[] = {0, 12, -5, 32, 22, 16};

	int len = sizeof(a) / sizeof(a[0]);
	printf("%d ", len);
	printf("����֮ǰ\n");
	printf("%d ", len);
	printArray(a, len);
	printf("����֮��\n");
	sortArray(a, len);
	printArray(a, len);

	system("pause");
	return 0;
}
/*
����֮ǰ
0 12 -5 32 22 16 ����֮��
-5 0 12 16 22 32 �밴���������. . .
*/