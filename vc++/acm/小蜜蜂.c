#include<stdio.h>
int main()
{
	int n,i,a,b;
	long long num[100];
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%d%d",&a,&b);
			num[a] = 1;
			num[a+1] = 1;
			num[a+2] = 2;
			for(i = a+3;i <= b;i++)
			num[i] = num[i - 1] + num[i - 2];
			printf("%lld\n",num[b]);
		}
	}
	return 0;
} 
