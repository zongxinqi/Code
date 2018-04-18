#include<bits/stdc++.h>
using namespace std;
const int maxn = 500;
int pa[maxn];
int vis[maxn];
int plen[maxn];
vector<pair<int,int> >G[maxn];
void Dij(int s,int d,int n){
	for(int i = 0;i < n;i++){
		pa[i] = -1;vis[i] = 0;plen[i] = 0x3f3f3f3f;
	}
	plen[s] = 0;
	priority_queue<pair<int,int> >q;
	q.push({0,s});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] =  1;
		for(int i = 0;i < (int)G[u].size();i++){
			int v = G[u][i].first,w = G[u][i].second;
			if(plen[u] + w < plen[v]){
				plen[v] = plen[u] + w;
				pa[v] = u;
				q.push({-plen[v],v});
			}
		}
	}
	cout<<plen[d]<<endl;
	vector<int> path; path.push_back(d);
	while(1){
		d = pa[d];
		if(d == - 1) break;
		path.push_back(d);
	}
	for(int i = path.size()- 1;i >= 0;i--) cout<<path[i]<<(i == 0?"":"->");
}
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	int n,m,s,d;cin>>n>>m>>s>>d;
	for(int i = 0;i < m;i++){
		int a,b,c;cin>>a>>b>>c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	Dij(s,d,n);
	return 0;
}
