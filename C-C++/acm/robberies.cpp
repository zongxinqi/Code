#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	int t;cin>>t;
	while(t--){
		double p;int m; cin>>p>>m;
		int mo[maxn] = {0};
		double pi[maxn] = {0};
		double dp[maxn] = {0};
		int sum = 0;
		for(int i = 1;i <= m;i++){
			cin>>mo[i]>>pi[i];
			sum += mo[i];
		}
		dp[0] = 1;
		for(int i  = 1;i <= m;i++){
			for(int j = sum;j >= mo[i];j--){
				dp[j] = max(dp[j],dp[j - mo[i]]*(1 - pi[i]));
			}
		}
		for(int i = sum;i >= 0;i--){
			if(dp[i] > (1 - p)){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}