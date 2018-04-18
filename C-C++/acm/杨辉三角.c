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
//#define M 10//?行数
////#define PYRAMID//?金字塔，会额外填充空格
////#define REVERSE//?反向再来一次，得到菱形
//int main(void)
//{
//  int a [M][M],i,j;//?二维数组和循环变量，a[行][列]
//for(i=0;i<M;i++)//每一行
//{
//#ifdef PYRAMID
//for(j=0;j<=M-i;j++)printf(" ");
//#endif //?填充结束
//for(j=0;j<=i;j++)//?赋值打印
//printf("%4d",(a[i][j]=(i==j||j==0)?1://?首尾置?1
//a[i-1][j]+a[i-1][j-1]));//?使用上一行计算
//printf("\n");
//}
//#ifdef REVERSE
//for(i=M-2;i>=0;i--)
//{
//#ifdef PYRAMID
//for(j=0;j<=M-i;j++)printf(" ");
//#endif //?填充结束
//for(j=0;j<=i;j++)printf("%4d",a[i][j]);//?直接使用以前求得的值
//printf("\n");
//}
//#endif//?菱形结束
//getchar();//?暂停等待
//}


#include <stdio.h>
#include "string.h"
int main()
{
	int a[10000];//容器，由n*(n+1)/2<=10000可知，n<=141
	int b,CR,i;//b为当前行数，CR为要求显示的行数，i为循环数
	printf("请输入要显示的行数（3~141）：");
	scanf("%d",&CR);
	a[1]=a[2]=1;//前两行数值少且全为1，故直接输出
	printf("%d\n",a[1]);
	printf("%d %d\n",a[1],a[2]);
		for(b=3;b<=CR;b++)//从第三行开始判断
		{
			for(i=b;i>=2;i--)//从倒数第一个数开始加
				a[i]=a[i]+a[i-1];//杨辉三角的规律，没有值的数组默认为0
			for(i=1;i<=b;i++)//显示循环
				printf("%d ",a[i]);
			printf("\n");//?换行
		}
		return 0;
}
