#include<bits/stdc++.h>
using namespace std;
int check(string s)
{
	for(int i = 0;i < s.length();i++){
		if(!isdigit(s[i])) return 1;
	}
	return 0;
}
int main()
{
	string s;
	getline(cin,s);
	string a,b;
	for(int i =0;i < s.length();i++){
		if(s[i] == ' ') {
			a = s.substr(0,i);
			b = s.substr(i + 1);
			break;
		}
	}
	if(a.length() == 0) a = "?";
	else if(check(a)||stoll(a) < 1|| stoll(a) > 1000) a = "?";
	if(check(b)||stoll(b) < 1|| stoll(b) > 1000) b = "?";
	cout<<a<<" + "<<b<<" = ";
	if(a == "?"||b == "?") cout<<"?";
	else cout<<stoll(a) + stoll(b);
	cout<<endl;
	return 0;
}
