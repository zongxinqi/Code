#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct day{
	int num;
	int beg;
	int end;
}D[maxn];
int vis[maxn] = {0};
int cmp(const void *a,const void *b){
	return (*(day*)a).end < (*(day*)b).end ? -1 : 1;
}
int main()
{
	ios_base::sync_with_stdio();
	cin.tie();
	int n;cin>>n;
	for(int i = 0;i < n;i++){
		int a,b,c;cin>>a>>b>>c;
		D[i].num = a;
		D[i].beg = b;
		D[i].end = c;
	}
	qsort(D,n,sizeof(D[0]),cmp);
	int tmp = 0;
	vis[tmp] = 1;
	int ans = 1;
	for(int i = 1;i < n;i++){
		if(D[i].beg >= D[tmp].end){
			ans++;
			vis[i] = 1;
			tmp = i;
		}
	}
	cout<<ans<<endl;
	for(int i = 0;i < n;i++){
		if(vis[i]) cout<<D[i].num<<" "<<D[i].beg<<" "<<D[i].end<<endl; 
	}
	return 0;
} 
