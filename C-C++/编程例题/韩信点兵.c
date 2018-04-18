#include<stdio.h>
int main()
{
	int x;
	for(x=1;;x++)
	{
		if(x%5==1&&x%6==5&&x%7==4&&x%11==10)
	{	printf("x=%d\n",x);
		break;/*在找到一个合适的数后就跳出循环，如果不加就会在输出多个结果中陷入死循环。*/
		}
	}
	printf("program is over");
	return 0;
}
