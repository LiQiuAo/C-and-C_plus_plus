/*
�ļ�����:�ṹ�����copy��ǳcopy
��    �ߣ�lqa
�༭ʱ�䣺20180125
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
��t1������t2
��������=�Ų�����ֻ���ָ�������ֵ����from������to�У�����
�����ָ�������ָ���ڴ�ռ��copy��ȥ�������Ϊ�ṹ���ǳ����
�����ֵĳ����ǣ��ṹ������һ��һ��ָ������ָ��
*/
void copyTeacher(Teacher* to, Teacher* from)
{
	*to = *from;//��һ�ֿ�������(����ǳ����)
	//memcpy(to, from, sizeof(Teacher));//�ڶ��ֿ�������(����ǳ����)

	//�����ִ�����,����ʽ�ķ����ڴ�
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