#include<stdio.h>
unsigned long fact(unsigned int n);/*可以选择在开头就写上声明语句*/
int main()
{
	int m,k;
	double p;
	do
	{
		printf("please input m,k(m>=k>0):");
		scanf("%d,%d",&m,&k);
	}while(m<k||m<0||k<0);
	p=(double)fact(m)/(fact(k)*fact(m-k));
	printf("p=%.0f\n",p);
}
unsigned long fact(unsigned int n)/*已经确定了为正数，用无符号的增大了数据的范围*/ 
{
	unsigned int i;
	unsigned long result =1;
	for(i=2;i<=n;i++)
	result=result*i;
	return result;
}
