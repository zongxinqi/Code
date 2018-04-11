#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1010;
string dele(string &s,int n)
{
	string::iterator st;
	int  flag;
	for(int i = n;i > 0;i--)
	{
		flag = 1;
		for(st = s.begin();st < s.end();st++)
		{
			if(*st > *(st + 1))
			{
				flag = 0;
				s.erase(st);
				break;
			}	
		}
		if(flag)
		s.erase(s.end() - i,s.end());	
	}
	return s; 
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		int n;
		cin>>s>>n;
		cout<<dele(s,n)<<endl;
	}
	return 0;
}
