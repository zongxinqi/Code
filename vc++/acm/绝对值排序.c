#include<stdio.h>
#include<math.h>
int swap(int*x,int*y);
int main()
{
	int n,i,j,num[100];
	while(scanf("%d",&n)&&n)
	{
		for(i = 0;i < n;i++)
		scanf("%d",&num[i]);
		for(i = 0;i < n-1;i++)
		{
			for(j = i+1;j < n;j++)
			{
				if(fabs(num[i]) < fabs(num[j]))
				swap(&num[i],&num[j]);
			}
		}
		for(i = 0;i < n;i++)
		{
			if(i != 0) printf(" ");
			printf("%d",num[i]);
		}
		printf("\n");
	}
	return 0;
}
int swap(int*x,int*y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return 0;
}
