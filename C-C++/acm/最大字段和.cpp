#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int dp[maxn];
int main()
{
	int t;cin>>t;
	for(int j = 1;j <= t;j++){
		int n;cin>>n;
		for(int i = 0;i < n;i++)cin>>dp[i];
		int ma = -maxn;
		int be = 0,end = 0;
		int aux = 0;
		for(int i = 1;i < n;i++){
			if(dp[i-1] >= 0) dp[i] = dp[i-1] + dp[i];
			else aux = i;
			if(dp[i] > ma){
				ma = dp[i];
				be = aux;
				end = i;
			}
		}
		cout<<"Case "<<j<<":"<<endl;
		cout<<ma<<" "<<be+1<<" "<<end+1;
		if(j != t) cout<<endl;
	}	
} 
