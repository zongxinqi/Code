#include<stdio.h>
int main()
{
 int a,b,max;
 printf("input a,b:");
 scanf("%d,%d",&a,&b);
max=a>b?a:b;    /*���������ʽ���������������ֵ*/ 
 printf("max=%d\n",max);
 return 0;
}
