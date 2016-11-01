/*
 * mycal.c
 *
 *  Created on: 2016年10月25日
 *      Author: zkyu
 *  note:使用乘法的时候的参数为 mycal 2 \* 3
 */
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>

int main(int argc,char *argv[])
{
	if(argc<4)
	{
		printf("error not enough parameters .");
		return -1;
	}
	int a=atoi(argv[1]);
	char solve=argv[2][0];
	int b=atoi(argv[3]);
	switch(solve)
	{
	case '+':
		printf("%d + %d = %d\n",a,b,a+b); break;
	case '-':
		printf("%d - %d = %d\n",a,b,a-b); break;
	case '*':
		printf("%d * %d = %d\n",a,b,a*b); break;
	case '/':
	{
		if(0==b)
		{
			printf("除数不能为零\n");
			return -2;
		}
		printf("%d / %d = %d\n",a,b,a/b); break;
	}
	default : printf("没有相应的运算符号\n");
	}
	return 0;

}

