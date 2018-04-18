#include<stdio.h>
#define N 40
int readscore(int score[]);
int findmax(int score[],int n);
int main()
{
	int score[N],max,n;
	n=readscore(score);
	printf("the total students are %d\n",n);
	max=findmax(score,n);
	printf("the max is %d",max);
	return 0;
}
int readscore(int score[])
{
	int i=-1;
	printf("please input score:");
	do
	{
		i++;
		scanf("%d,",&score[i]);
	}while(score[i]>=0);
	return i;
}
int findmax(int score[],int n)
{
	int max=score[0],i;
	for(i=1;i<n;i++)
	{
		if(score[i]>max)
		max=score[i];
	}
	printf("the location is %d\n",i);
	return i;
}
