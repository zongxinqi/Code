#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,a[20][20],tot;
	printf("please input the n:");
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	tot=a[i=0][j=0]=1;
	while(tot<n*n)
	{
		while(j+1<n&&!a[i][j+1]) a[i][++j]=++tot;
		while(i+1<n&&!a[i+1][j]) a[++i][j]=++tot;
		while(j-1>=0&&!a[i][j-1]) a[i][--j]=++tot;
		while(i-1>=0&&!a[i-1][j]) a[--i][j]=++tot;	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%4d",a[i][j]);
		printf("\n");
	}
	return 0;
 } 
