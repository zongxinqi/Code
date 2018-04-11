#include<stdio.h>
int main()
{
	int x;
	int find=0;/*定义标志变量，使结构更清晰*/
	for(x=1;!find;x++)
	if(x%5==1 && x%6==5 && x%7==4 && x%11==10)
	{
		printf("x=%d\n",x);
		find++;
	}
	printf("program is over!");
	return 0;
}
