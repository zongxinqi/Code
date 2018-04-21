#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	float h[maxn] = {0};
	for(int i = 1;i <= n;i++) cin>>h[i];
	int i = 1,aux = h[1],ct = 1;
	float ans[maxn];
	for(int i = 1;i <= n;i++){
		int j = h[i];
		if(j - aux > 2000){
				aux = j;
			 	ct++;
			 	if(abs(h[i+1] - aux) > 2000) ans[ct] = aux;
		}
		else 
			ans[ct] = (j - aux)*1.0/2 + aux;
	}
	cout<<ct<<endl;
	for(int i = 1;i <= ct;i++)
	cout<<ans[i]<<" ";
	return 0; 
}
