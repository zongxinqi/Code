#include<stdio.h>
int main()
{
	int n,h,i,a[100];
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			a[1] = 0;
			a[2] = 1;
			a[3] = 2;
			scanf("%d",&h);
			for(i = 4;i <= 40;i++)
			a[i] = a[i-1] + a[i-2];
			printf("%d\n",a[h]);
		}
	}
	return 0;
}
