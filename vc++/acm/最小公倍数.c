#include<stdio.h>
#include<string.h>
long long gcd (long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	long long i,n,num,data[100];
	while(scanf("%lld",&n)!=EOF&&n > 0)
	{
		num = 1;
		if(n == 1)
			continue; 
		for(i = 0;i < n;i++)
		{
			scanf("%lld",&data[i]);
			num = num*data[i]/gcd(num,data[i]);
		}
		printf("%lld\n",num);
	}
	return 0;
}
