#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int num[1005] = {0};
	int s;
	for(int i = 0;i < n;i++)
	{
		int m;
		cin>>m;
		for(int j = 0;j < m;j++)
		{
			cin>>s;
			num[s]++;
		}
	}
	int maxx = 0;
	for(int i = 1;i <= 1000;i++)
	{
		if(num[i] >= maxx)
		{
			maxx = num[i];
			s = i;
		}
	}
	cout<<s<<" "<<maxx;
	return 0;
}
