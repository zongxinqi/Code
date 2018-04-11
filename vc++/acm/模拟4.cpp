#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,i,lena,lenb,max,x,y,c[21] = {0},sum[21] = {0};
	string s,a,b;
	cin>>s>>a>>b;
	lena = a.length();
	lenb = b.length();
	for(i = 0;i < lena/2;i++)
	{
	a[i]+=a[lena-1-i];
	a[lena-1-i]=a[i]-a[lena-1-i];
	a[i]-=a[lena-1-i];
	}
	for(i = 0;i < lenb/2;i++)
	{
	b[i]+=b[lenb-1-i];
	b[lenb-1-i]=b[i]-b[lenb-1-i];
	b[i]-=b[lenb-1-i];
	}
	for(i = 0;i < s.length();i++)
	{
	if(i < lena) x = a[i] - '0';else x = 0;
	if(i < lenb) y = b[i] - '0';else y = 0;
	if(i == 0) c[i] = x+y/s[i];
	else c[i] = (x + y + c[i-1])/s[i]; 
	sum[i] = c[i]%s[i];
	}
	if(sum[s.length()] > 0) printf("%d",sum[max]);
	for(i = s.length()-1;i >= 0;i--)
		printf("%d",sum[i]);
		printf("\n");
	return 0;
}
