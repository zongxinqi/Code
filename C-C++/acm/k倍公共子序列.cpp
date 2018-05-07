#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
vector<int>x[maxn],y[maxn];
int dp[maxn][maxn] = {0};
int main()
{
	int n,m,k;cin>>n>>m>>k;
	vector<int>a(n+1),b(m+1);
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int j = 1;j <= m;j++)cin>>b[j];
	for(int i = 1;i <= n;i++){
		int u = a[i];
		x[u].push_back(i);
		for(int j = 0;j < 10;j++) y[j].clear();
		for(int j = 1;j <= m;j++){
			int v = b[j];
			y[v].push_back(j);
			if(u == v&&x[u].size() >= k&&y[v].size() >= k){
				int c = x[u].size() - k;
				int d = y[v].size() - k;
				dp[i][j] = dp[c-1][d-1] + 1;
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[n][m]*k<<endl;
	return 0;	
} 
