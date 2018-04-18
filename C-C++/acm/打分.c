#include<stdio.h>
int swap(double *x,double *y);
int main()
{
	int i,j,n;
	double x[100],sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum = 0;
		for(i = 0;i < n; i++)
			scanf("%lf",&x[i]);
		for(i = 0;i < n-1;i++)
		{
			for(j = i+1;j < n;j++)
			{
				if(x[i] < x[j]) 
				swap(&x[i],&x[j]);
			}
		}
		for(i = 1;i < n-1;i++)
		sum+=x[i];
		printf("%.2lf\n",sum/(n-2));
	}
	return 0;
}

int swap(double *x,double *y)
{
	double temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return 0;
}
