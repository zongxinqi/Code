#include<bits/stdc++.h>
const int maxn = 100 + 10;
using namespace std;
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	int n;cin>>n;
	vector<int> a[maxn];
	int b[maxn];
	int sum = 0;
	for(int i = 0;i < n;i++){
		cin>>b[i];
		sum+=b[i]*10;
	}
	int ans = 1,ct = 0;
	while(sum--){
		for(int i = 0;i < n;i++){
			if(a[i].size() < b[i]*10){
				a[i].push_back(ans);
				if(ct == n-1) ans+=2;
				ans++;
			}
		}
	}
	for(int i = 0;i < n;i++){
		cout<<"#"<<i+1<<endl;
		for(int j = 0;j < a[i].size();j++){
		cout<<a[i][j];
		cout<<(j%10==9?'\n':' ');	
		}
	}
	return 0;	
} 
