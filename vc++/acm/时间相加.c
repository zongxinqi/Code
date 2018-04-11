#include<stdio.h>
int main()
{
	long n,a1,b1,c1,a2,b2,c2;
	while(scanf("%ld",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%ld%ld%ld%ld%ld%ld",&a1,&b1,&c1,&a2,&b2,&c2);
			printf("%ld %ld %ld\n",a1+a2+(b1+b2+(c1+c2)/60)/60,(b1+b2+(c1+c2)/60)%60,(c1+c2)%60);
		}
	} 
	return 0;
 } 
