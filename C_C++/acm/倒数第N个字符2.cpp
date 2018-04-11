#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	int L,n;
	cin>>L>>n;
	int a[L+1];
	for(int i = 1;i <= L;i++) a[i] = 25;
	for(int i = 1;i < n;i++){
		if(a[L]) a[L]--;
		else{
			for(int j = L-1;j > 0;j--){
				if(a[j]){
					a[j]--;
					for(int k = j+1;k <= L;k++)a[k] = 25;
					break;
				}
			}
		}
	}
	for(int i = 1;i <= L;i++)
	cout<<(char)('a' + a[i]); 
	return 0;	
} 
