#include<stdio.h>
#define EPS 1e-3  /*定义EPS为一个无限接近0的数，可以看作是0*/ 
int main ()
{
	int x;
	printf("please input x:",&x);
	scanf("%d",&x);
	if (x%2<=EPS)
	{
		printf("x是偶数"); 
	}
	else 
	{
		printf("x是奇数");
	}
}
