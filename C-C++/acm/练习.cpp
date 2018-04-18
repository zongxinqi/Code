#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
struct moon{
	double num;
	double mon;
	double co;
}M[maxn];
int cmp(const void *a,const void*b){
	return (*(moon*)a).co > (*(moon*)b).co ? -1 : 1;
}
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	int n,sum;cin>>n>>sum;
	for(int i = 0;i < n;i++)	cin>>M[i].num;
	for(int i = 0;i < n;i++){
		cin>>M[i].mon;
		M[i].co = M[i].mon/M[i].num;
	}
	qsort(M,n,sizeof(M[0]),cmp);
	double ans = 0;
	for(int i = 0;i < n&&sum > 0;i++){
		if(M[i].num >= sum){
			ans += sum*M[i].co;
			sum = 0;
		}
		else{
			ans += M[i].mon;
			sum -= M[i].num;
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
