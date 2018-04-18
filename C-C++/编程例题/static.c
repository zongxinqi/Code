#include<stdio.h>
long Func(int n);
int main()
{
	int i,n;
	char c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("%d!=%d\n",i,Func(i));
	}
	return 0;
}
//函数功能：通过静态变量实现n的阶乘的求解 
long Func(int n)
{
	static long p=1;
	p=p*n;
	return p;
}
