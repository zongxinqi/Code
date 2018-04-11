#include<cstdio>
#include<cmath>
int main()
{
	int n,i,j;
	long long ans,t,aux;
	while(scanf("%d",&n)!=EOF)
	{
		ans = 0;
		if(n >= 2 && n < 5)	ans = n*(n - 1)/2;
		for(i = 8;i >= 0;i--)
		{
			if(n >5*pow(10,i)) 
			{
				t =pow(10,i+1) - 1;
				for(j = 0;j < 9;j++)
				{
					aux =j*pow(10,i+1) + t;
					if(aux <= n) ans += aux/2;
					else {ans += (n - (aux+1)/2 + 1)>=0?(n - (aux+1)/2 + 1):0;}
				}
				break;
			}
			else if(n ==5*pow(10,i)){ans = 1;break;}
		}
		printf("%lld\n",ans);
	}
	return 0;	
} 
