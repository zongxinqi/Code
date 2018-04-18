#include<stdio.h>
int main()
{
	int m,n,count,i;
	while(~scanf("%d%d",&m,&n)&&m&&n)
	{
		count = 0;
		for(i = m;i <= n;i++)
		{
			if((i/1000 == 4) ||(i/100%10 == 4) ||(i/10%10 == 4)||(i%10 == 4))
			continue;
			else 
			count++;
		}
		printf("%d\n",count);	
	}
	return 0;	
} 
