/*
 * itoa.c
 *
 *  Created on: 2016年10月31日
 *      Author: zkyu
 */
/*
 * atoi.c
 *
 *  Created on: 2016年10月25日
 *      Author: zkyu
 *  note:不能用任何库函数
 */
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
int len(const char *str)
{
	if (str == NULL)
	{
		printf("输入的是空字符串\n");
		return -1;
	}
	int i = 0;
	while (*str++)
	{
		i++;
	}
	return i;
}
int reverse(char *str,int neg)
{
			char *p1=str;
			char *p2=str+len(str) - 1;
			while(p1<p2)
			{
				char temp=*p1;
				*p1=*p2;
				*p2=temp;
				p1++;
				p2--;
			}
			if(neg==0)
	           return 0;
			else
			{
				char *p2=str;
				int str_len=len(p2);
				int i=str_len;
				for(;i>=0;i--)
				{
					p2[i+1]=p2[i];
				}
				str[0]='-';
				return 0;
			}
}

const char * myitoa(int src)
{
	static char buf[1024];
	int i = 0;
	for (; i < sizeof(buf); i++)
		buf[i] = 0;
	int neg = 0; // 0代表是正数 -1代表是负数
	if (src < 0)
	{
		neg = -1;
		src=0-src;
	}
	i=0;
	while (1)
	{
		buf[i] = src % 10 + 0x30;
		i++;
		src /= 10;
		if (src == 0)
			break;
	}
	reverse(buf,neg);
	return buf;
}
int main(int argc, char *argv[])
{
	myitoa(atoi(argv[1]));
	printf("%s\n", myitoa(atoi(argv[1])));
	return 0;
}

