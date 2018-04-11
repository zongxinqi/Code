#include<stdio.h>
main()
{
	float x = 2.5;
	float y = 4.7;
	int x1;
	float x2;
	int a = 7;
	int b = 3;

	x1 = a % 3 * (int)(x+y) % 2 / 4;
	printf("x1 =  %d\n",x1);
	a = 2;
	x = 3.5;
	y = 2.5;
	x2 = (float)(a+b)/2+(int)x%(int)y;
	printf("x2 =  %f\n",x2);
}
