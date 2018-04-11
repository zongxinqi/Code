#include<stdio.h>
#include<math.h>
int main()
{
	int m,n,i,j;
	while(scanf("%d%d",&m,&n)!=EOF&&(m != 0 || n != 0))
	{
		j = 0;
		while(m<=n)
		{
			for(i = 2;i <= (int)sqrt(m);i++)
			{
				if(m%i == 0) break;	
			}
			if(i == (int)sqrt(m) + 1) 
			{	
				if(j != 0) printf("\t");
				printf("%d",m);
				j++;
			}
			m++;
		}
		printf("\n");
	}
	return 0;
}
