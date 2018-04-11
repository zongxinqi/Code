#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s,a,b;
	int count = 0;
	cin>>s;
	while(s != ".")
	{	
		count++;
		if(count == 2) a = s;
		if(count == 14) b = s;
		cin>>s;
	}
	if(count >= 14) cout<<a<<" and "<< b<<" are inviting you to dinner...";
	else if(count >= 2&& count < 14) cout<<a<<" is the only one for you...";
	else if(count  < 2) cout<<"Momo... No one is for you ...";
	return 0;
}
