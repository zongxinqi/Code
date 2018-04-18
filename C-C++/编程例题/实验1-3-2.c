#include<stdio.h>
int main()
{
	int i,n,j,num[100][100];
	printf("please input the n:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
	  {
	  num[i][j]=i*n+j+1;
	   printf("%d ",num[i][j]);
	  }
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
	if(i%2==0)
	{
	for(j=0;j<n;j++)
	printf("%d ",num[i][j]);
	printf("\n");
	}
	else
	{
		for(j=n-1;j>=0;j--)
		printf("%d ",num[i][j]);
		printf("\n");
	}
    }
	return 0;
}
