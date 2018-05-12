#include<bits/stdc++.h>
using namespace std;

int used[260] = {0};
int mp[260]; 
int main()
{
	int n,k;cin>>n>>k;
	for(int i = 0;i <= 260;i++)mp[i] = i;
	for(int i = 0;i < n;i++){
		int a;
		cin>>a;
		int t = a;
		if(!used[a]){
			while(t >= 0&&a - mp[t] < k) t--;
			t++;
			for(int i = t;i <= a;i++){
				mp[i] = t;
				used[i] = 1;
			}
		}
		cout<<mp[a]<<" ";
	}
}
