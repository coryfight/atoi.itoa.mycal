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
int power10(int num)
{
	if (num == 0)
	{
		return 1;
	} else
		return 10 * power10(num - 1);
}
int char2i(char c)
{
	if (c < '0' || c > '9')
	{
		printf("输入的字符不是数字\n");
		return -1;
	}
	return c - 0x30;
}
int myatoi(const char *str)
{
	if (str == NULL)
	{
		printf("输入的是空字符串\n");
		return -1;
	}
	int neg = 0; // 0代表是正数 -1代表是负数
	char *p = (char *)str;
	if (str[0] == '-')
	{
		neg = -1;
		p++;
	}
	int str_len = len(p);
	int len_temp = str_len;
	int value = 0;
	int i=0;
	for (; i < str_len; i++)
	{
		value += power10(len_temp - 1 - i) * char2i(p[i]);
	}
	if(0==neg)
	    return value;
	else
		return 0-value;
}
int main(int argc, char *argv[])
{
	myatoi(argv[1]);
	printf("%d\n",myatoi(argv[1]));
	return 0;
}

