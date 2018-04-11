#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	long long ans[45];
	while(scanf("%d",&n)!=EOF)
	{
		ans[1] = 3;
		ans[2] = 8;
		ans[3] = 22;
		for(int i = 4;i <= n;i++)
		ans[i] = 2*(ans[i-1] + ans[i-2]);
		printf("%lld\n",ans[n]);
	}	
	return 0;
} 
