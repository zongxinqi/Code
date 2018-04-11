#include<stdio.h>
int main()
{
	int i,n,x;
	while(scanf("%d",&n)!=EOF)
	{
		x = 1;
		for(i = 1;i < n;i++)
		x = (x + 1) * 2;
		printf("%d\n",x);
	}
	return 0;
}
