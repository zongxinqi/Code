#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;int i,id;string s,ans;
int main(){
	for(cin>>i>>s,i = 1;i < s.size();i++) mp[s.substr(i-1,2)]++;
	for(auto&x:mp)if(x.second > id) ans = x.first,id = x.second;
	cout<<ans<<endl;
}
