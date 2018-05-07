#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
string a,b;
int dp[2][N] = {0};
bool now,pre;
int main(){
	int i,j;
	cin>>a>>b;
	for(now = 1,pre = 0,i = 0;i < a.length();i++){
		for(swap(now,pre),j = 0;j < b.length();j++){
			if(a[i] == b[j])dp[now][j+1] = dp[pre][j] + 1;
			else dp[now][j+1] = max(dp[now][j],dp[pre][j+1]);
		}
	}
	cout<<dp[now][b.length()];
	return 0;
}
