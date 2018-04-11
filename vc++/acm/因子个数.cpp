#include<stdio.h>
#include<math.h>
int main()
{
	int n,t,count;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			count = 0;
			scanf("%d",&n);
			for(int j = 1;j <= sqrt(n);j++)
			{
				if(n%j == 0)
				{
					if(n/j==j) count++;
					else count+=2;
				}
			}
			printf("%d\n",count);
		}
	}
}
