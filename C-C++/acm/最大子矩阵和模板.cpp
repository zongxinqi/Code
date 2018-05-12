#include<bits/stdc++.h>
using namespace std;
const int N  = 105;
const int INF = 0x3f3f3f3f;
int dp[N][N] = {0};
int main()
{
	int n;
	while(cin>>n){
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++){
				cin>>dp[i][j];
				dp[i][j] += dp[i][j-1];
			}
			int ans = 0;
			int res;
		for(int i = 1;i <= n;i++)
			for(int j = i;j <= n;j++)
				for(int k = 1,res = 0;k <= n;k++){
					res += dp[k][j] - dp[k][i-1];
					if(res < 0) res = 0;
					ans = max(ans,res);
				}
		cout<<ans<<endl;
	}
}
