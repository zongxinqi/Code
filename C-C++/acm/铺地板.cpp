#include<stdio.h>
int main()
{
	int n;
	long long ans[55];
	while(scanf("%d",&n)!=EOF)
	{
		ans[1] = 1;
		ans[2] = 2;
		ans[3] = 3;
		for(int i = 4;i <= n;i++)
		ans[i] = ans[i-1] + ans[i-2];
		printf("%lld\n",ans[n]);
	}
	return 0;
}
