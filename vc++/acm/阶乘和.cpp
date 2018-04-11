#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sum = 1;
	int res = 1;
	if(n == 0||n == 1) sum = 1;
	if(n >= 2)
	{
		for(int i = 2;i <= n;i++)
	{
		res*=i;
		sum+=res;
	}
	}
	cout<<sum;
	return 0;
}
