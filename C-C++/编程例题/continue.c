#include<stdio.h>
int main()
{
	int i,n;
	for(i=1;i<=3;i++)
	{
		printf("please input a number:");
		scanf("%d",&n);
		if(n<0)
		continue;/*不符合的话不在继续下面的语句，而是返回执行前面的直到循环达到结束条件*/
		printf("n=%d\n",n);
	}
	printf("program is over!");
	return 0;
}
