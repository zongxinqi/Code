#include<stdio.h>
int main()
{
	int i,j,n;
	long sum=0,p;
	printf("please input n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{    p=1;/*why define it here?*/
		for(j=1;j<=i;j++)
		{
			p=p*j;/*calculate n! again*/
		}
		sum=sum+p;
	}
	printf("1!+2!+...+%d!=%ld\n",n,sum);
	return 0;
}
