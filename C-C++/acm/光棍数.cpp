#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char str[1003];
	int len = 0;
	int p = 0;
	int now = 1;
	while(1)
	{
		if(p || now/n)
		{
			str[p++] = '0' + now/n;
		}
		len++;
		now %= n;
		if(now == 0)
		{
			str[p] = 0;
			cout<<str<<" "<<len;
			break;
		}
		now = now*10 + 1;
	}
	return 0;
}
