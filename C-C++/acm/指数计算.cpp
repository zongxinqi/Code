#include<stdio.h>
#include<math.h>
int main()
{
	int a,n;
	long long ans;
	while(scanf("%d%d",&a,&n)!=EOF)
	{
		ans = pow(a,n);
		printf("%d^%d = %lld\n",a,n,ans);
	}
	return 0;
}
