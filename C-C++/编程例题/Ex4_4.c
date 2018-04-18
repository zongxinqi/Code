#include<stdio.h>
int main()
{
	int x,a,b,c,d,e,n;
	printf("please input x:");
	scanf("%d",&x);
	if(x>0&&x<10)
	{printf("n=1\na=%d",x);
	}
	else if(x>=10&&x<100)
	{
		printf("n=2\na=%d\nb=%d\n",x%10,x/10);
	}
	else if(x>=100&&x<1000)
	{
		printf("n=3\na=%d\nb=%d\nc=%d\n",x%10,x/10%10,x/100);
	}
	else if(x>=1000&&x<10000)
	{
		printf("n=4\na=%d\nb=%d\nc=%d\nd=%d\n",x%10,x/10%10,x/100%10,x/1000);
	}
	else if(x>=10000&&x<100000)
{
	printf("n=5\na=%d\nb=%d\nc=%d\nd=%d\ne=%d\n",x%10,x/10%10,x/100%10,x/1000%10,x/10000);
}
else 
{printf("invalid number");
}
return 0;
}

