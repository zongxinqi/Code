#include <stdio.h>
int main ()
{
	int x,a,b,c,d,e;
	scanf("%d",&x);
	a=x%10;
	b=x/10%10;
	c=x/100%10;
	d=x/1000%10;
	e=x/10000;
	printf("a=%d\nb=%d\nc=%d\nd=%d\ne=%d\n",a,b,c,d,e);
 } 
