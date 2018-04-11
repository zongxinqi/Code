#include<stdio.h>
int main()
{
	int i,n;
	for(i=1;i<=5;i++)
{ printf("please input a number:");
scanf("%d",&n);
if(n<0)
break;/*不满足条件的跳出循环*/
printf("n=%d\n",n);  
}
printf("program is over!");
return 0;
}

