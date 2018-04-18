#include<stdio.h>
long fact(int n);/*阶乘的函数形式*/
int main()
{int m;
long ret;
do
{printf("please input m:");
scanf("%d",&m);
ret =fact(m);
/*if(ret==0);else*//*do while的作用是判断输入的值，如果为负，则重新输入，而if（）是判断返回值，若为0，则输出
输入数据错误，为正输出结果*/
} 
while(m<0);
printf("%d!=%ld\n",m,ret);
return 0;	
}
long fact (int n)
{
	int i;
	long result=1;
	if(n<0)
	{
		printf("input data error!\n");
	}
	else
{for(i=2;i<=n;i++)
	{
		result=result*i;
	}
		return result;/*输入的m为负数时，result的结果均为初值1*/ 
	}	

}
