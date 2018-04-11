#include<stdio.h>
#include<string.h>
int main()
{
	int i,n,count;
	char ha[10000];
	while(scanf("%d",&n)!=EOF&&n > 0)
	{
		getchar();
		while(n--)
		{
			count = 0;
			gets(ha);
			for(i = 0;i < strlen(ha);i++)
			{
				if(ha[i] < 0) count++;
			}
			printf("%d\n",count/2);
		}
	}
	return 0;
}
