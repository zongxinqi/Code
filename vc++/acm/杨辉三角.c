//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int s = 1,h,i,j;
//	while(scanf("%d",&h)!=EOF)
//	{
//		printf("1\n");
//		for(i = 2;i <= h;s = 1,i++)
//		{
//			printf("1 ");
//				for(j = 1; j <= i-2;j++)
//				printf("%d ",(s = (i - j) * s / j));
//			printf("1\n");
//		}
//	printf("\n");
//	getchar();
//	}
//	return 0;
//} 



//#include<stdio.h>
//#define M 10//?����
////#define PYRAMID//?����������������ո�
////#define REVERSE//?��������һ�Σ��õ�����
//int main(void)
//{
//  int a [M][M],i,j;//?��ά�����ѭ��������a[��][��]
//for(i=0;i<M;i++)//ÿһ��
//{
//#ifdef PYRAMID
//for(j=0;j<=M-i;j++)printf(" ");
//#endif //?������
//for(j=0;j<=i;j++)//?��ֵ��ӡ
//printf("%4d",(a[i][j]=(i==j||j==0)?1://?��β��?1
//a[i-1][j]+a[i-1][j-1]));//?ʹ����һ�м���
//printf("\n");
//}
//#ifdef REVERSE
//for(i=M-2;i>=0;i--)
//{
//#ifdef PYRAMID
//for(j=0;j<=M-i;j++)printf(" ");
//#endif //?������
//for(j=0;j<=i;j++)printf("%4d",a[i][j]);//?ֱ��ʹ����ǰ��õ�ֵ
//printf("\n");
//}
//#endif//?���ν���
//getchar();//?��ͣ�ȴ�
//}


#include <stdio.h>
#include "string.h"
int main()
{
	int a[10000];//��������n*(n+1)/2<=10000��֪��n<=141
	int b,CR,i;//bΪ��ǰ������CRΪҪ����ʾ��������iΪѭ����
	printf("������Ҫ��ʾ��������3~141����");
	scanf("%d",&CR);
	a[1]=a[2]=1;//ǰ������ֵ����ȫΪ1����ֱ�����
	printf("%d\n",a[1]);
	printf("%d %d\n",a[1],a[2]);
		for(b=3;b<=CR;b++)//�ӵ����п�ʼ�ж�
		{
			for(i=b;i>=2;i--)//�ӵ�����һ������ʼ��
				a[i]=a[i]+a[i-1];//������ǵĹ��ɣ�û��ֵ������Ĭ��Ϊ0
			for(i=1;i<=b;i++)//��ʾѭ��
				printf("%d ",a[i]);
			printf("\n");//?����
		}
		return 0;
}
