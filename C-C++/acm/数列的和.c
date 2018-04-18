#include<stdio.h>
#include<math.h>
int main()
{
	float n,m,i,sum;
	while(scanf("%f%f",&n,&m)!= EOF)
	{
		sum = 0;
		for(i = 0;i < m;i++)
		{
			sum = sum + n;
			n = sqrt(n);
		}
		printf("%.2f\n",sum);
	}
	return 0;
}
