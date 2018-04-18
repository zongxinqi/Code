#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct moon{
	float mo;
	float we;
	float co;
}M[maxn];
bool cmp(moon a,moon b){
	return a.co > b.co;
}
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	int n;cin>>n;
	float sum;cin>>sum;
	for(int i = 0;i < n;i++) cin>>M[i].we;
	for(int i = 0;i < n;i++){
		cin>>M[i].mo;
		M[i].co = M[i].mo/M[i].we;
	}
	sort(M,M+n,cmp);
	float ans = 0;
	for(int i = 0;i < n&&sum > 0;i++){
		if(M[i].we <= sum) {
			ans += M[i].mo;
			sum -= M[i].we;
		}
		else{
			ans += M[i].co * sum;
			sum = 0;
		}
	}
	printf("%.2f",ans);
	return 0;	
} 
