#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int main()
{
	int n,m;
	while(cin>>n&&n){
		cin>>m;
		int v[maxn] = {0};
		int dp[maxn] = {0};
		int vis[25][maxn] = {0};
		for(int i = 1;i <= m;i++) cin>>v[i];
		for(int i = 1;i <= m;i++){
			for(int j = n;j >= v[i];j--){
				if(dp[j] < dp[j - v[i]] + v[i])
					vis[i][j] = 1;
			}
		}
		vector<int> path;
		for(int i = m,j = n;i >= 1;i--){
			if(vis[i][j]){
				path.push_back(v[i]);
				j -= v[i];
			}
		}
		for(int i = path.size()-1;i >= 0;i--)
			cout<<path[i]<<" ";
		cout<<"sum:"<<dp[n]<<endl;
	}
	return 0;
}