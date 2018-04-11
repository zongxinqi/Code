#include<stdio.h>
#include<string.h> 
int main()
{
	int n;
	char a;
	while(scanf("%d %c",&n,&a)!=EOF)
	{
		for(int i = 1;i <= n;i++)
		{
			if(i == n/2||i == (n/2+1))
			{
				for(int j = 1;j <= n;j++)
				printf("%c",a);
			}
			else
			{
				for(int j = 1;j <= n;j++)
				{
					if(j == n/2||j == (n/2 + 1)) printf("%c",a);
					else printf("*");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
