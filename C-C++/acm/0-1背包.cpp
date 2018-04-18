#include<bits/stdc++.h>
const int maxn = 1010;
using namespace std;
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	int n,v;cin>>n>>v;
	int p[maxn]= {0},q[maxn] = {0};
	int dp[maxn] = {0};
	for(int i = 1;i <= n;i++)
		cin>>p[i]>>q[i];
	for(int i = 1;i <= n;i++){
		for(int j = v;j >= p[i];j--){
			dp[j] = max(dp[j],dp[j - p[i]] + q[i]);
		}
	}
	cout<<dp[v];
	return 0;	
} 
