/*
文件名称:结构体嵌套二级指针
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
	char** stuname;
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
	int j;
	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);//相当于Teacher Array[num]
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(Teacher) * num);

	//挂上内存
	for (int i = 0; i < num; i++)
	{
		char** p = NULL;

		//malloc一级指针
		tmp[i].alisname = (char *)malloc(60);

		//二级指针的第三种内存模型

		p = (char**)malloc(sizeof(char*) * 3);
		for (j = 0; j < 3; j++)
		{
			p[j] = (char*)malloc(120);
		}
		tmp[i].stuname = p;
	}

	*pT = tmp;//二级指针形参 去间接修改 实参的值
	return 0;
}

/*
释放内存函数
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
		//释放一级指针
		if (p[i].alisname != NULL)
		{
			free(p[i].alisname);
		}

		//释放二级指针
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
结构体数组，输入老师的年龄，排序
*/
int main()
{
	int ret = 0;
	int i = 0;
	//Teacher Array[3];//在栈上分配内存
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
		//scanf("%s", pArray[i].name);//向指针所指向的内存数据copy数据

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

	printf("排序之后\n");
	PrintTeacher(pArray, num);

	FreeTeacher(pArray, num);

	system("pause");
	return 0;
}

/*
测试结果：
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
排序之后
age : 21
age : 22
age : 23
请按任意键继续. .
*/