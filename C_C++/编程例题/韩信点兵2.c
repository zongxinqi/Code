#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x;
	for(x=1;;x++)
	{	if(x%5==1&&x%6==5&&x%7==4&&x%11==10)
	{printf("x=%d\n",x);
	exit(0);/*标准库函数，作用是终止整个程序的执行，强制返回操作系统 */ 
	}
	}
    printf("program is over");
	return 0;
}
