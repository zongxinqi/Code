#include<stdio.h>
int main()
{
	int n=1,i;
	double s=0,a,m=2;
	for(i=1;i<=20;i++)
	{
	a=m/n;
	m=m+n;
	n=m-n;
	s=s+a;	
	}
	printf("%f",s);
	return 0;
}
