#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ct = 0;
	for(int i = 1;i < n;i++)
	{
		for(int j = 2*i;j < n;j+=i)
		ct++;
		cout<<ct;
	}
	return 0;
}
