#include<stdio.h>
int main()
{
	int m,n,i,j,num[100],sum;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i = 1;i <= n;i++)
			num[i] = i*2;
		for(j = 1;j <= n/m;j++)
		{
			sum = 0;
			for(i = m*(j-1)+1;i <= j*m;i++)
				sum+=num[i];
			if(j!=1) printf(" ");
				printf("%d",sum/m);
		}
		if(n!=(j-1)*m)
		{
			sum = 0;
			printf(" ");
			for(i = (j-1)*m+1;i <= n;i++)
			sum+=num[i];
			printf("%d",sum/(n-((j-1)*m)));
		}
		printf("\n");
	}
	return 0;
}
