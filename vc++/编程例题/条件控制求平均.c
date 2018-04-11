#include<stdio.h>
#define N 40
int average(int score[],int n);
int readscore(int score[]);
int main()
{
	int score[N],aver,n;
	n=readscore(score);
	printf("total students are %d\n",n);
	aver=average(score, n);
	printf("the average is %d\n",aver);
	return 0;
}
int readscore( int score[])
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
int average(int score[],int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=score[i];
	}
	return n>=0?sum/n:-1;
}
