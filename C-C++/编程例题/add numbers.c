#include <stdio.h>
int main()
{
	int i,n,j,sum=0;
	printf("please input n:");
	scanf("%d",&n);
	for(i=1,j=n;i<=j;i++,j--) /*define plenty of variable quantity to fasten speed*/
	{sum=sum+i+j;
    } 
    if(n%2!=0)
		printf("sum=%d\n",sum-i+1);/*when the i input it's value is plus,need to return to the original value*/
    else
        printf("sum=%d\n",sum);
	return 0;
}
