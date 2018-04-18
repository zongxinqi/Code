#include <stdio.h>
 int main()
 {
	 int a;
	 float b;
	 char c;
	 scanf("%d",&a);
	 scanf("%f",&b);
	 scanf("%*c%c",&c);
	 printf("a=%d\n",a);
	 printf("b=%f\n",b);
	 printf("c=%c\n",c);
	 return 0 ;
 } 
