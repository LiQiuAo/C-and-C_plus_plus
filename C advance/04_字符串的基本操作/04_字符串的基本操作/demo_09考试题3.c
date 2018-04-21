/*
�ļ�����:������3
��    �ߣ�LQA
�༭ʱ�䣺20180116
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
ȥ���ո�
*/
int trimSpace2(char *inbuf, char *outbuf)
{
	int ret = 0;
	if (inbuf == NULL || outbuf == NULL)
	{
		ret = -1;
		printf("func trimSpace() err %d:inbuf == NULL || outbuf == NULL\n", ret);
		return ret;
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

/*
==============================================================
��ֵ�ԣ���key = value�����ַ������ڿ����о���ʹ��;
Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡ value;
Ҫ��2����д����������30��
Ҫ��3����ֵ���м������n��ո���ȥ���ո�30��  
ע�⣺��ֵ���ַ�����ʽ��������:
"key1 = value1"
"key2 =    value2     "
"key3  = value3"
"key4       = value4"
"key5  =   "
"key6  ="
"key7  =    "
==============================================================
*/
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int *valuebuflen)
{
	/*
	˼·��
	1.����key�ǲ�����ĸ����
	2.����û��=��
	3.�ڵȺź��棬ȥ���ո�
	*/
	//1
	int ret = 0;
	char *p = NULL;
	p = keyvaluebuf;//��ʼ����������ָ�����

	if (keyvaluebuf == NULL || keybuf == NULL || valuebuflen == NULL )
	{
		return -1;
	}

	/*
	 #include <string.h>
	 char *strstr( const char *str1, const char *str2 );
     ���ܣ���������һ��ָ�룬��ָ���ַ���str2 �״γ������ַ���str1�е�λ�ã����û���ҵ�������NULL��
	*/
	p = strstr(p, keybuf);
	if ( p == NULL )
	{
		return -1;
	}
	p = p + strlen(keybuf);//�ø���ָ����������´ﵽ��һ�μ���������

	//2
	p = strstr(p, "=");
	if ( p == NULL )
	{
		return -1;
	}
	p = p + strlen("=");//�ø���ָ����������´ﵽ��һ�μ���������

	//3
	ret = trimSpace2(p, valuebuf);
	if ( ret != 0 )
	{
		printf("func trimSpace() err:%d\n", ret);
	}
	return ret;
}

int main()
{
	int ret = 0;
	int buflen = 0;
	int buf[1024] = {0};

	char *keyandvalue = "key2=    value2    ";
	char *key = "key2";

	ret = getKeyByValue(keyandvalue, key, buf, &buflen);

	if ( ret != 0 )
	{
		printf("func getKeyByValue() err:%d\n", ret);
		return ret;
	}
	printf("buf:%s\n", buf);
	system("pause");
	return 0;
}
/*
buf:value2
�밴���������. . .
*/