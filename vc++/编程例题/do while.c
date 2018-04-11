#include<stdio.h>
int main()
{
	int i,n,sum;
	printf("Input n:");
	scanf("%d",&n);
	sum=0;
	i=1;
	do{
		sum=sum+i;
		i++;
	}while (i<=n);
	printf("sum=%d\n",sum);
	
}
