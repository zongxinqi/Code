#include<bits/stdc++.h>
using namespace std;
int t[1005][1005];
int dp[1005][1005];
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	int h;cin>>h;
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= i;j++)
		{
			cin>>t[i][j];
			if(i == h) dp[i][j] = t[i][j];
		}
	}
	for(int i = h;i >= 1;i--){
		for(int j = 1;j <= i;j++)
		dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + t[i][j];
	}
	cout<<dp[1][1]<<endl;
	cout<<t[1][1];
	int j = 1;
	for(int i = 2;i <= h;i++){
		if(dp[i-1][j] - t[i-1][j] == dp[i][j+1]) j++;
		cout<<" "<<t[i][j];
	}
	return 0;
 } 
