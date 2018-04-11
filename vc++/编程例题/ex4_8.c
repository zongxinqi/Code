#include<stdio.h>
float sum1(int n);
float sum2(int n);
float sum3(int n);
int main()
{
	int n;
	float a;
	a=sum1(n)+sum2(n)+sum3(n);
	printf("sum=%f\n",a);
	return 0;
}
float sum1(int n)
{
	int k;
	float sum=0;
	for(k=1;k<=100;k++)
	{
		sum=sum+k;
	}
	return sum;
}
float sum2(int n)
{
	int k;
	float sum=0;
	for(k=1;k<=50;k++)
	{
		sum=sum+k*k;
	}
	return sum;
}
float sum3(int n)
{
	int k;
	float sum=0;
	for(k=1;k<=10;k++)
	{
		sum=sum+1.0/k;
	}
	return sum;
}
