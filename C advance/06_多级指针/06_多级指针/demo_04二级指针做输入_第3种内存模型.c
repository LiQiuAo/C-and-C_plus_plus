/*
文件名称：二级指针做输入的第3种内存模型:程序员自己打造内存空间
作    者：lqa
编辑时间：20180117
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
	p2 = (char **)malloc(sizeof(char *) * num);//相当于buf[num]


	//申请内存
	for (i = 0; i < num; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * 100);//char buf[100]
		/*
		语法:
		#include <stdio.h>
		int sprintf( char *buffer, const char *format, ... );
		sprintf()函数和printf()类似, 只是把输出发送到buffer(缓冲区)中.返回值是写入的字符数量.
		*/
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}

	//排序之前
	printf("排序之前\n");
	//打印
	for (i = 0; i < num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//排序-交换的指针
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

	//排序-交换的内存
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

	//排序之后
	printf("排序之后\n");
	//打印
	for (i = 0; i < num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//释放内存
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
		free(p2);//先申请的后释放
	}

	system("pause");
	return 0;
}
/*
排序之前
111
222
333
444
555
排序之后
555
444
333
222
111
请按任意键继续. . .
*/

char **getMem03(int num)
{
	char **p2 = NULL;
	p2 = (char **)malloc(sizeof(char *) * num);//相当于buf[num]

	 //申请内存
	for (int i = 0; i < num; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * 100);//char buf[100]
		 /*
		 语法:
		 #include <stdio.h>
		 int sprintf( char *buffer, const char *format, ... );
		 sprintf()函数和printf()类似, 只是把输出发送到buffer(缓冲区)中.返回值是写入的字符数量.
		 */
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	return p2;
}

/*
打印
*/
void printMyArray03(char **myArray, int num)
{
	int i;
	//打印
	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}
}

/*
排序
*/
void sortMyArray03(char **myArray, int num)
{
	int i, j;
	char *tmp = NULL;
	//排序
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) < 0)
			{
				tmp = myArray[i];//注意：交换的是数组元素，也可以称交换的是指针的值
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

/*
释放内存
*/
void getMem_Free03(char **p2, int num)
{
	int i;
	//释放内存
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
		free(p2);//先申请的后释放
	}
}

int main08()
{
	char **p2 = NULL;
	char *tmp = NULL;
	int num = 5;
	p2 = getMem03(num);

	//排序之前
	printf("排序之前\n");
	//打印
	printMyArray03(p2, num);
	
	//排序
	sortMyArray03(p2, num);

	//排序之后
	printf("排序之后\n");
	//打印
	printMyArray03(p2, num);
	
	getMem_Free03(p2, num);
	system("pause");
	return 0;
}

/*
排序之前
111
222
333
444
555
排序之后
555
444
333
222
111
请按任意键继续. .
*/