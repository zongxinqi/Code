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
            for (j=0,sum=0;j<m;j++)         //sum����
            {
                scanf("%d",&a[i][j]);       //�������ݣ�
                sum=sum+a[i][j];            //��ÿ��ѧ�����ܳɼ�
                if (j==m-1)
                {
                    avg[i]=sum/m;           //����ÿ��ѧ����ƽ���ɼ�
                }
                b[j]=b[j]+a[i][j];          //����ÿ�ſγ̵��ܳɼ�
            }
        for (i=0;i<m;i++)
            b[i]=b[i]/n;                    //����ÿ�ſγ̵�ƽ���ɼ�
        for (i=0,flag=0;i<n;i++)
        {
            for (j=0,s=0;j<m;j++)
            {
                if (a[i][j]>=b[j])
                    s++;
                if (s==m)
                    flag++;                 //ͳ��ÿ�ſγɼ��ճ���ƽ���ɼ���ѧ������
            }
        }
        for (i=0;i<n;i++)                   //���ÿ��ѧ����ƽ���ɼ�
        {
            if(i==0)
            printf("%.2f",avg[i]);
            else
            printf(" %.2f",avg[i]);
        }
        printf("\n");
        for (i=0;i<m;i++)                   //���ÿ�ſγ̵�ƽ���ɼ�
        {
            if(i==0)
            printf("%.2f",b[i]);
            else
            printf(" %.2f",b[i]);
        }
        printf("\n");
        printf("%d\n\n",flag);                            //�������ƽ���ɼ���ѧ������

    }
    return 0;
}
