#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,a[100],s;
	while(cin>>n)
	{
		s=0;
		for(int i=0;i<n;i++)
		{
		cin>>a[i];
		s+=a[i];
		}
        sort(a,n+a);
	    cout<<fixed<<setprecision(2)<<(double)(s-a[0]-a[n-1])/(n-2)<<endl;
	}
}
