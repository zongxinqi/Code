#include<stdio.h>
#define months 12
int main()
{
    int days[2][months]={{31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}};
    int year,month;
	do
	{
    printf("please input year,month:");
	scanf("%d,%d",&year,&month);
      if(month<1||month>12)	
      {printf("the number is wrong!\n");
      }
	}while(month<1||month>12);
	if((year%4==0)&&(year%100!=0)||(year%400==0))
	printf("the number of the days is %d",days[1][month-1]);
	else 
	printf("the number of the days is %d",days[0][month-1]);
	return 0;                 
					 	
}
