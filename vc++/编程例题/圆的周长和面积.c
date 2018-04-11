#include<stdio.h>
#define PI 3.14159              /*定义宏变量PI*/ 
int main()
{
 double r;
 printf("input r:");
 scanf("%lf",&r)	;
 printf("c=%f\n",2*PI*r);
 printf("s=%f\n",PI*r*r);
 }
