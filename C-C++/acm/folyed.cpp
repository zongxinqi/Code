#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
const int maxn = 100;
int plen[maxn][maxn];
int path[maxn][maxn];
int arcs[maxn][maxn];
int n;
using namespace std;
void floyed(int arcs[maxn][maxn],int n){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			plen[i][j] = arcs[i][j];
			path[i][j] = -1;
		}
	}
	for(int k = 0;k < n;k++){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(plen[i][j] > plen[i][k] + plen[k][j]){
					plen[i][j] = plen[i][k] + plen[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(i != j){
				cout<<i<<"->"<<j<<",";
				if(plen[i][j] == INF) cout<<"not exist";
				else{
					cout<<plen[i][j]<<" ";
					cout<<i<<",";
					int pre = path[i][j];
					while(pre != -1){
						cout<<pre<<",";
						pre = path[pre][j];
					}
					cout<<j<<endl;
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++)cin>>arcs[i][j];
	}
	floyed(arcs,n);
	return 0;
}
