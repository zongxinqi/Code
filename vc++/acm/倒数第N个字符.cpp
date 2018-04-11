#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l,n;
	cin>>l>>n;
	int ans = pow(26,l)	- n;
	string s;
	for(int i = 0;i < l;i++)
	{
		s.push_back(ans%26 + 'a');
		ans /= 26;
	}
	reverse(s.begin(),s.end());
	cout<<s;	
	return 0;
} 
