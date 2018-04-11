#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn 1000
#define percision 0.00001
using namespace std;
struct tnode{double d,p;}a[maxn + 10];
double d1,c,d2,p;
int n;
bool cmp(tnode xx,tnode yy)
{
	return xx.d < yy.d;
}
int main()
{
	int i,j,k;
	double x,y,ans,s;
	scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&p,&n);
	a[1].d = 0,a[1].p = p;
	a[2].d = d1,a[2].p = 0;
	for(n+=2,i = 3;i <= n;i++)scanf("%lf%lf",&a[i].d,&a[i].p);
	sort(a+1,a+n+1,cmp);
	k = 1,ans = x = 0,s = c*d2;
	while(k <= n)
	{
		if(a[k+1].d - a[k].d > s){printf("No Solution\n");return 0;}
		for(j = k+1;a[j].d - a[k].d <= s&&j <= n;j++)
			if(a[j].p <= a[k].p)
			{
				y = (a[j].d - a[k].d)/d2;
				if(x < y) ans += a[k].p*(y - x),x = 0;
				else x-=y;
				k = j;
				break;
			}
			if(fabs(a[k].d - d1) <= percision)
			{
				printf("%.2lf\n",ans);
				return 0;
			}
			if(j != k)
			{
				ans += a[k].p * (c - x);
				x = c - (a[k+1].d - a[k].d)/d2;
				k++;
			}
	}
	return 0;
}
