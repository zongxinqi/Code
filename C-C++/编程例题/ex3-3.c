#include<stdio.h>
#include<math.h> 
#define rate 0.0225
int main()    /* ��������ı�Ϣ�� */ 
{
  int capital,n;
  float deposit;
  printf("input capital,n:");
  scanf("%d,%d",&capital,&n);
  printf("deposit=%f\n",capital*pow((1+rate),n));
}    
