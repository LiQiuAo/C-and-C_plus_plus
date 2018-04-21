#include <iostream>
#include <string>


void show(char *a, int len)
{
	for ( int i = 0; i < len; i++ )
	{
		std::cout << a[i] << std::endl;
		//printf("a[%d]:%d\n",i , a[i]);
	}
}

int main11()
{
	char a[] = { '1', '2', '3' };
	show(a, sizeof(a) / sizeof(a[0]));
	system("pause");
	return 0;
}