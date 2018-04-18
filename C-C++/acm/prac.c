#include<stdio.h>
int swap(int *x,int *y);
int main()
{
	int n,i,j,num[10];
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	scanf("%d",&num[i]);
	for(i = 0;i < n-1;i++)
	{
		for(j = i + 1;j < n;j++)
		{
		if(num[i] < num[j])
		swap(&num[i],&num[j]);	
		}	
	}
	while(n--)
	printf("%d ",num[n]);
	return 0;	
}

int swap(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return 0;
}
