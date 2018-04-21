/*
�ļ�����:�ṹ��Ƕ�׶���ָ��
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
	char** stuname;
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
	int j;
	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);//�൱��Teacher Array[num]
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(Teacher) * num);

	//�����ڴ�
	for (int i = 0; i < num; i++)
	{
		char** p = NULL;

		//mallocһ��ָ��
		tmp[i].alisname = (char *)malloc(60);

		//����ָ��ĵ������ڴ�ģ��

		p = (char**)malloc(sizeof(char*) * 3);
		for (j = 0; j < 3; j++)
		{
			p[j] = (char*)malloc(120);
		}
		tmp[i].stuname = p;
	}

	*pT = tmp;//����ָ���β� ȥ����޸� ʵ�ε�ֵ
	return 0;
}

/*
�ͷ��ڴ溯��
*/
void FreeTeacher(Teacher *p, int num)
{
	int j;
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < num; i++)
	{
		//�ͷ�һ��ָ��
		if (p[i].alisname != NULL)
		{
			free(p[i].alisname);
		}

		//�ͷŶ���ָ��
		if ( p[i].stuname != NULL )
		{
			char** myp = p[i].stuname;
			for ( j = 0; j < 3; j++ )
			{
				if ( myp[j] != NULL )
				{
					free(myp[j]);
				}
			}
			free(myp);
			p[i].stuname = NULL;
		}
	}
	free(p);
}

/*
�ṹ�����飬������ʦ�����䣬����
*/
int main()
{
	int ret = 0;
	int i = 0;
	//Teacher Array[3];//��ջ�Ϸ����ڴ�
	Teacher* pArray = NULL;
	int num = 3;
	ret = CreateTeacher(&pArray, num);

	if (ret != 0)
	{
		printf("func createTeacher()error:%d\n", ret);
	}

	for (i = 0; i < num; i++)
	{
		printf("\nplease enter age:");
		scanf("%d", &(pArray[i].age));

		//printf("\nplease enter name:");
		//scanf("%s", pArray[i].name);//��ָ����ָ����ڴ�����copy����

		printf("\nplease enter alias:");
		scanf("%s", pArray[i].alisname);

		for ( int j = 0; j < 3; j++ )
		{
			printf("please enter student name:");
			scanf("%s", pArray[i].stuname[j]);
		}
	}

	PrintTeacher(pArray, num);
	SortTeacher(pArray, num);

	printf("����֮��\n");
	PrintTeacher(pArray, num);

	FreeTeacher(pArray, num);

	system("pause");
	return 0;
}

/*
���Խ����
please enter student name:213

please enter age:22

please enter alias:22name
please enter student name:221
please enter student name:222
please enter student name:223

please enter age:23

please enter alias:23name
please enter student name:231
please enter student name:232
please enter student name:233
age : 21
age : 22
age : 23
����֮��
age : 21
age : 22
age : 23
�밴���������. .
*/