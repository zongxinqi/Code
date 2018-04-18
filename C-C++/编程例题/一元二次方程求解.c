#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 1e-6  /*浮点数并非真正意义上的实数，只是存在某种范围内的近似。因此也只能用近似的方法将实数与0进行比较*/
int main()
{
    float a,b,c,disc,p,q;
	printf("Please enter the coefficients a,b,c:");
	scanf("%f,%f,%f",&a,&b,&c);
	if (fabs(a)<=EPS)  /*a=0时，输出不是二次方程*/  
	{
		printf("It is not a quadratic equation!\n");
		  exit(0); /*函数的作用是终止整个程序的执行，强制返回操作系统*/ 
		 } 
		 disc=b*b-4*a*c;/*计算判别式*/
		 p=-b/(2*a);
		 q=sqrt(fabs(disc)/(2*a));
		 if(fabs(disc)<=EPS) /*判别式等于0时，输出两相等实根*/
		 {
	     printf("x1=x2=%.2f\n",p);
		 }
		 else
		 {
		 	if(disc>EPS)  /*判别式大于0时，输出两不等实根*/
		 	{
			 printf("x1=%.2f,x2=%.2f\n",p+q,p-q);
		    }
		else
		{
			printf("x1=%.2f+%.2fi,",p,q);
			printf("x2=%.2f-%.2fi\n,",p,q);
			}
		 }
	}

