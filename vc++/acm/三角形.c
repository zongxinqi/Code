#include<stdio.h>
int main()
{
	int i,n;
	double num[3];
	while(~scanf("%d",&n)&&n>0)
	{
		while(n--)
		{
			for(i = 0;i < 3;i++)
			scanf("%lf",num+i);
			if(num[0] + num[1] > num[2]&&num[0] + num[2] > num[1]&&num[1] + num[2] > num[0])
			printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
