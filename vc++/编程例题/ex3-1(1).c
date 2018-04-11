#include<stdio.h>
int main ()     /* 强制转换数据类型 */ 
{
	int a=12,b=3;
	float x=18.5,y=4.6;
	printf("%f\n",(float)(a*b)/2);
    printf("%d\n",(int)x%(int)y);
    
}
