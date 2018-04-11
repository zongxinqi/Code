#include<bits/stdc++.h>
using namespace std;
const int maxn = 530;
vector<pair<int,int> >G[maxn];
int plen[maxn];
int pwe[maxn];
int path[maxn];
int pn[maxn]; 
int suv[maxn] = {0};
int vis[maxn];
void Dij(int s,int d,int n)
{
	for(int i = 0;i < n;i++)
	{
		plen[i] = 0x3f3f3f3f;pwe[i] = 0;vis[i] = 0;pn[i] = 0;path[i] = -1;
	}
	pwe[s] = suv[s];
	plen[s] = 0;
	pn[s] = 1;
	priority_queue<pair<int,int> >q;
	q.push({0,s});
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0;i < (int)G[u].size();i++)
		{
			int v = G[u][i].first,w = G[u][i].second;
			if(plen[v] > plen[u] + w)
			{
				plen[v] = plen[u] + w;
				path[v] = u;
				pn[v] = pn[u];
				pwe[v] = pwe[u] + suv[v];
				q.push({-plen[v],v});
			}
			else if(plen[v] == plen[u] + w)
			{
				pn[v] += pn[u];
				if(pwe[v] < pwe[u] + suv[v])
				{
					pwe[v] = pwe[u] + suv[v];
					path[v] = u;
				}
			}
		}
	}
	cout<<pn[d]<<" "<<pwe[d]<<endl;
	vector<int> path_array; path_array.push_back(d);
	while(1)
	{
		d = path[d];
		if(d == -1)
		break;
		path_array.push_back(d);
	}
	for(int i = path_array.size() - 1;i >= 0;i--)
	{
		cout<<path_array[i];
		if(i) cout<<" ";
	}
	cout<<endl;
}
int main()
{
	int n,m,s,d;
	cin>>n>>m>>s>>d;
	for(int i = 0;i < n;i++)
	cin>>suv[i];
	for(int i = 0;i < m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push_back({b,c});
		G[b].push_back({a,c}); 
	}
	Dij(s,d,n);
	return 0;
}
