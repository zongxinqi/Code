#include<stdio.h>
int main()
{
 int a,b,max;
 printf("input a,b:");
 scanf("%d,%d",&a,&b);
max=a>b?a:b;    /*用条件表达式计算两整数的最大值*/ 
 printf("max=%d\n",max);
 return 0;
}
