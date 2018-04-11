#include<stdio.h>
int main()
{
	int n,i,min,num[100];
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		for(i = 0;i < n;i++)
			scanf("%d",&num[i]);
		min = num[0];
		for(i = 1;i < n;i++)
		{
			if(min > num[i])
				min = num[i];
		}
		for(i = 0;i < n;i++)
		{
			if(min == num[i])
			{
				num[i] = num[0];
				num[0] = min;
			} 
		}
		for(i = 0;i < n;i++)
		{
			if(i != 0) printf(" ");
			printf("%d",num[i]);
		}
		printf("\n");
	}
	return 0;
}

