#include<bits/stdc++.h>
using namespace std;
const int maxn = 200;
int sx,sy,ex,ey;
int n;
int dir[4][2] = {{-1,0},{0,1},{0,-1},{1,0}};
int Map[maxn][maxn];
int vis[maxn][maxn];
struct node{
	int x;
	int y;
	long long num;
	friend bool operator<(node a,node b){
		return a.num > b.num;
	}
};
int bfs(){
	node cur,nex;
	priority_queue<node>qu;
	memset(vis,-1,sizeof(vis));
	cur.x = sx;
	cur.y = sy;
	cur.num = 0;
	vis[sx][sy] = 0;
	qu.push(cur);
	while(!qu.empty()){
		cur = qu.top();
		qu.pop();
		if(cur.x == ex&&cur.y == ey){
			return cur.num;
		}
		for(int i = 0;i < 4;i++){
			nex.x = cur.x + dir[i][0];
			nex.y = cur.y + dir[i][1];
			if(nex.x >= 1&&nex.x <= n&&nex.y >= 1&&nex.y <= n){
				if(vis[nex.x][nex.y] == -1){
					nex.num = cur.num + Map[nex.x][nex.y];
					vis[nex.x][nex.y] = nex.num;
					qu.push(nex);
				}
				else if(cur.num + Map[nex.x][nex.y] < vis[nex.x][nex.y]){
					nex.num = cur.num + Map[nex.x][nex.y];
					vis[nex.x][nex.y] = nex.num;
					qu.push(nex);
				}
			}
		}
	}
	return -1;
}
int main()
{
	while(cin>>n){
		for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>Map[i][j];
			if(Map[i][j] == -1){
				sx = i;
				sy = j;
				Map[i][j] = 0;
			}
			else if(Map[i][j] == -2){
				ex = i;
				ey = j;
				Map[i][j] = 0;
			}
		}
	}
	int ans = bfs();
	cout<<ans<<endl;
	}
	return 0;
 } 
