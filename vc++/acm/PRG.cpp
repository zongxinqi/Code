#include<stdio.h>
int main()
{
	int m;
	long long ans[55];
	while(scanf("%d",&m)!=EOF)
	{
		ans[1] = 3;
		ans[2] = 6;
		ans[3] = 6;
		for(int i = 4;i <= m;i++)
		ans[i] = ans[i-1] + ans[i-2]*2;
		printf("%lld\n",ans[m]);
	}
	return 0;
}
