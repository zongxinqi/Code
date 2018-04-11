#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int p;
	cin>>p;
	int n,m;
	getchar();
	string s;
	while(p--)
	{	
		cin>>s>>n>>m;
		if(n < 15||n > 20||m < 50||m > 70)
		{
		cout<<s;
		if(p) cout<<endl; 
		}
	}
	return 0;
}
