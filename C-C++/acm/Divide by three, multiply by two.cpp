#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	LL a,b;
}A[110];
int cmp(node m,node n){
	if(m.b == n.b) return m.a < n.a;
	else return m.b > n.b;
}
int main()
{
	int n;cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>A[i].a;
		LL k = A[i].a;
		while(k % 3 == 0&&k){
			A[i].b++;
			k /= 3;
		}
	}
	sort(A+1,A+n+1,cmp);
	for(int i = 1;i <= n;i++) cout<<A[i].a<<" ";
	return 0;
}
