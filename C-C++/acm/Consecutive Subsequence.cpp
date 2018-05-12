#include<bits/stdc++.h>
using namespace std;
int n, a[200001], m, k, x;
map <int, int> mp, m1;
main ()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++) {cin>>a[i]; 
	if (mp[a[i]]<=mp[a[i]-1]+1) mp[a[i]]=mp[a[i]-1]+1;}
	for (int i=1; i<=n; i++) if (mp[a[i]]>m) m=mp[a[i]], k=a[i];
	cout<<m<<endl; x=k-m+1;
	for (int i=1; i<=n; i++)
	{
		if (a[i]==x) cout<<i<<" ", x++;
		if (x>k) break;
	}
	return 0;
}
