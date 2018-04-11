#include <stdio.h>
#include <math.h>
#define EPS 1e-1
int main()
{
	float a,b,c;
	int flag=1;  /*置标志变量flag为非0值*/
	printf("input a,b,c:");
	scanf("%f,%f,%f",&a,&b,&c) ;
	if(a+b>c&&b+c>a&&a+c>b)
	{
		if(fabs(a-b)<=EPS||fabs(b-c)<=EPS||fabs(c-a)<=EPS)
		{
        printf("等腰")；
		flag=0;
		 }
		 if(fabs(a*a+b*b-c*c)<EPS||fabs(a*a+c*c-b*b)<=EPS||fabs(b*b+c*c-a*a)<=EPS)
		 {
		 	printf("直角")；
			flag=0; 
		 	}
		 	if(flag)  /*若标志变量flag非0，则是一般三角形*/
		 	{
			printf("一般") ；
			}
			printf("三角形\n") ;
		}
		else
		{
			printf("不是三角形\n")
		}
}
