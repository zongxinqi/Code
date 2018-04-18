#include<bits/stdc++.h>
using  namespace std;
const int maxn = 1010;
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	int n;
	while(cin>>n&&n){
		int p[maxn] = {0};
		int dp[maxn] = {0};
	for(int i = 1;i <= n;i++)cin>>p[i];
		sort(p+1,p+n+1);
		int m;cin>>m;
		if(m < 5) cout<<m<<endl;
		else{
			for(int i = 1;i < n;i++){
			for(int j = m-5;j >= p[i];j--){
				dp[j] = max(dp[j],dp[j - p[i]] + p[i]);
			}
		}
		cout<<m-p[n]-dp[m-5]<<endl;
		}
	}
	return 0;
}
