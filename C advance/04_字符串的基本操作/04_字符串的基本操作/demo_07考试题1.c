/*
�ļ�����:������1
��    �ߣ�LQA
�༭ʱ�䣺20180116
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
==================================================================
��Ŀ����һ���ַ�����ͷ���β����n���ո񣨡�   abcdefgdddd    ������
��ȥ��ǰ��ո񣬷���һ�����ַ�����
Ҫ��1�����Լ�����һ���ӿڣ�����������ʵ�ֹ��ܣ�70��
Ҫ��2����д����������30��
==================================================================
*/
int trimSpace(char *inbuf, char *outbuf)
{
	int ret = 0;
	if (inbuf == NULL || outbuf == NULL)
	{
		ret = -1;
		printf("func trimSpace() err %d:inbuf == NULL || outbuf == NULL\n", ret);
		return -1;
	}

	char *inbuftrim = inbuf;//�����׸ı��βε�ֵ
	char *outbuftrim = outbuf;
	while (*(inbuftrim) != '\0')
	{
		if (*(inbuftrim) == ' ')
		{
			inbuftrim++;
		}
		else
		{
			*(outbuftrim++) = *(inbuftrim++);
		}
	}
	*outbuftrim = '\0';
	outbuf = outbuftrim;
	return ret;
} 

int main12()
{
	char intbuf[] = "   abcdef   gdddd    ";
	char outbuf[128];
	trimSpace(intbuf, outbuf);
	printf("outbuf:%s\n", outbuf);

	/*
	��������
	*/
	{
		char inbuf = NULL;
		char outbuf = NULL;
		trimSpace(inbuf, outbuf);
	}

	system("pause");
	return 0;
}
/*
outbuf:abcdefgdddd
func trimSpace() err -1:inbuf == NULL || outbuf == NULL
*/