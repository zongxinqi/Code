#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--){
		int n,x;cin>>n>>x;
		double pi = acos(-1);
		double ans = pow(n,pi);
		if(x == 1) printf("%.1lf\n",ans);
		else if(x == 2) printf("%.2lf\n",ans);
		else if(x == 3) printf("%.3lf\n",ans);
		else if(x == 4) printf("%.4lf\n",ans);
		else if(x == 5) printf("%.5lf\n",ans);
	}
	return 0;
}

