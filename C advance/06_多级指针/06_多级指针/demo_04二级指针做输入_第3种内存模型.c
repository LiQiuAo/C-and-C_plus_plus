/*
�ļ����ƣ�����ָ��������ĵ�3���ڴ�ģ��:����Ա�Լ������ڴ�ռ�
��    �ߣ�lqa
�༭ʱ�䣺20180117
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main07()
{
	char i, j;
	char **p2 = NULL;
	char *tmp = NULL;
	char tmpbuf[128];
	int num = 5;
	p2 = (char **)malloc(sizeof(char *) * num);//�൱��buf[num]


	//�����ڴ�
	for (i = 0; i < num; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * 100);//char buf[100]
		/*
		�﷨:
		#include <stdio.h>
		int sprintf( char *buffer, const char *format, ... );
		sprintf()������printf()����, ֻ�ǰ�������͵�buffer(������)��.����ֵ��д����ַ�����.
		*/
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}

	//����֮ǰ
	printf("����֮ǰ\n");
	//��ӡ
	for (i = 0; i < num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//����-������ָ��
	/*
	for ( i = 0; i < num; i++ )
	{
		for ( j = i+1; j < num; j++)
		{
			if ( strcmp( p2[i], p2[j] ) < 0 )
			{
				tmp = p2[i];
				p2[i] = p2[j];
				p2[j] = tmp;
			}
		}
	}
	*/

	//����-�������ڴ�
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(p2[i], p2[j]) < 0)
			{
				strcpy(tmpbuf, p2[i]);
				strcpy(p2[i], p2[j]);
				strcpy(p2[j], tmpbuf);
			}
		}
	}

	//����֮��
	printf("����֮��\n");
	//��ӡ
	for (i = 0; i < num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//�ͷ��ڴ�
	for (i = 0; i < num; i++)
	{
		if (p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}
	if (p2 != NULL)
	{
		free(p2);//������ĺ��ͷ�
	}

	system("pause");
	return 0;
}
/*
����֮ǰ
111
222
333
444
555
����֮��
555
444
333
222
111
�밴���������. . .
*/

char **getMem03(int num)
{
	char **p2 = NULL;
	p2 = (char **)malloc(sizeof(char *) * num);//�൱��buf[num]

	 //�����ڴ�
	for (int i = 0; i < num; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * 100);//char buf[100]
		 /*
		 �﷨:
		 #include <stdio.h>
		 int sprintf( char *buffer, const char *format, ... );
		 sprintf()������printf()����, ֻ�ǰ�������͵�buffer(������)��.����ֵ��д����ַ�����.
		 */
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	return p2;
}

/*
��ӡ
*/
void printMyArray03(char **myArray, int num)
{
	int i;
	//��ӡ
	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}
}

/*
����
*/
void sortMyArray03(char **myArray, int num)
{
	int i, j;
	char *tmp = NULL;
	//����
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) < 0)
			{
				tmp = myArray[i];//ע�⣺������������Ԫ�أ�Ҳ���Գƽ�������ָ���ֵ
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

/*
�ͷ��ڴ�
*/
void getMem_Free03(char **p2, int num)
{
	int i;
	//�ͷ��ڴ�
	for (i = 0; i < num; i++)
	{
		if (p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}
	if (p2 != NULL)
	{
		free(p2);//������ĺ��ͷ�
	}
}

int main08()
{
	char **p2 = NULL;
	char *tmp = NULL;
	int num = 5;
	p2 = getMem03(num);

	//����֮ǰ
	printf("����֮ǰ\n");
	//��ӡ
	printMyArray03(p2, num);
	
	//����
	sortMyArray03(p2, num);

	//����֮��
	printf("����֮��\n");
	//��ӡ
	printMyArray03(p2, num);
	
	getMem_Free03(p2, num);
	system("pause");
	return 0;
}

/*
����֮ǰ
111
222
333
444
555
����֮��
555
444
333
222
111
�밴���������. .
*/