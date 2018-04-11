#include <stdio.h>
#define PI 3.14159
int main ()   /*  定义宏常量计算球的表面积和体积 */
{
  double r;
  printf("input r:");
  scanf("%lf",&r);
  printf("c=%f\n",4*PI*r*r);
  printf("s=%f\n",4.0/3*PI*r*r*r);
  	
}
