#include<stdio.h>
#include<math.h>
int main ()
{
 float a,b,c,s,area;
 printf("input a,b,c:");
 scanf("%f,%f,%f",&a,&b,&c);
 s=(a+b+c)/2;
 area=(float)sqrt(s*(s-a)*(s-b)*(s-c));
 printf("area=%f\n",area);	
 } 
