#include<stdio.h>
#define EPS 1e-3  /*����EPSΪһ�����޽ӽ�0���������Կ�����0*/ 
int main ()
{
	int x;
	printf("please input x:",&x);
	scanf("%d",&x);
	if (x%2<=EPS)
	{
		printf("x��ż��"); 
	}
	else 
	{
		printf("x������");
	}
}
