#include<stdio.h>
int main()
{
	int fib(int n);
	int n,x;
	scanf("%d",&n);
	x=fib(n);
	printf("%d",x);
	return 0;
}
int fib(int n)
{
  int f;
  if(n==1||n==2) f=1;
  else f=fib(n-1)+fib(n-2);
  return f;	
}
