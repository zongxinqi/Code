#include<bits/stdc++.h>
using namespace std;
int n;
queue<char> s;
void dfs(int i,int j)
{
	if(i == 0|| j == 0) return ;
	int a = i,b = j; 
	if(i){
		if(i%10 == 0 || i%10 == 1){
			s.push('0' + a/n);
			dfs(i*10,i*10+1);
		}
	}
	if(j){
		if(j%10 == 0 || j%10 == 1){
		s.push('0' + b/n);
		dfs(j*10,j*10+1);
		}
	}
}
int main()
{
	cin>>n;
	dfs(10,11);
	while(!s.empty())
	{
		cout<<s.front();
		s.pop();
	}
	return 0;
}
