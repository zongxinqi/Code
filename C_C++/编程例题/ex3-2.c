#include<stdio.h>
#include<math.h>
int main()       /* ��������ѧ�ľ���ֵ��������λ�����ֽ�����λ�ý�������*/ 
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
