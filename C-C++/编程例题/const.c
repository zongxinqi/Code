#include <stdio.h>
int main()    
{
	const float r=10;
	int a,b=3;
        a=r%b;         /*前面已经定义了r为实型数不能进行求余运算 */ 
	printf("a=%d\n",a);
}            

