#include<iostream>
#include<algorithm>
using namespace std;
int a[230][230]={0};
int sum(int l,int x,int y){
	return a[x][y]-a[x-l][y]-a[x][y-l]+a[x-l][y-l];
}
int main(){
	int n,m;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cin>>a[i][j];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			}
		}
		int ans=0;
		for(int i=1;i<=min(n,m);i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=m;k++){
					int t=sum(i,j,k);
					if(t==i*i||t==0) ans=i*i;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
