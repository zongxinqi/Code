#include<iostream>
#include<cstring>
#include<algorithm>
const int maxn = 1e5 + 5;
using namespace std;
int n,m;
int a[maxn];
int fun(int mid)
{
	int sum = 0;
	int len = 1;
	for(int i = 1;i < n;i++)
	{
		if(sum + a[i] - a[i - 1] < mid)
			sum += a[i] - a[i - 1];
		else
		{
			sum = 0;
			len++;
		}
	}
	if(len < m) return false;
	else return true;
} 
int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		for(int i = 0;i < n;i++)
		cin>>a[i];
		sort(a,a + n);
		int low = a[n - 1] - a[0];
		int high = a[n - 1] - a[0];
		for(int i = 1;i < n;i++)
		low = min(low,a[i] - a[i - 1]);
		while(low <= high)
		{
			int mid = (low + high)/2;
			if(fun(mid))
			low = mid + 1;
			else
			high = mid - 1;
		}
		cout<<high;
	}
	return 0;
}
