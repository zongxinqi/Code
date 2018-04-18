#include<stdio.h>
#include<math.h>
int main()
{
	int m,n,i,j;
	long int max,sc[100][100];
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(i = 1;i <= m;i++)
	{
		for(j = 1;j <= n;j++)
		scanf("%ld",&sc[i][j]);
	}
	max = fabs(sc[1][1]);
	for(i = 1;i <= m;i++)
	{
		for(j = 1;j <= n;j++)
		{
			if(max < fabs(sc[i][j]))
			max = fabs(sc[i][j]);
		}
	}
	for(i = 1;i <= m;i++)
	{
		for(j = 1;j <= n;j++)
		{
			if(max == fabs(sc[i][j]))
			{
				printf("%d %d %ld\n",i,j,sc[i][j]);
				break;
			}
		}
		if(max == fabs(sc[i][j]))
		break;
	}
	}
	return 0;	
}
