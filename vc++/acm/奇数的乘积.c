//#include<stdio.h>
//int main()
//{
//	int n,mul,i,num[5000];
//	while(scanf("%d",&n)!=EOF)
//	{
//		mul = 1;
//		for(i = 0; i <n;i++)
//		{
//		scanf("%d",&num[i]);
//		if(num[i] %2 != 0) mul*=num[i];	
//		}
//		printf("%d\n",mul);
//	}
//}
#include <stdio.h>
int main()
{
	int n,sum,num;
	while(scanf("%d",&n)!=EOF)
	{
		sum=1;
		while(n--)//直到n=0结束循环 
		{
			scanf("%d",&num);
			if(num%2==1)
				sum*=num;
		}
		printf("%d\n",sum);
	}
	return 0;
}
