#include<iostream>
#include<algorithm>
using namespace std;
int ans=10;
int n,a,b;
void dfs(int num,int now,int ca,int cb){
	if(num>=ans) return;
	if(ca){
		if(now>=a) dfs(num,now-a,ca-1,cb);
		else dfs(num+1,n-a,ca-1,cb);
	}	
	if(cb){
		if(now>=b) dfs(num,now-b,ca,cb-1);
		else dfs(num+1,n-b,ca,cb-1);
	}
	if(ca==0&&cb==0) ans=min(ans,num);
}
int main(){
	cin>>n>>a>>b;
	dfs(1,n,4,2);
	cout<<ans<<endl;
	return 0;
}
