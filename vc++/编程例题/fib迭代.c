#include<stdio.h>
void main()
{
	int f1=1,f2=1,f3,i,n;
	scanf("%d",&n);
	for(i=3;i<=n;i++)
	{
		f3=f1+f2;
		f1=f2;
		f2=f3;
	}
	printf("%d",f3);
}
