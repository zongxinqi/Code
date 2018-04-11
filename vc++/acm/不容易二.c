#include<stdio.h>
int main()
{
	int n,x,i;
	while(~scanf("%d",&n)&&n>0)
	{
		while(n--)
		{
			x = 3;
			scanf("%d",&i);
			while(i--)
			x = 2*(x-1);
			printf("%d\n",x);
		}
	}
	return 0;
}
