#include<stdio.h>
void main()
{
	long fact(int n);
	int m;
	long p;
	printf("please input m:");
	scanf("%d",&m);
	p=fact(m);
	printf("%ld\n",p);
}
long fact(int n)
{
	long f;
	if(n<0)
	{
		printf("data error");
	}
	else if(n==0||n==1)
	f=1;
	else f=n*fact(n-1);
	return f;
}
