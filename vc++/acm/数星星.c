#include<stdio.h>
#include<string.h>
int min(int a,int b);
int max(int a,int b);
int s[5001][5001];
int main()
{
	int t,x1,x2,y1,y2,m,x,y,i,j,su,n;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			memset(s,0,sizeof(s));
			scanf("%d",&n);
			while(n--)
			{
				scanf("%d%d",&x,&y);
				s[x][y] ++;
				
			}
		scanf("%d",&m);
		for(i = 1;i <= 5000;i++)
			{
				for(j = 1;j <= 5000;j++)
				s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + s[i][j];
			}
		while(m--)
		{
			su = 0;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				su = s[max(x1,x2)][max(y1,y2)] - s[max(x1,x2)][min(y1,y2)-1] - s[min(x1,x2)-1][max(y1,y2)] + s[min(x1,x2)-1][min(y1,y2)-1];
			printf("%d\n",su);
		}
		}
	}
	return 0;
}

int min(int a,int b)
{
	return a < b?a:b;
}
int max(int a,int b)
{
	return a > b?a:b;
}
