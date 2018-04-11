#include<bits/stdc++.h>
using namespace std;
bool isM;
vector<int> pre;
vector<int> post;
void getpost(int root,int tail){
	if(root > tail) return;
	int i = root+1,j = tail;
	if(!isM){
		while(i <= tail&&pre[root] > pre[i]) i++;
		while(j > root&&pre[root] <= pre[j]) j--;
	}
	else{
		while(i <= tail&&pre[root] <= pre[i]) i++;
		while(j > root&&pre[root] > pre[j]) j--;
	}
	if(i - j != 1) return;
	getpost(root+1,j);
	getpost(i,tail);
	post.push_back(pre[root]);
}
int main()
{
	ios::sync_with_stdio();
	cin.tie();
	int n;cin>>n;
	pre.resize(n);
	for(int i = 0;i < n;i++)cin>>pre[i];
	getpost(0,n-1);
	if(post.size() != n){
		isM = true;
		post.clear();
		getpost(0,n-1);
	}
	if(post.size() == n){
		cout<<"YES\n"<<post[0];
		for(int i = 1;i < n;i++)
		cout<<" "<<post[i];
	}
	else cout<<"NO";
	return 0;
}
