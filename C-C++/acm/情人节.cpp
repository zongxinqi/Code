#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s;
	string a;
	string b;
	int n  = 0;
	cin>>s;
	while(s != ".")
	{
		n++;
		if(n == 2) a = s;
		if(n == 14) b = s;
		cin>>s;
	}
	if(n >= 14)
	cout<<a<<" and "<<b<<" are inviting you to dinner...";
	else if(n >= 2&&n < 14) 
	cout<<a<<" is the only one for you...";
	else if(n < 2)
	cout<<"Momo... No one is for you ...";
	return 0;
}
