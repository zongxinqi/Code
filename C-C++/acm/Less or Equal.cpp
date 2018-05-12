#include<bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5+10;
int a[maxn];
int main(){
	int n,k;cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i];
	a[0] = 1;a[n+1] = 1e9+1;
	sort(a,a+n+2);
	if(a[k] == a[k+1])cout<<"-1"<<endl;else cout<<a[k]<<endl;
	return 0;
}
