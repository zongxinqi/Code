#include<stdio.h>
#include<math.h>
int main()
{
	int x,y,n,i,prime[1000],flag;
	while(scanf("%d%d",&x,&y)!=EOF&&(x != 0||y != 0))
	{
		while(x<=y)
		{
			flag = 1;
			n = pow(x,2) + x + 41;
			for(i = 2;i <= sqrt(n);i++)
			{
				if(n%i == 0) 
				{
					flag = 0;
					break;
				}
			}
			if(flag == 0) break;
			x++;
		}
		if(flag == 1) printf("OK\n");
		else printf("Sorry\n");
	}
	return 0;
}
