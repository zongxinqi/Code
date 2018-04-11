#include<iostream>
using namespace std;
int main()
{
	int n;
	char c;
	cin>>n>>c;
	for(int i = 0;i < (n + 1)/2;i++)
	{
		for(int j = 0;j < n;j++)
		cout<<c;
		cout<<endl;
	}
	return 0;
}
