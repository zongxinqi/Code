#include<stdio.h>
int main()
{
	int i,n,count,sum,p[100],a,b,c,d,e,f;
	while(scanf("%d",&n)&&n!=0)
	{
		count = sum = 0;
		for(i = 0;i < n;i++)
		scanf("%d",&p[i]);
		for(i = 0;i < n;i++)
		{
			a = b = c = d = e = f = 0;
			a = p[i]/100;
			b = (p[i]-a*100)/50;
			c = (p[i]-a*100-b*50)/10;
			d = (p[i]-a*100-b*50-c*10)/5;
			e = (p[i]-a*100-b*50-c*10-d*5)/2;
			f = (p[i]-a*100-b*50-c*10-d*5-e*2);
			count = a + b + c + d + e + f;
			sum+=count;
		}
		printf("%d\n",sum);
	}
}
