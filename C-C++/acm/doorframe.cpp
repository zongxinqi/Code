#include<cstdio>
#include<algorithm>
using namespace std;
int ans = 10;
int n,a,b;
void dfs(int num,int now,int ca,int cb)
{
	if(num > ans) return;
	if(ca)
	{
		if(now >= a) dfs(num,now-a,ca-1,cb);
		else dfs(num+1,n-a,ca-1,cb);
	}
	if(cb)
	{
		if(now >= b) dfs(num,now-b,ca,cb-1);
		else dfs(num+1,n-b,ca,cb-1);
	}
	if(ca == 0&&cb == 0) ans = min(ans,num);
}
int main()
{
    while(scanf("%d%d%d",&n,&a,&b)!=EOF)
    {
    	dfs(1,n,4,2);
    	printf("%d\n",ans);
	}
	return 0;
}
