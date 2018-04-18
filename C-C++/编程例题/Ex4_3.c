#include <stdio.h>
int main()
{
	float x;
	printf("please input x:");
	scanf("%f",&x);
	if(x>=90)
	{printf("A");
	}
	else if(x>=80&&x<89)
	{printf("B");
	}
	else if(x>=70&&x<79)
	{printf("C");
	}
	else if(x>=60&&x<70)
	{printf("D");
	}
	else if(x<60)
	{printf("E");
	}
	return 0;
}
