#include<cstdio> 
#include<algorithm>
using namespace std;
int a[100],dp[100];

int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(a[i]>a[j]) {
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
