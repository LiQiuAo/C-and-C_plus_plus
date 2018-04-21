/*
�ļ����ƣ��ṹ������������
��    �ߣ�lqa
�༭ʱ�䣺20180124
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;

/*
��ӡ
*/
void PrintTeacher(Teacher* array, int num)
{
	for ( int i = 0; i < 3; i++ )
	{
		printf("age : %d \n",array[i].age);
	}
}

/*
����
*/
void SortTeacher(Teacher* array, int num)
{
	Teacher tmp;
	for ( int i = 0; i < num; i++ )
	{
		for ( int j = i+1; j < num; j++ )
		{
			if ( array[i].age > array[j].age )
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}


/*
�ṹ�����飬������ʦ�����䣬����
*/
int main03()
{
	int i = 0;
	Teacher Array[3];//��ջ�Ϸ����ڴ�
	int num = 3;

	for ( i = 0; i < num; i++ )
	{
		printf("\nplease enter age:");
		scanf("%d", &(Array[i].age));
	}

	//��ӡ��ʦ����
	/*for ( i = 0; i < 3; i++ )
	{
		printf("age:%d \n", Array[i].age);
	}*/

	PrintTeacher(Array, num);
	SortTeacher(Array, num);

	printf("����֮��\n");
	PrintTeacher(Array, num);

	system("pause");
	return 0;
}

/*
���Ϸ����ڴ�
*/
Teacher* CreateTeacher(int num)
{
	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);//�൱��Teacher Array[num]
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;
}

/*
�ͷ��ڴ溯��
*/
void FreeTeacher(Teacher *p)
{
	if ( p != NULL )
	{
		free(p);
	}
}

/*
�ṹ�����飬������ʦ�����䣬����
*/
int main04()
{
	int i = 0;
	//Teacher Array[3];//��ջ�Ϸ����ڴ�
	Teacher* pArray = NULL;
	int num = 3;
	pArray = CreateTeacher(num);
	
	for (i = 0; i < num; i++)
	{
		printf("\nplease enter age:");
		scanf("%d", &(pArray[i].age));
	}

	PrintTeacher(pArray, num);
	SortTeacher(pArray, num);

	printf("����֮��\n");
	PrintTeacher(pArray, num);
	
	FreeTeacher(pArray);

	system("pause");
	return 0;
}