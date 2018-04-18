#include<bits/stdc++.h>
using namespace std;
int dp[10010];
int mo[10010];
bool vis[10010][10010];
int main()
{
  ios::sync_with_stdio();
  cin.tie();
  int n,m;cin>>n>>m;
  for(int i = 1;i <= n;i++) cin>>mo[i];
    sort(mo+1,mo+n+1,greater<int>());
  for(int i = 1;i <= n;i++){
    for(int j = m;j >= mo[i];j--){
      if(dp[j] <= dp[j - mo[i]] + mo[i]){
        dp[j] = dp[j - mo[i]] + mo[i];
        vis[i][j] = true;
      }
    }
  }
  if(dp[m] != m) cout<<"No Solution";
  else{
    for(int i = n,j = m;i >= 1;i--){
      if(vis[i][j]) {
      	cout<<mo[i];
		  j -= mo[i]; 
		  if(j) cout<<" ";else cout<<endl;
	  }
    }
  }
  return 0;
}
