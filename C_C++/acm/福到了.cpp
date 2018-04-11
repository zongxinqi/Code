#include<bits/stdc++.h>
using namespace std;
int main()
{
	char c;
	int n;
	cin>>c>>n;
	getchar();
	string s[101];
	int flag = 0;
	for(int i = 0;i < n;i++)
	{
		getline(cin,s[i]);
		for(int j = 0;j < n;j++)
		{
			if(s[i][j] == '@') s[i][j] = c;	
		} 
	}
	int k = n;
	for(int i = 0;i < n/2;i++)
	{
		if(i == (n/2 - 1)&&(n % 2 == 0)) k = n/2;	
		for(int j = 0;j < k;j++)
		{
			if(s[i][j] != s[k-i-1][k-j-1])
			flag = 1;
		}
	}
	if(flag == 0) cout<<"bu yong dao le"<<endl;
	for(int i = n-1;i >=0;i--)
	{
		for(int j = n-1;j >= 0;j--)
		cout<<s[i][j];
		cout<<endl;
	}
	return 0;
}
