#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
struct person{
	int num;
	string s;
}P[maxn];
int main()
{
	int n;
	cin>>n;
	int sum = 0;
	getchar();
	for(int i = 0;i < n;i++)
	{
		cin>>P[i].s>>P[i].num;
		sum += P[i].num;
	}
	int avg = sum/n/2;
	int cha[maxn];
	for(int i = 0;i < n;i++)
		cha[i] = abs(avg - P[i].num);
	sort(cha,cha+n);
	for(int i = 0;i <  n;i++)
	{
		if(abs(avg - P[i].num) == cha[0])
		{
			cout<<avg<<" "<<P[i].s<<endl;
			break;	
		}	
	}	   
	return 0;
}
