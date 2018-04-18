#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int h,m;
	char c;
	cin>>h>>c>>m;
	if(m == 0)
	{
		if(h >= 0&&h <= 12) 
		{
			cout<<"Only "<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<".  Too early to Dang.";
		}
		else 
		{
			for(int i = 0;i < h-12;i++)
			cout<<"Dang";
		}
	}
	else
	{
		if(h >= 0&&h <= 11) cout<<"Only "<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<".  Too early to Dang.";
		else
		{
			for(int i = 0;i < h - 11;i++)
			cout<<"Dang";
		}
	}
	return 0;
}
