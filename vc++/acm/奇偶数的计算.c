#include<stdio.h>
#include<math.h>
int main()
{
	int x,y,m1,m2;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		m1 = m2 = 0;
	if(x<=y)
	{
			while(x<=y)
	{
		if(x%2==0) m1+=pow(x,2);
		else m2+=pow(x,3);
		x++;
	}
	}
	else
	while(y<=x)
	{
		if(y%2==0) m1+=pow(y,2);
		else m2+=pow(y,3);
		y++;
	}
	printf("%d %d\n",m1,m2);
	}
	return 0;
}
