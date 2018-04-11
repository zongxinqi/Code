#include<stdio.h>
int main()
{
	int a,b,x,y;
	scanf("%d%d%d",&a,&x,&y);
	x = a % 3*(int)(x+y)%2/4;
	printf("%d",x);
	scanf("%d%d%d%d",&a,&b,&x,&y);
	x = (float)(a+b)/2+(int)x%(int)y;
	printf("%d",x);
	return 0;
}
