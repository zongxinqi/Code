#include<stdio.h>
int main()
{
	int x=1;
	do
	{
		x++;
	}while(!(x%5==1 && x%6==5 && x%7==4 && x%11==10));/*条件为真，继续执行，知道符合后面的方程，判断条件
	为假，结束循环*/
	printf("x=%d\n",x);
	printf("program is over");
	return 0;
	
}
