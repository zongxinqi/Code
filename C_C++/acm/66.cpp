#include<cstdio>

int a[100];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=a[j];
			ans=max(ans,sum);
		}
	}
	int ans=0,sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		ans=max(ans,sum);
		if(sum<0){
			sum=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
