#include<iostream>
using namespace std;
int num[10];
int find(int a,int b,int re,int num[10])
{
	if(a > b) return 0;
	int l = (a + b)/2;
	if(re > num[l]) find(l + 1,b,re,num);
	else if(re < num[l]) find(a,l-1,re,num);
	else return l;
}
int main()
{
	int re;
	cin>>re;
	for(int i = 0;i < 10;i++)
	cin>>num[i];
	int ans = find(0,10,re,num);
	cout<<ans;
}
