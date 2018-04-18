#include<stdio.h>
int main()
{
	int a,b,c,n,i;
	float num;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		a = b = c = 0;
		for(i = 0; i < n;i++)
	{
		scanf("%f",&num);
		if(num < 0) a++;
		else if(num == 0) b++;
		else c++;
	}
	printf("%d %d %d\n",a,b,c);
	}

	return 0;
}
