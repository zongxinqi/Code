#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	char c;
	scanf("%d %c",&n,&c);
	int i,j;
	int m = sqrt(double((n+1)/2));
	for(i = 1;i <= m;i++)
	{
		for(j = 1;j < i;j++)
		printf(" ");
		for(j = 1;j <= 2 * (m - i) + 1;j++)
		printf("%c",c);
		printf("\n");
	}
	for(i = 1;i <= m - 1;i++)
	{
		for(j = 1;j <= m - i - 1;j++)
		printf(" ");
		for(j = 1;j <= 2 * i + 1;j++)
		printf("%c",c);
		printf("\n");
	}
	printf("%d",n - 2 * m * m + 1);
	return 0;
}
