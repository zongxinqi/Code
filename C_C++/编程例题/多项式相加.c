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
			scanf("%d",&m); //���������ԭ������Ϊ���һֱ��������س��Ļ�����һֱ�������ֵ���뵽�������У�ֱ���س��Ż�ִ���������� 
			for(i=1;i<=m;i++)
			{
				sum+=pow(-1,i+1)*1.0/i;
			}
			printf("%.2lf\n",sum);
		}
		}
		return 0;
}
