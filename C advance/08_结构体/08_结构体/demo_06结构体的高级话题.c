/*
�ļ�����:�ṹ��ĸ߼�����-ƫ����
��    �ߣ�lqa
�༭ʱ�䣺20180125
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
һ���ṹ�嶨����������ṹ���еĳ�Ա �ڴ沼�� �Ͷ�������
����ͨ��age��ַȥ �� ��Ľṹ���ڴ��ַ
*/
typedef struct AdvTeacher
{
	char name[64];
	int age;
	int p;
	char* pname2;
}AdvTeacher;

void main07()
{
	AdvTeacher t1;
	AdvTeacher *p = NULL;

	{
		int offsize = (int)&(p->age);
		printf("%d\n", offsize);//��õ������ƫ����
	}


	system("pause");
}

/*
���Խ����
64
�밴���������. . .
*/

void main08()
{
	AdvTeacher t1;
	AdvTeacher *p = NULL;
	p = &t1;
	p = p + 100;

	{
		//int offsize1 = (int)&(p->age) - (int)p;
		int offsize1 = (int)&(p->age);//��ʾ����&(t1.age)
		int offsize2 = (int )&(((AdvTeacher*)0)->age); 
		printf("offsize1 = %d\n", offsize1);//��õ������ƫ����
		printf("offsize2 = %d\n", offsize2);
	}

	system("pause");
}

/*
���Խ����
64
�밴���������. . .
*/