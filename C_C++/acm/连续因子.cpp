#include<stdio.h>
#include<math.h>
int main()
{
	long long n;
	scanf("%lld",&n);
	int max = sqrt(n);
	for(int len = 12;len >= 1;len--)
	{
		for(int st = 2;st <= max;st++)
		{
			long long ans = 1;
			for(int i = st;i - st <= len - 1;i++)
			{
				ans *= i;
			}
			if(n % ans == 0)
			{
				printf("%d\n%d",len,st);
				for(int i = st + 1;i - st <= len - 1;i++)
				printf("*%d",i);
				return 0;	
			}
		}
	}
	printf("1\n%lld",n);
	return 0;
}
