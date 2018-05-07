#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int vis[maxn];
int plen[maxn];
int path[maxn];
vector<pair<int,int> >G[maxn];
void Dij(int n,int s,int d){
	for(int i = 0;i < n;i++){
		vis[i] = 0;path[i] = -1;plen[i] = 0x3f3f3f3f;
	}
	plen[s] = 0;
	priority_queue<pair<int,int> >q;
	q.push({0,s});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0;i < (int)G[u].size();i++){
			int v = G[u][i].first, w = G[u][i].second;
			if(plen[v] > plen[u] + w){
				plen[v] = plen[u] + w;
				path[v] = u;
				q.push({-plen[v],v});
			}
		}
	}
	cout<<plen[d]<<endl;
	vector<int> path_array;path_array.push_back(d);
	while(1){
		d = path[d];
		if(d == -1) break;
		path_array.push_back(d);
	}
	for(int i = path_array.size()-1;i >= 0;i--)
	cout<<path_array[i]<<(i == 0?"":" ");
}
int main()
{		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,s,d;cin>>n>>m>>s>>d;
	for(int i = 0;i < m;i++){
		int a,b,c;cin>>a>>b>>c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	Dij(n,s,d);
	return 0;
}
