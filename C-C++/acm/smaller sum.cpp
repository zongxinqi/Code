#include<bits/stdc++.h>
int main()
{
	int n,a[70000],i,j;
	while(scanf("%d",&n) !=EOF)
	{
		for(i = 0;i <= n;i++) a[i] = i;
		if(n % 2 == 0)
		{
			if(n/2%2 == 0) printf("0\n");
			else printf("1\n");
			printf("%d",n/2);
			if(n/2%2 == 0)
				for(j = 1;j < n/2;j+=2) printf(" %d %d",a[j],a[n+1-j]);
			else
			{
				for(j = 1;j < n/2;j+=2) printf(" %d %d",a[j],a[n+1-j]);
				printf(" %d",a[n/2]);	
			} 
		}
		else
		{
			if((n+1)/2%2 != 0)printf("1\n");
			else printf("0\n");
			printf("%d",n/2);
			printf(" %d",a[n]);
			if((n+1)/2%2 == 0)
				for(j = 2;j < (n+1)/2;j+=2) printf(" %d %d",a[j],a[n-j]);
			else
			{
				for(j = 2;j < n/2;j+=2) printf(" %d %d",a[j],a[n-j]);
				if(n/2>0)printf(" %d",a[n/2]);	
			} 
		}
		printf("\n");
	}
	return 0;
}
