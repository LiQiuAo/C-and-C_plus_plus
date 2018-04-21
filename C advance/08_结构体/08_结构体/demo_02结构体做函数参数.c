/*
文件名称：结构体做函数参数
作    者：lqa
编辑时间：20180124
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
打印
*/
void PrintTeacher(Teacher* array, int num)
{
	for ( int i = 0; i < 3; i++ )
	{
		printf("age : %d \n",array[i].age);
	}
}

/*
排序
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
结构体数组，输入老师的年龄，排序
*/
int main03()
{
	int i = 0;
	Teacher Array[3];//在栈上分配内存
	int num = 3;

	for ( i = 0; i < num; i++ )
	{
		printf("\nplease enter age:");
		scanf("%d", &(Array[i].age));
	}

	//打印老师年龄
	/*for ( i = 0; i < 3; i++ )
	{
		printf("age:%d \n", Array[i].age);
	}*/

	PrintTeacher(Array, num);
	SortTeacher(Array, num);

	printf("排序之后\n");
	PrintTeacher(Array, num);

	system("pause");
	return 0;
}

/*
堆上分配内存
*/
Teacher* CreateTeacher(int num)
{
	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);//相当于Teacher Array[num]
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;
}

/*
释放内存函数
*/
void FreeTeacher(Teacher *p)
{
	if ( p != NULL )
	{
		free(p);
	}
}

/*
结构体数组，输入老师的年龄，排序
*/
int main04()
{
	int i = 0;
	//Teacher Array[3];//在栈上分配内存
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

	printf("排序之后\n");
	PrintTeacher(pArray, num);
	
	FreeTeacher(pArray);

	system("pause");
	return 0;
}