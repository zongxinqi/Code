#include<bits/stdc++.h>
double fun(int n)
{
	if(n == 1) return 1;
	else return n * fun(n-1);
}
double cfun(int n)
{
	if(n == 1) return 0;
	else if(n == 2) return 1;
	else return (n - 1)*(cfun(n - 1) + cfun(n - 2)); 
}
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		while(n--)
		{
			int m;
			double p,q;
			scanf("%d",&m);
			p = fun(m);
			q = cfun(m);
			printf("%.2lf%%\n",(q/p)*100);
		} 
	}
	return 0;
}
