#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main(void)
{
	int i,n,s[100];
	double sum;
	while(cin>>n)
	{
		sum = 0;
		for(i = 0;i < n;i++)
		{
			cin>>s[i];
			sum+=s[i];
		}
		sort(s,s+n);
		cout<<fixed<<setprecision(2)<<(sum - s[0] - s[n-1])/(n-2)<<endl;
	}
}
