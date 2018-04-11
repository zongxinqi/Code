#include<stdio.h>
int main()         /*自增自减运算 */ 
{   
	int x=32,y=81,p,q;  
	p=x++;
	q=--y;
	printf("%d%d\n",p,q);
	printf("%d%d\n",x,y);
}
