#include<stdio.h>
int main()
{
	int x,count=0;
	for(x=100;x<1000;x++)
	{
		if(x==(x/100)*(x/100)*(x/100)+(x/10%10)*(x/10%10)*(x/10%10)+(x%10)*(x%10)*(x%10))
		{
		  printf("%d\n",x);
	      count++;
		}
			
	}
	printf("n=%d",count);
	return 0;
}
