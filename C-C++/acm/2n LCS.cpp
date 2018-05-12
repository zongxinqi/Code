#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
string a,b;
int dp[2][N] = {0};
bool now,pre;
int vis[N][N];

int print(int i,int j){
	if(vis[i][j] == 1){
		print(i-1,j-1);
		cout<<b[j-1];
	}
	else if(vis[i][j] == 2) print(i,j-1);
	else if(vis[i][j] == 3) print(i-1,j);
}

int main(){
	int i,j;
	cin>>a>>b;
	int len = 1;
	memset(vis,0,sizeof(vis));
	for(now = 1,pre = 0,i = 0;i < a.length();i++){
		for(swap(now,pre),j = 0;j < b.length();j++){
			if(a[i] == b[j]){
				dp[now][j+1] = dp[pre][j] + 1;
				vis[i+1][j+1] = 1;
			}
			else if(dp[now][j] >= dp[pre][j+1]){
				dp[now][j+1]=dp[now][j];
				vis[i+1][j+1] = 2;
			}
			else if(dp[now][j] < dp[pre][j+1]){
				dp[now][j+1]=dp[pre][j+1];
				vis[i+1][j+1] = 3;
			}
		}
	}
	for ( int i = 0; i <= a.length(); i++ ) {
		for ( int j = 0; j <= b.length(); j++ ) {
			cout << vis[ i ][ j ] << ' ';
		}
		cout << endl;
	}
	print(a.length(),b.length());
	cout<<dp[now][b.length()];
	return 0;
}
