#include<stdio.h>
#include<math.h>
int main()       /* 运用了数学的绝对值函数对三位的数字进行了位置交换操作*/ 
{
	int x,y,b0,b1,b2,sum;
	printf("input x:");
	scanf("%d",&x);
	y=(int)fabs(x);
	b2=y/100;
	b1=(y-b2*100)/10;
	b0=y%10;
	sum=b0*100+b1*10+b2;
	printf("y=%d\nb0=%d\nb1=%d\nb2=%d\nsum=%d\n",y,b0,b1,b2,sum);
	return 0;
}
