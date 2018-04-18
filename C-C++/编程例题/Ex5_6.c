#include<stdio.h>
int main()
{
	int x,i,n=0;
	for(x=1;x<=1000;x++)
	{
		n=0;/*这就类似以前求阶乘不借用上一步的值，在每一次循环结束之后都需要对n初始化，最终的值才是因子
		的和，否则就是所有数的因子的和了，结果自然也就不对了*/
		for(i=1;i<x;i++)
		{ 
	    if(x%i==0)
	    n=n+i;
	    }
	    if(x==n)
	    {
	    	printf("%d its factors are",x);/*最后的格式中前缀语句和因子的值需要分别输出*/ 
		for(i=1;i<x;i++)
		{ 
	    if(x%i==0)
	    printf("%d,",i);
			}
			printf("\n");/*将所有因子输出之后在输出一个空格，使排版显的更美观*/	
		
	    }
	}
  return 0;	
}
