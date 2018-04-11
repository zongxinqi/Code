#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	int ct = 0;
	while(1)
	{
		cin>>s;
		ct++;
		if(s == "End") break;
		else 
		{   
			if(ct % (n+1) != 0)
			{
				if(s == "ChuiZi") cout<<"Bu"<<endl;
				else if(s == "JianDao") cout<<"ChuiZi"<<endl;
				else if(s == "Bu") cout<<"JianDao"<<endl;
			}
			else
			cout<<s<<endl;	
		}
	}
	return 0;
}
