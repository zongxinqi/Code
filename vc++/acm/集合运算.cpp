#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int m,n,i,j,a[1007],b[1005],flag1[1005] = {0},flag2[1005] = {0},c[2005];
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0;i < n;i++)
		scanf("%d",&a[i]);
		scanf("%d",&m);
		for(i = 0;i < m;i++)
		scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+m);
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		for(i = 0;i < n;i++)
		{for(j = 0;j < m;j++){if(a[i] == b[j]) {printf("%d ",a[i]);count1++;}}}
		if(count1 != 0) printf("\n");
		for(i = 0;i < n;i++)
		{
			c[i] = a[i];
			for(j = 0;j < m;j++){if(a[i] == b[j])flag1[j] = 1;}
		}
		int n1 = n;
		for(j = 0;j < m;j++) {if(flag1[j] == 0){c[n1] = b[j];n1++;}}
		sort(c,c+n1);
		for(i = 0;i < n1;i++) printf("%d ",c[i]);
		printf("\n");
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < m;j++)
			{if(a[i] == b[j]) flag2[i] = 1;}
				if(flag2[i] == 0) 
				{printf("%d ",a[i]);count3++;}
		}
		if(count3 != 0) printf("\n");	
	 } 	
} 
