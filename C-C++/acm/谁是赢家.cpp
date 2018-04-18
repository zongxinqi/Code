#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int ca = 0,cb = 0;
	int c[3];
	for(int i = 0;i < 3;i++)
	{
		cin>>c[i];
		if(c[i] == 0) ca++;
		else cb++;
	}
	char ans;
	if(a < b)
	{
		if(ca == 3) ans = 'a';
		else ans = 'b';
	}
	else
	{
		if(cb == 3) ans = 'b';
		else ans = 'a';
	}
	if(ans == 'a')
	cout<<"The winner is a: "<<a<<" + "<<ca<<endl;
	else
	cout<<"The winner is b: "<<b<<" + "<<cb<<endl;
	return 0;
}
