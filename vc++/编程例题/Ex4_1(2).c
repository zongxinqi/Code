#include<stdio.h>
int main()
{
	float t,w,h;
	scanf("%f,%f",&w,&h);
	t=w/(h*h);
	if(t<18)
	{
		printf("thin");
	}
	else if(t>=18&&t<=25)
	{
		printf("normal");
	}
	else if(t>25&&t<27)
	{printf("fat");
	}
	else if(t>=27)
	{
		printf("overweight");
	}
	return 0;
}
