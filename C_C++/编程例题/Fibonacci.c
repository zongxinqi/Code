#include<stdio.h>
long fib(int n);
int n,i,x,count;
int main()
{

	printf("input n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		count=0;
		x=fib(i);
		printf("fib(%d)=%d\n%d\n",i,x,count);
	}
	return 0;
}
long fib(int n)
{
	count++;
	if(n==1||n==2)
	return 1;
	else return (fib(n-1)+fib(n-2));
}
