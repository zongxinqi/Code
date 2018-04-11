#include<stdio.h>
long long fun(int n)
{
	if(n == 1||n == 0) return 1;
	if(n > 1) return n * fun(n - 1);
}
long long fu(int n)
{
	if(n == 1) return 0;
	if(n == 2) return 1;
	if(n >= 3) return (n - 1)*(fu(n - 1) + fu(n - 2));
}
int main()
{
	int c,m,n;
	while(scanf("%d",&c)!=EOF)
	{
		while(c--)
		{
			scanf("%d%d",&n,&m);
			printf("%lld\n",fun(n)/(fun(n - m)*fun(m))*fu(m));
		}	
	} 
	return 0;
}
