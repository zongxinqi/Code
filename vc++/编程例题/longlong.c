#include<stdio.h>
int main()
{
	long long a,b,sum;
	while(~scanf("%lld%lld",&a,&b)&&a&&b)
	{
			sum = 0;
			sum = a + b;
			printf("%lld\n",sum);
	}
	return 0;
} 
