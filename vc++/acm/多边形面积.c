#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	float x[100],y[100],sum;
	while(scanf("%d",&n)!=EOF&&n)
	{
		sum = 0;
		for(i = 0;i < n;i++)
			scanf("%f%f",x+i,y+i);
		for(i = 0;i < n;i++)
			sum+=x[i%n]*y[(i+1)%n] - y[i%n]*x[(i+1)%n];
		printf("%.1f\n",fabs(sum/2));
	}
	return 0;
}
