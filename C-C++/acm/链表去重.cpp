#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 1e5+5;
struct node
{
	int data;
	int next;
};
node p[maxn],pa[maxn],pb[maxn];
int vis[maxn] = {0};
int main()
{
	int st,n;
	cin>>st>>n;
	int a,b,c;
	for(int i = 0;i < n;i++)
	{
		cin>>a>>b>>c;
		p[a].data = b;
		p[a].next = c;	
	}	
	int pat = 0;
	int pbt = 0;
	for(int i = st;i != -1;i = p[i].next)
	{
		int k = abs(p[i].data);
		if(vis[k] == 0)
		{
			vis[k] = 1;
			pa[pat].data = p[i].data;
			pa[pat].next = i;
			pat++;
		}
		else
		{
			pb[pbt].data = p[i].data;
			pb[pbt].next = i;
			pbt++;
		}
	}
	for(int i = 0;i < pat;i++)
	{
		printf("%05d %d ",pa[i].next,pa[i].data);
		if(i == pat-1) printf("-1\n");
		else printf("%05d\n",pa[i+1].next);
	}
	for(int i = 0;i < pbt;i++)
	{
		printf("%05d %d ",pb[i].next,pb[i].data);
		if(i == pbt-1) printf("-1\n");
		else printf("%05d\n",pb[i+1].next);
	}
	return 0;	
} 
