#include<stdio.h>
int main()
{
	int m,n,sum;
	while(~scanf("%d%d",&m,&n)&&(m||n))
	{
		sum = 1;
		while(n--)
		{
			sum*=m;
			sum%=1000;
		}
		printf("%d\n",sum);
	}
	return 0;
}
