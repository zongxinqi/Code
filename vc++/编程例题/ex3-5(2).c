#include <stdio.h>
int main()    /* const常量求解 */ 
{
    const double PI=3.14159;  /*定义实型的const常量  */ 
    double  r;
  	printf("Input r:");
	scanf("%lf",&r);
    printf("c=%f\n",4*PI*r*r);
	printf("s=%f\n",4.0/3*PI*r*r*r);
}                                     /* const常量有数据类型，编译器能对其进行类型检查 */ 
