#include<stdio.h>
int main()
{
	int n,i;
	 while(scanf("%d",&n)!=EOF&&n!=0)
	   {
	    if(n<=4) n=n;
		else
		{
			for(i = n-4;i > 0;i--)
			n+=i;
		}	
		printf("%d\n",n);
	   }
	return 0;
} 
