#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
#define inf 0x3f3f3f3f
int pre[maxn];
int ans[maxn];
int mo[maxn];
int dp[maxn];
void print(int u){
	if(!pre[u]){
		cout<<ans[u];return ;
	}
	print(pre[u]);
	cout<<" "<<ans[u];
}
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	int n,m; cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>mo[i];
		memset(dp,-inf,sizeof(dp));
		memset(pre,-1,sizeof(pre));
		dp[0] = 0;
		sort(mo+1,mo+n+1);
	for(int i = 1;i <= n;i++){
		for(int j = m;j >= mo[i];j--){
			if(dp[j] <= dp[j - mo[i]] + 1){
				dp[j] = dp[j - mo[i]] + 1;
				ans[j] = mo[i];
				pre[j] = j - mo[i];
			}
		}
	}
	if(dp[m] > 0) print(m);
	else cout<<"No Solution";
	return 0;
}
