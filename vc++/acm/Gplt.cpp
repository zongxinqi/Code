#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int a = 0,b = 0,c = 0,d = 0;
	string s;
	cin>>s;
	for(int i = 0;i < s.length();i++)
	{
		if(s[i] == 'G'||s[i] == 'g')
		a++;
		else if(s[i] == 'P'||s[i] == 'p')
		b++;
		else if(s[i] == 'L'||s[i] == 'l')
		c++;
		else if(s[i] == 'T'||s[i] == 't')
		d++;
	}
	while(a||b||c||d)
	{
		if(a) {cout<<'G';a--;}
		if(b) {cout<<'P';b--;}
		if(c) {cout<<'L';c--;}
		if(d) {cout<<'T';d--;}
	}
	return 0;
}
