/*
文件名称:结构体嵌套一级指针
作    者：lqa
编辑时间：20180125
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
打印
*/
void PrintTeacher(Teacher* array, int num)
{
	for (int i = 0; i < 3; i++)
	{
		printf("age : %d \n", array[i].age);
	}
}

/*
排序
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
堆上分配内存
*/
Teacher* CreateTeacher01(int num)
{
	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);//相当于Teacher Array[num]
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;
}

int CreateTeacher(Teacher** pT, int num)
{
	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);//相当于Teacher Array[num]
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(Teacher) * num);
	 
	//挂上内存
	for ( int i =0; i < num; i++ )
	{
		tmp[i].alisname = (char *)malloc(60);
	}

	*pT = tmp;//二级指针形参 去间接修改 实参的值
	return 0;
}

/*
释放内存函数
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
结构体数组，输入老师的年龄，排序
*/
int main05()
{
	int ret = 0;
	int i = 0;
	//Teacher Array[3];//在栈上分配内存
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
		scanf("%s", pArray[i].name);//向指针所指向的内存数据copy数据

		printf("\nplease enter alias:");
		scanf("%s", pArray[i].alisname);
	}

	PrintTeacher(pArray, num);
	SortTeacher(pArray, num);

	printf("排序之后\n");
	PrintTeacher(pArray, num);

	FreeTeacher(pArray, num);

	system("pause");
	return 0;
}