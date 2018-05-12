#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	int l = 0,p = 0;
	for(char c:s)(c == 'o'?p:l)++;
	cout<<((p == 0||l%p==0)?"YES":"NO");
	return 0;
}
