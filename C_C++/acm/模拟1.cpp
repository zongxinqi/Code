#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1010;
int main()
{
	int n;
	cin>>n;
	char c[maxn];
	for(int i = 0;i < maxn;i++)
	c[i] = " ";
	getchar();
	gets(c);
	int h = (strlen(c) - 1)/n+1;
	for(int i = 0;i < n;i++)
	{
		for(int j = h - 1;j >= 0;j--)
		cout<<c[i + j*n];
		cout<<endl;
	}
	return 0;
}
