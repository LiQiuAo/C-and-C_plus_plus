/*
文件名称:结构体的深copy和浅copy
作    者：lqa
编辑时间：20180125
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher
{
	char name[64];
	int age;
	char* pname2;
}Teacher;

/*
将t1拷贝到t2
编译器的=号操作，只会把指针变量的值，从from拷贝到to中，但是
不会把指针变量所指的内存空间给copy过去——这称为结构体的浅拷贝
常出现的场景是：结构体中套一个一级指针或二级指针
*/
void copyTeacher(Teacher* to, Teacher* from)
{
	*to = *from;//第一种拷贝方法(属于浅拷贝)
	//memcpy(to, from, sizeof(Teacher));//第二种拷贝方法(属于浅拷贝)

	//如果想执行深拷贝,再显式的分配内存
	to->pname2 = (char*)malloc(100);
	strcpy(to->pname2, from->pname2);
}

int main06()
{
	Teacher t1;
	Teacher t2;
	strcpy(t1.name, "name1");
	t1.pname2 = (char*)malloc(100);
	strcpy(t1.pname2, "ssss");

	//t1 copy t2
	copyTeacher(&t2, &t1);

	if ( t1.pname2 != NULL )
	{
		free(t1.pname2);
		t1.pname2 = NULL;
	}

	if (t2.pname2 != NULL)
	{
		free(t2.pname2);
		t2.pname2 = NULL;
	}

	system("pause");
	return 0;
}