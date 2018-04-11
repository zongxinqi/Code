#include<stdio.h>
int Readscore(long num[] ,int score[]);
void Order(int score[],long num[],int n);
#define N 30
int main()
{
	int score[N],n;
	long num[N];
	n=Readscore(num,score);
	Order(score,num,n);
	printf("ID\tscore\n");
	for(int i = 0;i < n;i++)
		printf("%ld\t%d\n",num[i],score[i]);
	return 0;
}
int Readscore(long num[] ,int score[])
{
	int i=-1;
		printf("Input ID and score!\n");
	do
	{
		i++;
		scanf("%ld%d",&num[i],&score[i]);
		
	}while((score[i]>=0)&&(num[i]>0));
	return i;
}
void Order(int score[],long num[],int n)
{
	int i,j,temp1;
	long temp2;
	printf("Order is \n");
	for(i = 0;i < n - 1;i++)
	{
		for(j = i + 1;j < n;j++)
		{
			if(score[i]<score[j])
			{
				temp1=score[i];
				score[i]=score[j];
				score[j]=temp1;
				temp2=num[i];
				num[i]=num[j];
				num[j]=temp2;
			}	
		}
	}
}
