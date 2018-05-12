#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int dp[N][N] = {0};
int main()
{
	int t;cin>>t;
	while(t--){
		int n,m,x,y; cin>>n>>m>>x>>y;
		int ma = 0;
	for(int i = 1;i <= n;i++)	
		for(int j = 1;j <= m;j++){
			cin>>dp[i][j];
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			if(i >= x&&j >= y){
			ma = max(ma,dp[i][j] - dp[i-x][j]- dp[i][j-y] + dp[i-x][j-y]);
		}
	}
	cout<<ma<<endl;
	}
	return 0;
}
