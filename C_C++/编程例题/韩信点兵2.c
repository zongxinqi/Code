#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x;
	for(x=1;;x++)
	{	if(x%5==1&&x%6==5&&x%7==4&&x%11==10)
	{printf("x=%d\n",x);
	exit(0);/*��׼�⺯������������ֹ���������ִ�У�ǿ�Ʒ��ز���ϵͳ */ 
	}
	}
    printf("program is over");
	return 0;
}
