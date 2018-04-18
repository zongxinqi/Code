#include<bits/stdc++.h>
using namespace std;
int ans = 101;
int bfs(int num,int aux,int m,int n)
{
	if(aux != (m+n)/2)
	{
		if(aux >= m)
		bfs(num++,aux-m,m,n);
		else if(aux >= n)
		bfs(num++,aux-n,m,n);
	}
	else ans = min(ans,num);
}
int main()
{
	int s,m,n,aux;
	scanf("%d%d%d",&s,&m,&n);
	bfs(0,aux,m,n);
	if(ans != 0)printf("%d\n",ans);
	else printf("NO\n");	
} 
