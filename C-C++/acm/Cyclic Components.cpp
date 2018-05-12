#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+10;
vector<int> G[N];
bool vis[N];
bool g;
void dfs(int x){
	vis[x] = 1;
	if(G[x].size() != 2) g = 0;
	for(auto i:G[x]){
		if(!vis[i]) dfs(i);
	}
}
int main(){
	int n,m,i,ans = 0;
	for(cin>>n>>m,i = 1;i <= m;i++){
		int a,b;cin>>a>>b;
		G[a].push_back(b);G[b].push_back(a);
	}
	for(int i = 1;i <= n;i++){
		g = 1;
		if(!vis[i]){
			dfs(i);
			if(g) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
