#include<stdio.h>
int main()
{
	int m,n,i,num[100],flag;
	while(scanf("%d%d",&n,&m)!=EOF&&(m!=0||n!=0))
	{
		flag = 1;
		for(i = 0;i < n;i++)
			scanf("%d",&num[i]);
			for(i = 0;i < n;i++)
			{
				if(m <= num[i]&&flag){
					printf("%d %d",m,num[i]);
					flag = 0;
				}
				else printf("%d",num[i]);
				if(i == n-1) printf("\n");
				else printf(" ");
			}
	}
	return 0;
}
