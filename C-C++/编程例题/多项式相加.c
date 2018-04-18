//#include<stdio.h>
//int main()
//{
//	int i,m,flag;
//	float n,num[1000],sum = 0;
//	while(scanf("%d",&m)!=EOF)
//	{
//		for(i = 1;i <= m;i++)
//		scanf("%f",&num[i]);
//		for(i = 1;i <= m;i++)
//		{
//			sum = 0;
//			flag = 1;
//			for(n = 1;n <= num[i];n++)
//			{
//				sum+=flag/n;
//				flag = -flag;
//			}
//			printf("%.2f\n",sum);
//		}	
//	}
//	return 0;
//}
#include<stdio.h>
#include<math.h>
int main()
{
	int n,m,i;
	double sum;
	while(scanf("%d",&n)!=EOF)
		{
			while(n--)
		{	sum=0;
			scanf("%d",&m); //不用数组的原因是因为如果一直输入而不回车的话，会一直将输入的值存入到缓冲区中，直到回车才会执行下面的语句 
			for(i=1;i<=m;i++)
			{
				sum+=pow(-1,i+1)*1.0/i;
			}
			printf("%.2lf\n",sum);
		}
		}
		return 0;
}
