#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int h,w;
		cin>>h>>w;
		int st = (h - 100)*1.8;
		if(abs(w - st) < st*0.1) cout<<"You are wan mei!";
		if(abs(w - st) >= st*0.1&&w < st) cout<<"You are tai shou le!";
		if(abs(w - st) >= st*0.1&&w > st)cout << "You are tai pang le!";
		if(n) cout<<endl;
	}
	return 0;	
} 
