#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int a[maxn],b[maxn];
struct node{
	int l,r;
}c[maxn];
int build(int la,int ra,int lb,int rb)
{
	if(la > ra) return 0;
	else
	{
		int w = b[rb];
		int p = la;
		while(a[p] != w) p++;
		c[w].l = build(la,p-1,lb,lb+p-la-1);
		c[w].r = build(p+1,ra,lb+p-la,rb-1);
		return w;	
	} 
}
void dfs(int x)
{
	vector<int>v;
	queue<int>q;
	q.push(x);
	while(!q.empty())
	{
		int ro = q.front();
		q.pop();
		if(ro == 0) break;
		else v.push_back(ro);
		if(c[ro].l != 0)
		q.push(c[ro].l);
		if(c[ro].r != 0)
		q.push(c[ro].r);
	}
	for(int i =0;i < v.size();i++)
	{
		printf("%d%c",v[i],i == v.size()-1?'\n':' ');
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i =0;i < n;i++)
	cin>>b[i];
	for(int i = 0;i < n;i++)
	cin>>a[i];
	build(0,n-1,0,n-1);
	dfs(b[n-1]);
	return 0;
}
