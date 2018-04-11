#include<stdio.h>
#define N 40
float average(int score[],int n);
void readscore(int score[],int n);
void datasort(int score[],int n);
int main()
{
int score[N],i,n,data;
float aver;
printf("please input n:");
scanf("%d",&n);
readscore(score,n);
aver=average(score,n);
datasort(score,n);
printf("the average is %f\n",aver);
for(i=0;i<n;i++)
{
printf("%d",score[i]);
}
	return 0;	
}
void readscore(int score[],int n)
{
	int i;
	printf("please input score:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&score[i]);
	}
}
float average(int score[],int n)
{
	int i;
	float sum=0;
	for(i=0;i<n;i++)
	{
		sum+=score[i];
	}
	return n>0?sum/n:-1;
}
void datasort(int score[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(score[j]>score[i])
			{
				temp=score[j];
			    score[j]=score[i];
			    score[i]=temp; 
			}
		}
	}
}

