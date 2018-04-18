#include<stdio.h>
int main()
{
	int i,num[12];
	int *p = num;
	printf("please input 12 numbers:");
	for(i=0;i<12;i++)
	{
		scanf("%d",num+i);
	}
	for(i=0;i<12;i++)
	{
		printf("%d\t",*p++);
		if((i+1)%4==0)printf("\n");
	}
	return 0;
}

	 
