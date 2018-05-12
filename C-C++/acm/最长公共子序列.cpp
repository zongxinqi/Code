#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int dp[maxn][maxn];
int vis[maxn][maxn] = {0};
string a,b;
void print(int i,int j){
	if(!i && !j) return ;
	if(vis[i][j] == 1){
		print(i-1,j-1);
		cout<<a[i-1];
	}
	else if(vis[i][j] == 2) print(i-1,j);
	else print(i,j-1);
}
int main()
{
	cin>>a>>b;
	for(int i = 0;i <= a.length();i++) dp[i][0] = 0;
	for(int j = 0;j <= b.length();j++) dp[0][j] = 0;
	for(int i = 1;i <= a.length();i++){
		for(int j = 1;j <= b.length();j++){
			if(a[i-1] == b[j-1]){dp[i][j] = dp[i-1][j-1] + 1;vis[i][j] = 1;}
			else if(dp[i-1][j] > dp[i][j-1]){dp[i][j] = dp[i-1][j];vis[i][j] = 2;}
			else {dp[i][j] = dp[i][j-1];vis[i][j] = 3;}
		}
	}
	cout<<dp[a.length()][b.length()]<<endl;
	print(a.length(),b.length());
	return 0;
} 
