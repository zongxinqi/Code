#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,n,x,y,sum1,sum2;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			sum1 = sum2 = 0;
			scanf("%d%d",&x,&y);
			for(i = 1,j = 1;i < x&&j < y;i++,j++)
			{
				if(x%i==0) sum1+=i;
				if(y%j==0) sum2+=j;
			}
			if(sum1==y&&sum2==x) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
