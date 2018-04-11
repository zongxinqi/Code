#include<stdio.h>
#include<math.h>
int main()
{
   int	a,b,i,sum=0;
   printf("please input a,b:");
   scanf("%d,%d",&a,&b);
   for(i=1;i<=b;i++)
   {
   	sum=sum+a*(pow(10,i)-1)/9;
   }
   printf("sum=%d\n",sum);
   return 0;
} 
