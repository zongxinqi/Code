#include<stdio.h>
#include<math.h>
int main()
{
  int i,n,k,m=0;
 for(n=1;n<=1000;n=n+1)
  {
  k=sqrt(n);
  for(i=2;i<=k;i++)/*1和2不符合循环条件，直接运行下面的条件语句*/
   {if(n%i==0)
  break;
   }	
	  if(i>=k+1)
	  {printf("%d ",n);
	  m=m+1;
	  if(m%10==0) /*在一行中输出10个数字时，输出一个换行*/ 
	  printf("\n");
      }
  }
  printf("\n1000以内的素数有%d个",m);
	  return 0;
}
