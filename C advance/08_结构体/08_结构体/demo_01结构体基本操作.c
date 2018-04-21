/*
文件名称：结构体的基本操作
作    者：lqa
编辑时间：20180124
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//定义一个结构体类型。固定大小内存块的别名，还没有分配内存
/*
struct  Teacher
{
	char name[64];
	int age;
	int id;
};
*/

//类型重定义
typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;

/*
用类型定义变量的3种方法
*/
struct  Student
{
	char name[64];
	int age;
}s1, s2;//定义类型的同时定义变量——第二种方法

struct 
{
	char name[64];
	int age;
}s3, s4;//匿名类型 定义变量——第三种方法

/*
初始化变量的三种方法：
1、定义变量，然后初始化。
例如：Teacher t3 = {"jack", 20, 1}

2、定义类型的同时定义变量，然后赋值
struct Student2
{
	char name[64];
	int age;
}s5 = {"names", 21};

3、匿名类型，定义变量后赋值
struct
{
	char name[64];
	int age;
}s6 = {"name", 21};
*/


int main01()
{
	struct Teacher t1;//告诉C编译器给我分配内存

	//重定义后
	Teacher t2 = {"aaaa", 22, 02};//用类型定义变量第一种方法

	/*
	t1.操作符是干什么的，有没有操作内存?
	是寻址操作，计算age相对于t1变量的偏移量===》计算在CPU中进行
	什么时候操作内存了呢？等号赋值的时候操作内存
	*/

	t1.age = 21;

	/*
	通过指针的方式 操作 内存空间
	*/
	Teacher *p = NULL;
	p = &t2;
	printf("p->age:%d \n", p->age);//-> 是寻址操作 计算age相对于t2变量的 偏移量 计算在cpu中进行
	printf("p->name:%s \n", p->name);

	system("pause");
	return 0;
}

/*
结构体元素做函数参数,进行拷贝，并不能成功
*/
void CopyTeacher(Teacher to, Teacher from)
{
	to = from;
}

/*
结构体元素做函数指针,进行拷贝，成功
*/
void CopyTeacher2(Teacher* to, Teacher* from)
{
	*to = *from;
}

int main02()
{
	Teacher t1 = {"jackey", 22, 01};
	Teacher t2;
	Teacher t3;
	memset(&t3, 0, sizeof(t3));

	t2 = t1;//=号操作下，编译器的行为

	printf("t2.name:%s \n", t2.name);
	printf("t2.age:%d \n", t2.age);

	CopyTeacher(t3, t1);

	printf("t3.name:%s \n", t3.name);
	printf("t3.age:%d \n", t3.age);

	CopyTeacher2(&t3, &t1);

	printf("t3.name:%s \n", t3.name);
	printf("t3.age:%d \n", t3.age);
	system("pause");
	return 0;
}