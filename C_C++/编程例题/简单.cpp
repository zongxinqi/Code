#include<stdio.h>
int f(int b);
int main()
{
	int a=6;
	printf("%d",f(a));
	return 0;	
} 
int f(int b)
{return(b*b);
}
