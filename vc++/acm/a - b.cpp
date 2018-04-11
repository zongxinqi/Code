#include<bits/stdc++.h>
typedef long long LL;
const int maxn = 1e4 +10;
using namespace std;
int main()
{
	int flag[256] = {0};
	char a[maxn];
	char b[maxn];
	gets(a);
	gets(b);
	for(int i = 0;i < strlen(b);i++)
		flag[b[i]] = 1;
	for(int i = 0;i < strlen(a);i++)
	{
		if(flag[a[i]] == 0) cout<<a[i];
	}
	return 0;
}
