#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int h,m;
	scanf("%d:%d",&h,&m);
	if(m == 0)
	{
		if(h >= 0 &&h <= 12) printf("Only %02d:%02d. Too early  to Dang.",h,m);
		else 
		{
			for(int i = 0;i < h - 12;i++)
			printf("Dang");
			printf("\n");
		}
	}
	else 
	{
		if(h >= 0&& h < 12) printf("Only %02d:%02d.  Too early to Dang.",h,m);
		else 
		{
			for(int i = 0;i < h - 11;i++)
			printf("Dang");
			printf("\n");
		}
	}
	return 0;
} 
