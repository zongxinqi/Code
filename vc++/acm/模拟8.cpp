#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n --)
	{
		int d;
		float h,m;
		scanf("%d %f:%f",&d,&h,&m);
		if(d == 0) printf("%d %02.f:%02.f\n",d,h,m);
		else
		{
			int q = (int)(h * 60 + m);
			if(d % 2 == 0)
			{
				h = q/120 + 12;
				m = (q - (h - 12) * 120)/2;
				d /= 2;
			}
			else
			{
				h = q/120;
				m = (q- h * 120)/2;
				d = d/2 + 1;
			}
			printf("%d %02.f:%02.f\n",d,h,m);
		}
	}
}
