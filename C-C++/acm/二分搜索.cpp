#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int num[maxn];
int find(int num[],int l,int r,int t){
	if(l > r) return 0;
	else{
		int mid = (l + r)/2;
		if(t > num[mid]) find(num,mid + 1,r,t);
		else if(t < num[mid]) find(num,l,mid,t);
		else return mid + 1;
	}
}
int main()
{
	ios_base::sync_with_stdio();
	cin.tie();
	int n,t;
	while(cin>>n>>t){
	for(int i = 0;i < n;i++) cin>>num[i];
	int ans;
	ans = find(num,0,n-1,t);
	cout<<ans<<endl;
	}
	return 0;	
} 
