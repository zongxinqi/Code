#include<stdio.h>
#include<math.h>
int f(int n);
int main()
{
	int n,x,y;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%d%d",&x,&y);
			printf("%s\n",f(x)==y&&f(y)==x?"YES":"NO");
		}
	}
	return 0;
}

int f(int n)
{
	int r = 0,i;
	for(i = 1;i < n;i++)
	{
		if(n%i==0) r+=i;
	}
	return r;
}
