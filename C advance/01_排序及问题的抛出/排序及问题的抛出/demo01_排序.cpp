#include <stdio.h>
#include <stdlib.h>

//void printArray(int a[], int len)
void printArray(int *a, int len)
{
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);
	}
}
//void sortArray(int a[], int len)
void sortArray(int *a, int len)
{
	/*
	结论：按住一个变量i不变，让另外一个变量j进行变化，下一轮依次进行
	*/
	int i = 0, j = 0, tem = 0;
	for (i = 0; i < len; ++i)//外层循环，当i=0时，j从1....N进行变化
	{
		for (j = i + 1; j < len; ++j)//内层循环：a[i] 与a[j]进行比较
		{
			if (a[i] > a[j])
			{
				tem = a[i];
				a[i] = a[j];
				a[j] = tem;
			}
		}
	}
}
/*数组做函数参数的退化问题，退化为一个指针
1.结论：把数组的内存首地址和数组的有效长度传给被调用函数
2.实参的a和形参的a的数据类型本质不一样
  形参中的数组，编译器会把它当成指针处理
3.形参写在函数上，和写在函数内是一样的，只不过拥有对外的属性。
*/
int main(void)
{
	int a[] = {0, 12, -5, 32, 22, 16};

	int len = sizeof(a) / sizeof(a[0]);
	printf("%d ", len);
	printf("排序之前\n");
	printf("%d ", len);
	printArray(a, len);
	printf("排序之后\n");
	sortArray(a, len);
	printArray(a, len);

	system("pause");
	return 0;
}
/*
排序之前
0 12 -5 32 22 16 排序之后
-5 0 12 16 22 32 请按任意键继续. . .
*/