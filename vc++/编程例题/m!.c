#include<stdio.h>
int main()
{
	int p=1,i;
	long sum=0,n;
	printf("please input n:");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{p=p*i;
	sum=sum+p;
	}
	printf("1!+2!+...+%d!=%d\n",n,sum);
	} 
