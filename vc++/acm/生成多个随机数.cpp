#include<bits/stdc++.h>
int main()
{
	int i,n,m,a[20],num[20]; //
	srand((unsigned)time(NULL)); 
	int flag;
	while(scanf("%d",&m)!=EOF)
	{
		i=0; 
		flag = 1;
		memset(a,0,sizeof(a));
		for(int j = 1;j <= m;j++)
		scanf("%d",num+j);
		while(1) 
		{ 
		n=rand()%m+1; 
		if(a[n-1]!=-1) 
		{ 
			if(flag){printf("%d,",num[n]);flag = 0;}
			else {printf("%d\n",num[n]);flag = 1;} 
			a[n-1]=-1; //用数组做标记
			if((++i)==m)break; //取到几个数就停止
		} 
		} 
	}
    return 0;
}
