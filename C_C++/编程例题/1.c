#include <stdio.h>
int main ()
{
	int a,b;
	scanf("%d%*c%d",&a,&b);
	printf("a=%d\nb=%d\n",a,b);/*忽略修饰字符来实现用户以任意字符作为分隔符进行数据的输入。*/ 
	
 } 
