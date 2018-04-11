#include<stdio.h> 
int main()
{
	int n,i,j,a[10005],flag[10005] = {0},count;
	while(scanf("%d",&n)!=EOF)
	{
		count = 0;
		for(i = 1;i <= n;i++)	a[i] = i;
		for(i = 1;i <= n;i++)
		{
			for(j = 1;j <= n;j+=3)
			{
				if(flag[j] == 1) continue;
				else {flag[j] = 1;count++;}
				if(count == (n-1)&&flag[i] == 0) printf("%d\n",a[i]);
			}
		}
	}
	return 0;   
}
