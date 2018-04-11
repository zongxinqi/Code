#include<stdio.h>
int main()
{
	int a,b,c,y,n=0;
	for(a=1;a<=9;a++)
	{
		for(b=0;b<=9;b++)
		{
			for(c=0;c<=9;c++)
			{y=a*100+b*10+c;
			if(a*a*a+b*b*b+c*c*c==y)
			{printf("%d\n",y);n=n+1;}/*how input the quantity of the number?*/
			}
		}
	}
	printf("%d\n",n);
	return 0;
}
