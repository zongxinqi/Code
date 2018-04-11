#include<stdio.h>
#define N 12
#define MAX_LEN 20
int add(int n);
int main()
{
	int i,n,sum=0;
	char month[N][MAX_LEN]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
	char *p[N];
	for(i=0;i<12;i++)
	{
		p[i]=month[i];
	}
	scanf("%d",&n);
	sum=add(n);
	if(sum>0&&sum<=12) puts(p[sum-1]);
    else printf("***");
	return 0;
}
int add(int n)
{
	int sum=0;
	while(n)
	{
		sum=sum+n%10;
		n=n/10;
	}
		return sum;
}
