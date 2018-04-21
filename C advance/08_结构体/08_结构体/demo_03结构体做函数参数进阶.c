/*
�ļ�����:�ṹ��Ƕ��һ��ָ��
��    �ߣ�lqa
�༭ʱ�䣺20180125
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher
{
	char name[64];
	char* alisname;
	int age;
	int id;
}Teacher;

/*
��ӡ
*/
void PrintTeacher(Teacher* array, int num)
{
	for (int i = 0; i < 3; i++)
	{
		printf("age : %d \n", array[i].age);
	}
}

/*
����
*/
void SortTeacher(Teacher* array, int num)
{
	Teacher tmp;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (array[i].age > array[j].age)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

/*
���Ϸ����ڴ�
*/
Teacher* CreateTeacher01(int num)
{
	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);//�൱��Teacher Array[num]
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;
}

int CreateTeacher(Teacher** pT, int num)
{
	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);//�൱��Teacher Array[num]
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(Teacher) * num);
	 
	//�����ڴ�
	for ( int i =0; i < num; i++ )
	{
		tmp[i].alisname = (char *)malloc(60);
	}

	*pT = tmp;//����ָ���β� ȥ����޸� ʵ�ε�ֵ
	return 0;
}

/*
�ͷ��ڴ溯��
*/
void FreeTeacher(Teacher *p, int num)
{
	if (p == NULL)
	{
		return;
	}
	for ( int i = 0; i < num; i++ )
	{
		if ( p[i].alisname != NULL )
		{
			free(p[i].alisname);
		}
	}
	free(p);
}

/*
�ṹ�����飬������ʦ�����䣬����
*/
int main05()
{
	int ret = 0;
	int i = 0;
	//Teacher Array[3];//��ջ�Ϸ����ڴ�
	Teacher* pArray = NULL;
	int num = 3;
	ret = CreateTeacher(&pArray, num);

	if ( ret != 0 )
	{
		printf("func createTeacher()error:%d\n", ret);
	}

	for (i = 0; i < num; i++)
	{
		printf("\nplease enter age:");
		scanf("%d", &(pArray[i].age));

		printf("\nplease enter name:");
		scanf("%s", pArray[i].name);//��ָ����ָ����ڴ�����copy����

		printf("\nplease enter alias:");
		scanf("%s", pArray[i].alisname);
	}

	PrintTeacher(pArray, num);
	SortTeacher(pArray, num);

	printf("����֮��\n");
	PrintTeacher(pArray, num);

	FreeTeacher(pArray, num);

	system("pause");
	return 0;
}