#include<iostream>
#include<cstring>
const int maxn = 1010;
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int fa[maxn] = {0};
		for(int i = 2;i < n;i++)
		cin>>fa[i];
		int q;
		cin>>q;
		while(q--)
		{
			int a,b;
			cin>>a>>b;
			int flag[maxn]; 
			memset(flag,0,sizeof(flag));
			while(fa[a] != 0)
			{
				a = fa[a];
				flag[a] = 1;
			}
			while(fa[b] != 0&& flag[b] == 0)
			b = fa[b];
			cout<<b<<endl; 
		}
	}
	return 0;
}
