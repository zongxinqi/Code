#include<stdio.h>
#include<math.h>
int main()
{
	int m,n,a,b,c,d;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		d = 0;
		while(m<=n)
		{
			a = m/100;
			b = m/10%10;
			c = m%10;
			if(m == (pow(a,3) + pow(b,3) + pow(c,3)))
			{
				if(d != 0) printf(" ");
				printf("%d",m);
				d++;
			}
			m++;
		}
		if(d == 0) printf("no\n");
		else printf("\n");
	}
	return 0;
}
