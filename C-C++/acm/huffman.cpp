#include<bits/stdc++.h>
using namespace std;
int cal(char x){
	if(x == '_') return 0;
	else return x - 'A' + 1;
}
struct node{
	int w;
	friend bool operator<(node aa,node bb){
		return aa.w > bb.w;
	}
};
int main()
{
	ios_base::sync_with_stdio();
	cin.tie();
	string s;
	while(cin>>s){
		if(s == "END") break;
		int a[30] = {0};
		for(int i = 0;i < s.length();i++) a[cal(s[i])]++;
		priority_queue<node> q;
		for(int i = 0;i < 27;i++){
			node b;
			b.w = a[i];
			if(a[i]) q.push(b);
		}
		int res;
		if(q.size() == 1) res = s.length();
		else{
			while(q.size() > 1){
				int aa = q.top().w;q.pop();
				int bb = q.top().w;q.pop();
				res += (aa + bb);
				node b;
				b.w = aa + bb;
				q.push(b);
			}
		}
		cout<<s.length()*8<<" "<<res<<" "<<s.length()*8/res<<endl;
	}
	return 0;
}
