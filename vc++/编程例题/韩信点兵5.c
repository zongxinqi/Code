#include<stdio.h>
int main()
{
	int x=1;
	int find=0;
	do
	{
		x++;
	}while(find==(x%5==1 && x%6==5 && x%7==4 && x%11==10));/*find==0,相等则为真继续循环，当符合条件时，
	0！=1，条件为假，结束循环*/
	printf("x=%d\n",x);
 } 
