#include<stdio.h>
int findmax(int num[10]);
int findmin(int num[10]);
int main()
{
	int i,max,min,num[10];
	for(i=0;i<10;i++)
	{
		scanf("%d",&num[i]);
	}
	for(i=9;i>=0;i--)
	{
		printf("%d ",num[i]);
	}
	max=findmax(num);
	min=findmin(num);
	printf("\n");
	printf("max=%d\n",max);
	printf("min=%d\n",min);
	
}
int findmax(int num[10])
{
	int max,j;
	max=num[0];
	for(j=1;j<10;j++)
	{
		if(num[j]>max)
		max=num[j];
	}
	return max;
} 
int findmin(int num[10])
{
	int min,j;
	min=num[0];
	for(j=1;j<10;j++)
	{
		if(num[j]<min)
		min=num[j];
	}
	return min;
}


