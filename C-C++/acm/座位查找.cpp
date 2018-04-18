#include<stdio.h>
struct student
{
	long long a;
	int b,c;
}T[1003];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)	
	{
		scanf("%lld%d%d",&T[i].a,&T[i].b,&T[i].c);
	}
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int d;
		scanf("%d",&d);
		for(int i = 0;i < n;i++)
		{
			if(d == T[i].b)
			{
				printf("%lld %d\n",T[i].a,T[i].c);
			} 
		}
	}
	return 0;
}
