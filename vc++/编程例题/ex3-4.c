#include <stdio.h>
#include <math.h>
 int main ()
 {
  	float a,b,c,x1,x2,z;
    printf("a*x*x+b*x+c=0 input a,b,c:");
 	scanf("%f,%f,%f",&a,&b,&c);
 	z=sqrt(b*b-4*a*c);
 	x1= (-b+z)/2/a;
 	x2= (-b-z)/2/a;
 	printf("%f\n%f\n",x1,x2);
}
