#include<stdio.h>
#include<math.h>
int main()
{
  int i,n,k,m=0;
 for(n=1;n<=1000;n=n+1)
  {
  k=sqrt(n);
  for(i=2;i<=k;i++)/*1��2������ѭ��������ֱ������������������*/
   {if(n%i==0)
  break;
   }	
	  if(i>=k+1)
	  {printf("%d ",n);
	  m=m+1;
	  if(m%10==0) /*��һ�������10������ʱ�����һ������*/ 
	  printf("\n");
      }
  }
  printf("\n1000���ڵ�������%d��",m);
	  return 0;
}
