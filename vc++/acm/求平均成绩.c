//#include<stdio.h>
//int main()
//{
//	int i,j,m,n,count;
//	double sc[100][100],sav[100],cav[100],sum;
//	while(scanf("%d%d",&m,&n)!=EOF)
//	{
//		count = 0;
//		for(i = 0;i < m;i++)
//		{
//			sum = 0;
//			for(j = 0;j < n;j++)
//			{
//				scanf("%lf",&sc[i][j]);
//				sum+=sc[i][j];
//			}
//			sav[i] = sum/n;
//		}
//		for(j = 0;j < n;j++)
//		{
//			sum = 0;
//			for(i = 0;i < m;i++)
//				sum+=sc[i][j];
//			cav[j] = sum/m;
//		}
//		for(i = 0;i < m;i++)
//		{
//			if(i != 0) printf(" ");
//				printf("%.2lf",sav[i]);
//		}
//		printf("\n");
//		for(j = 0;j < n;j++)
//		{
//			if(j != 0) printf(" ");
//				printf("%.2lf",cav[j]);
//		}
//		printf("\n");
//		for(i = 0;i < m;i++)
//		{
//			int flag = 1;
//			for(j = 0;j < n;j++)
//			{
//				if(sc[i][j] < cav[j]) flag = 0;
//			}
//			if(flag == 1) count++;
//		}
//		printf("%d\n\n",count);
//	}
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,m,a[51][6],flag,s;
    double sum,avg[51],b[6];
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (i=0;i<6;i++)
            b[i]=0;
        for (i=0;i<n;i++)
            for (j=0,sum=0;j<m;j++)         //sum置零
            {
                scanf("%d",&a[i][j]);       //输入数据，
                sum=sum+a[i][j];            //求每名学生的总成绩
                if (j==m-1)
                {
                    avg[i]=sum/m;           //计算每名学生的平均成绩
                }
                b[j]=b[j]+a[i][j];          //计算每门课程的总成绩
            }
        for (i=0;i<m;i++)
            b[i]=b[i]/n;                    //计算每门课程的平均成绩
        for (i=0,flag=0;i<n;i++)
        {
            for (j=0,s=0;j<m;j++)
            {
                if (a[i][j]>=b[j])
                    s++;
                if (s==m)
                    flag++;                 //统计每门课成绩凑超过平均成绩的学生人数
            }
        }
        for (i=0;i<n;i++)                   //输出每名学生的平均成绩
        {
            if(i==0)
            printf("%.2f",avg[i]);
            else
            printf(" %.2f",avg[i]);
        }
        printf("\n");
        for (i=0;i<m;i++)                   //输出每门课程的平均成绩
        {
            if(i==0)
            printf("%.2f",b[i]);
            else
            printf(" %.2f",b[i]);
        }
        printf("\n");
        printf("%d\n\n",flag);                            //输出超过平均成绩的学生人数

    }
    return 0;
}
