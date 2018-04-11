#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	set<int> s[55];
	int n;cin>>n;
	for(int i = 1;i <= n;i++){
		int m;cin>>m;
		for(int j = 0;j < m;j++){
			int x;cin>>x;
			s[i].insert(x);
		}
	}
	int k;cin>>k;
	while(k--){
		int a,b;cin>>a>>b;
		set<int>::iterator p;
		int same = 0;
		for(p = s[a].begin();p != s[a].end();p++){
			if(s[b].find(*p) != s[b].end())
			same++;
		}
		double ans = same*1.0/(s[a].size() + s[b].size() - same);
		printf("%.2lf%%\n",ans*100);
	}
	return 0;
}
