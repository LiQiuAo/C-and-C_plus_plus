/*
�ļ����ƣ��ṹ��Ļ�������
��    �ߣ�lqa
�༭ʱ�䣺20180124
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//����һ���ṹ�����͡��̶���С�ڴ��ı�������û�з����ڴ�
/*
struct  Teacher
{
	char name[64];
	int age;
	int id;
};
*/

//�����ض���
typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;

/*
�����Ͷ��������3�ַ���
*/
struct  Student
{
	char name[64];
	int age;
}s1, s2;//�������͵�ͬʱ������������ڶ��ַ���

struct 
{
	char name[64];
	int age;
}s3, s4;//�������� ����������������ַ���

/*
��ʼ�����������ַ�����
1�����������Ȼ���ʼ����
���磺Teacher t3 = {"jack", 20, 1}

2���������͵�ͬʱ���������Ȼ��ֵ
struct Student2
{
	char name[64];
	int age;
}s5 = {"names", 21};

3���������ͣ����������ֵ
struct
{
	char name[64];
	int age;
}s6 = {"name", 21};
*/


int main01()
{
	struct Teacher t1;//����C���������ҷ����ڴ�

	//�ض����
	Teacher t2 = {"aaaa", 22, 02};//�����Ͷ��������һ�ַ���

	/*
	t1.�������Ǹ�ʲô�ģ���û�в����ڴ�?
	��Ѱַ����������age�����t1������ƫ����===��������CPU�н���
	ʲôʱ������ڴ����أ��ȺŸ�ֵ��ʱ������ڴ�
	*/

	t1.age = 21;

	/*
	ͨ��ָ��ķ�ʽ ���� �ڴ�ռ�
	*/
	Teacher *p = NULL;
	p = &t2;
	printf("p->age:%d \n", p->age);//-> ��Ѱַ���� ����age�����t2������ ƫ���� ������cpu�н���
	printf("p->name:%s \n", p->name);

	system("pause");
	return 0;
}

/*
�ṹ��Ԫ������������,���п����������ܳɹ�
*/
void CopyTeacher(Teacher to, Teacher from)
{
	to = from;
}

/*
�ṹ��Ԫ��������ָ��,���п������ɹ�
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

	t2 = t1;//=�Ų����£�����������Ϊ

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